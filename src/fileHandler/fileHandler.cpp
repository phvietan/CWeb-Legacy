#include "fileHandler.hpp"

bool FileHandler::is_LFI_attack(const std::string path) {
  // Check whether path contains: ../ or /.. or %
  std::regex e("(\\.\\./)|(/\\.\\.)|\%", std::regex_constants::ECMAScript);
  return (std::regex_search(path, e)) ? true : false;
}

std::string FileHandler::get_file_content(const std::string path) {
  std::ifstream ifs(path);
  std::string content;
  content.assign( std::istreambuf_iterator<char>(ifs), std::istreambuf_iterator<char>() );
  return content;
}

bool FileHandler::file_exists(const std::string path) {
  return boost::filesystem::exists(path);
}

crow::response FileHandler::get_file_response(const std::string path) {
  bool should404 = this->is_LFI_attack(path) || this->file_exists(path) == false;
  return should404 ?
    crow::response(404) :
    crow::response(this->get_file_content(path));
}
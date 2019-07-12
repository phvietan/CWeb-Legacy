#include "fileServer.hpp"

bool FileServer::is_LFI_attack(std::string path) {
  // Check whether path contains: ../ or /.. or %
  std::regex e("(\\.\\./)|(/\\.\\.)|\%", std::regex_constants::ECMAScript);
  return (std::regex_search(path,e)) ? true : false;
}

std::string FileServer::get_file_content(const std::string path) {
  std::ifstream ifs(path);
  std::string content;
  content.assign( std::istreambuf_iterator<char>(ifs), std::istreambuf_iterator<char>() );
  return content;
}

bool FileServer::file_exists(const std::string path) {
  return boost::filesystem::exists(path);
}

crow::response FileServer::get_file_response(const std::string path) {
  bool should404 = FileServer::is_LFI_attack(path) || FileServer::file_exists(path) == false;
  return should404 ?
    crow::response(404) :
    crow::response(FileServer::get_file_content(path));
}
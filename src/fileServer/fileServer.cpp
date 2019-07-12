#include "fileServer.hpp"

std::string FileServer::get_file_content(const std::string filePath) {
  std::ifstream ifs(filePath);
  std::string content;
  content.assign( std::istreambuf_iterator<char>(ifs), std::istreambuf_iterator<char>() );
  return content;
}

bool FileServer::file_exists(const std::string path) {
  return boost::filesystem::exists(path);
}

crow::response FileServer::get_file_response(const std::string path) {
  if (FileServer::file_exists(path)) {
    crow::response r(FileServer::get_file_content(path));
    return r;
  }
  else return crow::response(404);
}
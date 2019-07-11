#include "util.hpp"

bool Util::path_exists(std::string path) {
  return boost::filesystem::exists(path);
}

std::string Util::connect_vector_paths(std::vector <std::string> paths) {
  std::string result = paths[0];
  for (int i = 1; i < (int)paths.size(); ++i) {
    std::string cur = paths[i];
    if (result[result.length() - 1] != '/') result.push_back('/');
    while (cur.length() > 0 && cur[0] == '/')
      cur = cur.substr(1, cur.length() - 1);
    result += cur;
  }
  return result;
}

std::string Util::get_file_content(std::string filePath) {
  std::ifstream ifs(filePath);
  std::string content;
  content.assign( std::istreambuf_iterator<char>(ifs), std::istreambuf_iterator<char>() );
  return content;
}
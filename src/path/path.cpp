#include "path.hpp"

std::string Path::connect_two_paths(const std::string a, const std::string b) {
  const std::vector <std::string> paths = { a, b };
  return Path::connect_vector_paths(paths);
}

std::string Path::connect_vector_paths(const std::vector <std::string> & paths) {
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
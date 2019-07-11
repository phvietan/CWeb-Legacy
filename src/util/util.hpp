#pragma once

#ifndef UTIL_HPP
#define UTIL_HPP 1

#include <vector>
#include <fstream>
#include <boost/filesystem.hpp>

class Util {
private:

public:
  static bool path_exists(std::string path);
  static std::string get_file_content(std::string filePath);
  static std::string connect_vector_paths(std::vector <std::string> paths);
};

#endif
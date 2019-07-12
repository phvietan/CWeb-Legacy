#pragma once

#ifndef PATH_HPP
#define PATH_HPP 1

#include <vector>
#include <fstream>

class Path {
private:

public:
  static std::string connect_two_paths(const std::string a, const std::string b);
  static std::string connect_vector_paths(const std::vector <std::string> & paths);
};

#endif
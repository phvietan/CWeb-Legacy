#pragma once

#ifndef PATH_HANDLER_HPP
#define PATH_HANDLER_HPP 1

#include <vector>
#include <fstream>

class PathHandler {
private:

public:
  std::string connect_two_paths(const std::string a, const std::string b);
  std::string connect_vector_paths(const std::vector <std::string> & paths);
};

#endif
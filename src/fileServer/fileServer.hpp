#pragma once

#ifndef FILE_SERVER_HPP
#define FILE_SERVER_HPP 1

#include <regex>
#include <string>
#include <boost/filesystem.hpp>

#include "../crow.h"
#include "../path/path.hpp"

class FileServer {
private:
  static std::string get_file_content(const std::string filePath);

public:
  static bool file_exists(const std::string path);
  static crow::response get_file_response(const std::string path);
};

#endif
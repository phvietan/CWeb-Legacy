#pragma once

#ifndef FILE_HANDLER_HPP
#define FILE_HANDLER_HPP 1

#include <regex>
#include <string>
#include <boost/filesystem.hpp>

#include "../crow.h"

class FileHandler {
private:
  bool is_LFI_attack(const std::string path);
  std::string get_file_content(const std::string path);

public:
  bool file_exists(const std::string path);
  crow::response get_file_response(const std::string path);
};

#endif
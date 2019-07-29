#pragma once

#ifndef FILE_HANDLER_HPP
#define FILE_HANDLER_HPP 1

#include <regex>
#include <string>
#include <stdexcept>
#include <boost/filesystem.hpp>
#include "fileHandlerConstants.hpp"

#include "../crow.h"

class FileHandler {
private:
  bool is_LFI_attack(const std::string & path);
  std::string get_file_content(const std::string & path);

  struct ExtensionHandler {
    std::string get_extension(const std::string & path);
    std::string get_content_type(const std::string & path);
  } extHandler;

public:
  FileHandler();

  bool file_exists(const std::string & path);
  crow::response get_file_response(const std::string & path);
};

#endif
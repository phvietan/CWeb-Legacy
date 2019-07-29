#ifndef FILE_HANDLER_CONSTANTS_HPP
#define FILE_HANDLER_CONSTANTS_HPP 1

#include <string>

const static int WHITELIST_SIZE = 8;

const static std::string WHITELIST_EXT[WHITELIST_SIZE] = {
  "ico",
  "png",
  "jpg",
  "jpeg",
  "pdf",
  "html",
  "css",
  "txt"
};

const static std::string WHITELIST_CONTENT_TYPE[WHITELIST_SIZE] = {
  "image/x-icon",
  "image/png",
  "image/jpeg",
  "image/jpeg",
  "application/pdf",
  "text/html",
  "text/css",
  "text/plain"
};

const static std::string DEFAULT_CONTENT_TYPE = "text/plain";
const static std::string ERROR_BLACK_LIST_EXT = "FileHandler Exception: found blacklist extension.";
const static std::string ERROR_DOES_NOT_HAVE_EXT = "FileHandler Exception: does not have extension.";

#endif
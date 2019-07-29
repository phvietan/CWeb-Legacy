#include "fileHandler.hpp"

std::string FileHandler::ExtensionHandler::get_extension(const std::string & path) {
  const int occur = path.find_last_of('.');

  const bool found = (occur != std::string::npos);
  if (not found) throw std::invalid_argument(ERROR_DOES_NOT_HAVE_EXT);
   
  return path.substr(occur + 1);
}

std::string FileHandler::ExtensionHandler::get_content_type(const std::string & path) {
  try {
    const std::string ext = this->get_extension(path);
    const int & n = WHITELIST_SIZE;
    for (int i = 0; i < n; ++i) {
      if (ext == WHITELIST_EXT[i])
        return WHITELIST_CONTENT_TYPE[i];
    }
  } catch (std::exception & e) {}
  return DEFAULT_CONTENT_TYPE;
}

bool FileHandler::is_LFI_attack(const std::string & path) {
  // Check whether path contains: ../ or /.. or %
  std::regex e("(\\.\\./)|(/\\.\\.)|\%", std::regex_constants::ECMAScript);
  return (std::regex_search(path, e)) ? true : false;
}

std::string FileHandler::get_file_content(const std::string & path) {
  std::ifstream ifs(path);
  std::string content;
  content.assign( std::istreambuf_iterator<char>(ifs), std::istreambuf_iterator<char>() );
  return content;
}

FileHandler::FileHandler() {
  this->extHandler = ExtensionHandler();
}

bool FileHandler::file_exists(const std::string & path) {
  return boost::filesystem::exists(path);
}

crow::response FileHandler::get_file_response(const std::string & path) {
  if (this->is_LFI_attack(path) || this->file_exists(path) == false)
    return crow::response(404);

  crow::response res;
	res.code = 200;
	res.add_header("Content-Type", this->extHandler.get_content_type(path));
	res.write(this->get_file_content(path));
	return res;
}
#include "specialServer.hpp"

SpecialServer::SpecialServer() {
  puts("Initializing SpecialServer object");
  this->app = NULL;
}
  
SpecialServer::SpecialServer(crow::SimpleApp & app) {
  puts("Creating SpecialServer Object");
  this->app = &app;
}

void SpecialServer::initSpecials() {
  crow::SimpleApp & app = *(this->app);
  CROW_ROUTE(app, "/robots.txt")([] {
    auto page = crow::mustache::load("robots.txt");
    return page.render();
  });

  CROW_ROUTE(app, "/favicon.ico")([this] {
    const std::string filePath = pathHandler.connect_two_paths(SERVER_STATIC_IMG_BASE, "favicon.ico");
    return fileHandler.get_file_response(filePath);
  });
}
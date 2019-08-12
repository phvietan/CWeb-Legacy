#include "pageServer.hpp"

PageServer::PageServer() {
  puts("Initializing PageServer object");
  this->app = NULL;
}
  
PageServer::PageServer(crow::SimpleApp & app) {
  puts("Creating PageServer Object");
  this->app = &app;
}

void PageServer::initPages() {
  puts("Creating PageServer Endpoint");
  crow::SimpleApp & app = *(this->app);
  CROW_ROUTE(app, "/")([]() {
    // crow::mustache::context x;
    // return page.render();
    auto page = crow::mustache::load("index.html");
    return page.render();
  });

  CROW_ROUTE(app, "/home")([](const crow::request & req) {
    // const std::string s = req.get_header_value("");
    auto page = crow::mustache::load("home.html");
    return page.render();
  });
}
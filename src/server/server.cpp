#include "server.hpp"

void Server::initPages() {
  CROW_ROUTE(this->app, "/")([]() {
    // crow::mustache::context x;
    // return page.render();
    auto page = crow::mustache::load("index.html");
    return page.render();
  });

  CROW_ROUTE(this->app, "/signup")([](const crow::request & req) {
    // const std::string s = req.get_header_value("");
    auto page = crow::mustache::load("signup.html");
    return page.render();
  });

  CROW_ROUTE(this->app, "/login")([]() {
    auto page = crow::mustache::load("login.html");
    return page.render();
  });
}

void Server::initStatics() {
  CROW_ROUTE(this->app, "/static/css/<string>")
  ([this](std::string path) {
    const std::string filePath = this->pathHandler.connect_two_paths(SERVER_STATIC_CSS_BASE, path);
    return this->fileHandler.get_file_response(filePath);
  });

  CROW_ROUTE(this->app, "/static/img/<string>")
  ([this](std::string path){
    const std::string filePath = this->pathHandler.connect_two_paths(SERVER_STATIC_IMG_BASE, path);
    return this->fileHandler.get_file_response(filePath);
  });

  CROW_ROUTE(this->app, "/static/file/<string>")
  ([this](std::string path){
    const std::string filePath = this->pathHandler.connect_two_paths(SERVER_STATIC_FILE_BASE, path);
    return this->fileHandler.get_file_response(filePath);
  });

  CROW_ROUTE(this->app, "/static/js/<string>")
  ([this](std::string path){
    const std::string filePath = this->pathHandler.connect_two_paths(SERVER_STATIC_JS_BASE, path);
    return this->fileHandler.get_file_response(filePath);
  });
}

void Server::initSpecials() {
  CROW_ROUTE(this->app, "/robots.txt")([] {
    auto page = crow::mustache::load("robots.txt");
    return page.render();
  });

  CROW_ROUTE(this->app, "/favicon.ico")([this] {
    const std::string filePath = this->pathHandler.connect_two_paths(SERVER_STATIC_IMG_BASE, "favicon.ico");
    return this->fileHandler.get_file_response(filePath);
  });
}

Server::Server() {
  puts("Initializing...");

  this->pathHandler = PathHandler();
  this->fileHandler = FileHandler();

  this->initPages();
  this->initStatics();

  this->initSpecials();
}

void Server::run() {
  puts("Running server...");
  this->app.port(PORT_NUMBER)
    .multithreaded()
    .run();
}
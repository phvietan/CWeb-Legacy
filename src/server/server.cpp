#include "server.hpp"

Server::Server() {
  puts("Initializing...");

  CROW_ROUTE(this->app, "/")([]() {
    crow::mustache::context x;
    x["server-title"] = SERVER_TITLE;
    auto page = crow::mustache::load("index.html");
    return page.render(x);
  });

  CROW_ROUTE(app, "/static/css/<string>")
  ([](std::string path){
    const std::string filePath = Path::connect_two_paths(SERVER_STATIC_CSS_BASE, path);
    return FileServer::get_file_response(filePath);
  });

  CROW_ROUTE(app, "/static/img/<string>")
  ([](std::string path){
    const std::string filePath = Path::connect_two_paths(SERVER_STATIC_IMG_BASE, path);
    return FileServer::get_file_response(filePath);
  });

  CROW_ROUTE(this->app, "/robots.txt")([] {
    auto page = crow::mustache::load("robots.txt");
    return page.render();
  });
}

void Server::run() {
  puts("Running server...");
  this->app.port(PORT_NUMBER)
    .multithreaded()
    .run();
}
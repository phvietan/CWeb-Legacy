#include "staticServer.hpp"

StaticServer::StaticServer() {
  puts("Initializing StaticServer object");
  this->app = NULL;
}
  
StaticServer::StaticServer(crow::SimpleApp & app) {
  puts("Creating StaticServer Object");
  this->app = &app;
}

void StaticServer::initStatics() {
  puts("Creating StaticServer Endpoint");
  crow::SimpleApp & app = *(this->app);
   CROW_ROUTE(app, "/static/css/<string>")
  ([this](std::string path) {
    const std::string filePath = this->pathHandler.connect_two_paths(SERVER_STATIC_CSS_BASE, path);
    return this->fileHandler.get_file_response(filePath);
  });

  CROW_ROUTE(app, "/static/img/<string>")
  ([this](std::string path){
    const std::string filePath = this->pathHandler.connect_two_paths(SERVER_STATIC_IMG_BASE, path);
    return this->fileHandler.get_file_response(filePath);
  });

  CROW_ROUTE(app, "/static/file/<string>")
  ([this](std::string path){
    const std::string filePath = this->pathHandler.connect_two_paths(SERVER_STATIC_FILE_BASE, path);
    return this->fileHandler.get_file_response(filePath);
  });

  CROW_ROUTE(app, "/static/js/<string>")
  ([this](std::string path){
    const std::string filePath = this->pathHandler.connect_two_paths(SERVER_STATIC_JS_BASE, path);
    return this->fileHandler.get_file_response(filePath);
  });
}
#include "apiServer.hpp"

ApiServer::ApiServer() {
  puts("Initializing ApiServer object");
  this->app = NULL;
}
  
ApiServer::ApiServer(crow::SimpleApp & app) {
  puts("Creating ApiServer Object");
  this->app = &app;
}

void ApiServer::initApi() {
  puts("Creating ApiServer Endpoint");
  crow::SimpleApp & app = *(this->app);

  CROW_ROUTE(app, "/api/test/crypto")
    .methods("POST"_method)
    ([](const crow::request & req) {
      puts("Receive post request");
      const auto jsonRequest = crow::json::load(req.body);
      if (!jsonRequest) return crow::response(400);

      const std::string prfL = jsonRequest["prfL"].s();
      const std::string prfR = jsonRequest["prfR"].s();
      
      return crow::response(404);
    });
}
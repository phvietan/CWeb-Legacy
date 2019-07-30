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

  CROW_ROUTE(app, "/api/user/signup")
    .methods("POST"_method)
    ([](const crow::request & req) {
      puts("Receive post request");
      const auto jsonRequest = crow::json::load(req.body);
      if (!jsonRequest) return crow::response(400);

      const std::string username = jsonRequest["username"].s();
      const std::string email = jsonRequest["email"].s();
      const std::string password = jsonRequest["password"].s();
      if (username.length() > 40 || email.length() > 40 || password.length() > 40) return crow::response(400);

      puts("Found username");
      std::cout << username << std::endl;

      puts("Found email");
      std::cout << email << std::endl;

      puts("Found password");
      std::cout << password << std::endl;
      
      return crow::response(404);
    });
}
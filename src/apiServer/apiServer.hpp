#ifndef API_SERVER_HPP
#define API_SERVER_HPP 1

#include "../crow.h"
#include "../constants.hpp"
#include <iostream>

class ApiServer {
private:
  crow::SimpleApp * app;

public:
  ApiServer();
  ApiServer(crow::SimpleApp & app);
  
  void initApi();
};

#endif
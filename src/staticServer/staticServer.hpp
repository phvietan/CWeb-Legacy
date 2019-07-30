#ifndef STATIC_SERVER_HPP
#define STATIC_SERVER_HPP 1

#include "../crow.h"

#include "../constants.hpp"
#include "../pathHandler/pathHandler.hpp"
#include "../fileHandler/fileHandler.hpp"

class StaticServer {
private:
  crow::SimpleApp * app;
  PathHandler pathHandler;
  FileHandler fileHandler;

public:
  StaticServer();
  StaticServer(crow::SimpleApp & app);
  
  void initStatics();
};

#endif
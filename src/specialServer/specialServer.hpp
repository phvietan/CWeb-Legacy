#ifndef SPECIAL_SERVER_HPP
#define SPECIAL_SERVER_HPP 1

#include "../crow.h"

#include "../constants.hpp"
#include "../pathHandler/pathHandler.hpp"
#include "../fileHandler/fileHandler.hpp"

class SpecialServer {
private:
  crow::SimpleApp * app;
  PathHandler pathHandler;
  FileHandler fileHandler;

public:
  SpecialServer();
  SpecialServer(crow::SimpleApp & app);
  
  void initSpecials();
};

#endif
#pragma once

#ifndef SERVER_HPP
#define SERVER_HPP 1

#include <vector>
#include <iostream>
#include "../crow.h"
#include "../constants.hpp"
#include "../pathHandler/pathHandler.hpp"
#include "../fileHandler/fileHandler.hpp"

class Server {
private:
  crow::SimpleApp app;
  PathHandler pathHandler;
  FileHandler fileHandler;

  void initPages();
  void initStatics();

public:
  Server();
  void run();
};

#endif
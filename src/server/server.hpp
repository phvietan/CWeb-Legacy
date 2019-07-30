#pragma once

#ifndef SERVER_HPP
#define SERVER_HPP 1

#include <vector>
#include <iostream>

#include "../crow.h"
#include "serverConstants.hpp"

#include "../pageServer/pageServer.hpp"
#include "../staticServer/staticServer.hpp"
#include "../specialServer/specialServer.hpp"

class Server {
private:
  crow::SimpleApp app;
  
  PageServer pageServer;
  StaticServer staticServer;
  SpecialServer specialServer;

public:
  Server();
  void run();
};

#endif
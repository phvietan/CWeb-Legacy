#pragma once

#ifndef SERVER_HPP
#define SERVER_HPP 1

#include "../crow.h"
#include "serverConstants.hpp"

#include "../apiServer/apiServer.hpp"
#include "../pageServer/pageServer.hpp"
#include "../staticServer/staticServer.hpp"
#include "../specialServer/specialServer.hpp"

class Server {
private:
  crow::SimpleApp app;
  
  ApiServer apiServer;
  PageServer pageServer;
  StaticServer staticServer;
  SpecialServer specialServer;

public:
  Server();
  void run();
};

#endif
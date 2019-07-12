#pragma once

#ifndef SERVER_HPP
#define SERVER_HPP 1

#include <vector>
#include <iostream>
#include "../crow.h"
#include "../path/path.hpp"
#include "../constants.hpp"
#include "../fileServer/fileServer.hpp"

class Server {
private:
  crow::SimpleApp app;

public:
  Server();
  void run();
};

#endif
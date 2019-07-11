#pragma once

#ifndef SERVER_HPP
#define SERVER_HPP 1

#include <vector>
#include <iostream>
#include "../crow.h"
#include "../util/util.hpp"
#include "../constants.hpp"

class Server {
private:
    crow::SimpleApp app;

public:
    Server();
    void run();
};

#endif
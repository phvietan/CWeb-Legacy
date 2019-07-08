#pragma once

#ifndef SERVER_HPP
#define SERVER_HPP 1

#include "../crow.h"

class Server {
private:
    crow::SimpleApp app;

public:
    Server();
    void run();
};

#endif
#include "../crow.h"
#include <iostream>
#include "server.hpp"
#include "../constants.hpp"

Server::Server() {
    puts("Initializing...");

    CROW_ROUTE(this->app, "/")([]() {
        crow::mustache::context x;
        x["server-title"] = SERVER_TITLE;
    
        auto page = crow::mustache::load("index.html");
        return page.render(x);
    });

    CROW_ROUTE(this->app, "/robots.txt")([] {
        auto page = crow::mustache::load("robots.txt");
        return page.render();
    });
}

void Server::run() {
    puts("Running server...");
    this->app.port(PORT_NUMBER)
        .multithreaded()
        .run();
}
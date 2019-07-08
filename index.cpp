#include "src/crow.h"
#include "src/constants.hpp"

int main()
{
    crow::SimpleApp app;

    CROW_ROUTE(app, "/")([]() {
        crow::mustache::context x;
        x["server-title"] = SERVER_TITLE;
	
        auto page = crow::mustache::load("index.html");
        // return "hello";
        return page.render(x);
    });

    app.port(PORT_NUMBER).multithreaded().run();
}
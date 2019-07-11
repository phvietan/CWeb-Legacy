#include "server.hpp"

Server::Server() {
    puts("Initializing...");

    CROW_ROUTE(this->app, "/")([]() {
        crow::mustache::context x;
        x["server-title"] = SERVER_TITLE;
        auto page = crow::mustache::load("index.html");
        return page.render(x);
    });

    CROW_ROUTE(app, "/static/css/<string>")
    ([](std::string path){
        std::string staticCssBase(SERVER_STATIC_CSS_BASE);
        std::vector <std::string> paths = {staticCssBase, path};
        std::string filePath = Util::connect_vector_paths(paths);

        if (Util::path_exists(filePath)) {
            crow::response r(Util::get_file_content(filePath));
            r.add_header("Content-Type", "text/css");
            return r;
        }
        else return crow::response(404);
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
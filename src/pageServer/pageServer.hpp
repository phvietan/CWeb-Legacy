#ifndef PAGE_SERVER_HPP
#define PAGE_SERVER_HPP 1

#include "../crow.h"

class PageServer {
private:
  crow::SimpleApp * app;

public:
  PageServer();
  PageServer(crow::SimpleApp & app);
  
  void initPages();
};

#endif
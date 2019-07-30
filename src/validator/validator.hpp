#ifndef VALIDATOR_HPP
#define VALIDATOR_HPP 1

#include "../crow.h"

class Validator {
private:

public:
  Validator() {}

  bool isValidUsername(const std::string & username);
  bool isValidEmail(const std::string & email);
  bool isValidPassword(const std::string & password);

  int validateSignupRequest(const crow::request & req);
};

#endif
#include "validator.hpp"

function validateUsername(documentUsername) {
  const username = documentUsername.value;
  if (username.length > 40) {
    alert("Username is too long, exceed 40 characters");
    return false;
  }

  const nameRegex = /^[a-zA-Z0-9]+$/;
  const isValid = nameRegex.test(username);
  if (!isValid) {
    alert("Invalid username. Only characters A-Z, a-z and 0-9 are  acceptable.");
    documentUsername.focus();
  }
  return isValid;
}

bool Validator::isValidUsername(const std::string username) {

}

int Validator::validateSignupRequest(const crow::request & req) {
  const auto jsonRequest = crow::json::load(req.body);
  if (!jsonRequest) return 400;

  const std::string username = jsonRequest["username"].s();
  const std::string email = jsonRequest["email"].s();
  const std::string password = jsonRequest["password"].s();
  if (username.length() > 40 || email.length() > 40 || password.length() > 40) return 400;
  if (username.length() == 0 || email.length() == 0 || )

  
  return crow::response(404);
}
#include "CustomAuthorizationObject.hpp"

#include "../util/JwtUtil.hpp"

class CustomBearerAuthorizationHandler : public oatpp::web::server::handler::BearerAuthorizationHandler {
public:
  CustomBearerAuthorizationHandler() : BearerAuthorizationHandler("my-realm") {}

  std::shared_ptr<AuthorizationObject> authorize(const oatpp::String& token) override {
    JwtUtil jwtUtil;
    if (jwtUtil.verifyToken(token)) {
      auto id = jwtUtil.extractIdFromToken(token);
      auto role = jwtUtil.extractRoleFromToken(token);
      return std::make_shared<CustomAuthorizationObject>(id, role);
    }
    return nullptr;
  }
};
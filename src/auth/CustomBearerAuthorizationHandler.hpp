#include "CustomAuthorizationObject.hpp"

class CustomBearerAuthorizationHandler : public oatpp::web::server::handler::BearerAuthorizationHandler {
public:
    CustomBearerAuthorizationHandler() : BearerAuthorizationHandler("my-realm") {}

    std::shared_ptr<AuthorizationObject> authorize(const oatpp::String &token) override {
        if (JwtUtil::verifyToken(token)) {
            auto id = JwtUtil::extractIdFromToken(token);
            auto role = JwtUtil::extractRoleFromToken(token);
            return std::make_shared<CustomAuthorizationObject>(id, role);
        }
        return nullptr;
    }
};
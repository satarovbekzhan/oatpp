#include <oatpp/core/Types.hpp>
#include <oatpp/web/server/handler/AuthorizationHandler.hpp>

class CustomAuthorizationObject : public oatpp::web::server::handler::AuthorizationObject {
public:
  CustomAuthorizationObject(const oatpp::String& pUserId, const oatpp::String& pUserRole) : userId(pUserId) {
    userRole = pUserRole;
  }

  oatpp::String userId;
  oatpp::String userRole;
};
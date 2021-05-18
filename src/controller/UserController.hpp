#ifndef UserController_hpp
#define UserController_hpp

#include "oatpp/web/server/api/ApiController.hpp"
#include "oatpp/parser/json/mapping/ObjectMapper.hpp"
#include "oatpp/core/macro/codegen.hpp"

#include "../service/UserService.hpp"

#include OATPP_CODEGEN_BEGIN(ApiController)

class UserController : public oatpp::web::server::api::ApiController {
public:
  UserController(OATPP_COMPONENT(std::shared_ptr<ObjectMapper>, objectMapper))
  : oatpp::web::server::api::ApiController(objectMapper)
    {}
private:
  UserService userService;
public:
  static std::shared_ptr<UserController> createShared(
    OATPP_COMPONENT(std::shared_ptr<ObjectMapper>, objectMapper)
  ) {
    return std::make_shared<UserController>(objectMapper);
  }

  ENDPOINT_INFO(createUser) {
    info->summary = "Create new User";
    info->addConsumes<Object<UserDto>>("application/json");
    info->addResponse<Object<UserDto>>(Status::CODE_200, "application/json");
  }
  ENDPOINT("POST", "users", createUser,
  BODY_DTO(Object<UserDto>, userDto)) {
    return createDtoResponse(Status::CODE_200, userService.createUser(userDto));
  }

  ENDPOINT_INFO(getUserById) {
    info->summary = "Get one User by userId";
    info->addResponse<Object<UserDto>>(Status::CODE_200, "application/json");
    info->pathParams["userId"].description = "User Identifier";
  }
  ENDPOINT("GET", "users/{userId}", getUserById,
  PATH(Int32, userId)) {
    return createDtoResponse(Status::CODE_200, userService.getUserById(userId));
  }

  ENDPOINT_INFO(getUsers) {
    info->summary = "get all stored users";
  }
  ENDPOINT("GET", "users/offset/{offset}/limit/{limit}", getUsers,
  PATH(UInt32, offset),
  PATH(UInt32, limit)) {
    return createDtoResponse(Status::CODE_200, userService.getAllUsers(offset, limit));
  }

};

#include OATPP_CODEGEN_BEGIN(ApiController)

#endif//UserController_hpp

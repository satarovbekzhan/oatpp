#ifndef UserController_hpp
#define UserController_hpp

#include "oatpp/web/server/api/ApiController.hpp"
#include "oatpp/parser/json/mapping/ObjectMapper.hpp"
#include "oatpp/core/macro/codegen.hpp"

#include "../service/UserService.hpp"

#include OATPP_CODEGEN_BEGIN(ApiController)

class UserController : public oatpp::web::server::api::ApiController {
public:

    explicit UserController(OATPP_COMPONENT(std::shared_ptr<ObjectMapper>, objectMapper))
            : oatpp::web::server::api::ApiController(objectMapper) {}

private:

    UserService userService;

public:

    static std::shared_ptr<UserController> createShared(OATPP_COMPONENT(std::shared_ptr<ObjectMapper>, objectMapper)) {
        return std::make_shared<UserController>(objectMapper);
    }

    // CREATE
    ENDPOINT_INFO(createUser) {
        info->summary = "Create new user";
        info->addConsumes < Object < UserDto >> ("application/json");
        info->addResponse < Object < UserDto >> (Status::CODE_200, "application/json");
    }

    ENDPOINT("POST", "users", createUser, BODY_DTO(Object < UserDto > , userDto)) {
        return createDtoResponse(Status::CODE_200, userService.createUser(userDto));
    }

    // READ BY ID
    ENDPOINT_INFO(getUserById) {
        info->summary = "Get one ser by id";
        info->addResponse < Object < UserDto >> (Status::CODE_200, "application/json");
        info->pathParams["userId"].description = "User Identifier";
    }

    ENDPOINT("GET", "users/{userId}", getUserById, PATH(Int32, userId)) {
        return createDtoResponse(Status::CODE_200, userService.getUserById(userId));
    }

    // READ ALL
    ENDPOINT_INFO(getUsers) {
        info->summary = "Get all stored users";
    }

    ENDPOINT("GET", "users/offset/{offset}/limit/{limit}", getUsers, PATH(UInt32, offset), PATH(UInt32, limit)) {
        return createDtoResponse(Status::CODE_200, userService.getAllUsers(offset, limit));
    }

    // UPDATE
    ENDPOINT_INFO(putUser) {
        info->summary = "Update user by id";
        info->addConsumes < Object < UserDto >> ("application/json");
        info->addResponse < Object < UserDto >> (Status::CODE_200, "application/json");
    }

    ENDPOINT("PUT", "users/{userId}", putUser, PATH(Int32, userId), BODY_DTO(Object < UserDto > , userDto)) {
        userDto->id = userId;
        return createDtoResponse(Status::CODE_200, userService.updateUser(userDto));
    }

    // DELETE
    ENDPOINT_INFO(deleteUser) {
        info->summary = "Delete user by id";
        info->addResponse < Object < UserDto >> (Status::CODE_200, "application/json");
    }

    ENDPOINT("DELETE", "users/{userId}", deleteUser, PATH(Int32, userId)) {
        return createDtoResponse(Status::CODE_200, userService.deleteUserById(userId));
    }

};

#include OATPP_CODEGEN_BEGIN(ApiController)

#endif//UserController_hpp

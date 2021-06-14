#ifndef LoginController_hpp
#define LoginController_hpp

#include <iostream>
#include "oatpp/web/server/api/ApiController.hpp"
#include "oatpp/parser/json/mapping/ObjectMapper.hpp"
#include "oatpp/core/macro/codegen.hpp"

#include "../service/UserService.hpp"
#include "../dto/LoginDto.hpp"
#include "../dto/TokenDto.hpp"

#include OATPP_CODEGEN_BEGIN(ApiController)

class LoginController : public oatpp::web::server::api::ApiController {
public:

    LoginController(OATPP_COMPONENT(std::shared_ptr<ObjectMapper>, objectMapper))
            : oatpp::web::server::api::ApiController(objectMapper) {}

private:

    UserService userService;

public:

    static std::shared_ptr<LoginController> createShared(OATPP_COMPONENT(std::shared_ptr<ObjectMapper>, objectMapper)) {
        return std::make_shared<LoginController>(objectMapper);
    }

    // Login to system with email and password and get a token
    ENDPOINT("GET", "/login", login, BODY_DTO(Object < LoginDto > , loginDto)) {
        if (loginDto->email && loginDto->password) {
            oatpp::Object<UserDto> userDto = userService.getUserByEmail(loginDto->email);
            if (userDto->password == loginDto->password) {
                JwtUtil jwtUtil;
                auto tokenDto = TokenDto::createShared();
                tokenDto->token = jwtUtil.generateToken(userDto);
                tokenDto->email = userDto->email;
                return createDtoResponse(Status::CODE_200, tokenDto);
            }
            return createResponse(Status::CODE_401, "Invalid credentials");
        }
        return createResponse(Status::CODE_400, "Bad Request");
    }

};

#include OATPP_CODEGEN_BEGIN(ApiController)

#endif//LoginController_hpp

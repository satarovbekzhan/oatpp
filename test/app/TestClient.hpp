#ifndef MyApiTestClient_hpp
#define MyApiTestClient_hpp

#include "oatpp/web/client/ApiClient.hpp"
#include "oatpp/core/macro/codegen.hpp"

#include "../../src/dto/LoginDto.hpp"
#include "../../src/dto/TokenDto.hpp"

#include OATPP_CODEGEN_BEGIN(ApiClient)

class TestClient : public oatpp::web::client::ApiClient {

API_CLIENT_INIT(TestClient)

    API_CALL("POST", "/login", getBearerToken, BODY_DTO(Object<LoginDto>, loginDto))
    API_CALL("GET", "/users/1", getBekzhanUser)

    // TODO - add more client API calls here

};

#include OATPP_CODEGEN_END(ApiClient)

#endif // MyApiTestClient_hpp
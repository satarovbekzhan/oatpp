#ifndef LoginDto_hpp
#define LoginDto_hpp

#include "oatpp/core/Types.hpp"
#include "oatpp/core/macro/codegen.hpp"

#include OATPP_CODEGEN_BEGIN(DTO)

class LoginDto : public oatpp::DTO {

  DTO_INIT(LoginDto, DTO)

  DTO_FIELD(String, email, "email");
  DTO_FIELD(String, password, "password");

};

#include OATPP_CODEGEN_END(DTO)

#endif//LoginDto_hpp
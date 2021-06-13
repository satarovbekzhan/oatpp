#ifndef TokenDto_hpp
#define TokenDto_hpp

#include "oatpp/core/Types.hpp"
#include "oatpp/core/macro/codegen.hpp"

#include OATPP_CODEGEN_BEGIN(DTO)

class TokenDto : public oatpp::DTO {

  DTO_INIT(TokenDto, DTO)

  DTO_FIELD(Any, token, "token");
  DTO_FIELD(String, email, "email");

};

#include OATPP_CODEGEN_END(DTO)

#endif//TokenDto_hpp
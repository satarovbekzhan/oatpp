#ifndef UserDto_hpp
#define UserDto_hpp

#include "oatpp/core/Types.hpp"
#include "oatpp/core/macro/codegen.hpp"

#include OATPP_CODEGEN_BEGIN(DTO)

ENUM(Role, v_int32, VALUE(ADMIN, 0, "ROLE_ADMIN"), VALUE(MODERATOR, 1, "ROLE_MODERATOR"), VALUE(CUSTOMER, 2, "ROLE_CUSTOMER"))

class UserDto : public oatpp::DTO
{

  DTO_INIT(UserDto, DTO)

  DTO_FIELD(Int32, id);
  DTO_FIELD(String, email, "email");
  DTO_FIELD(String, password, "password");
  DTO_FIELD(String, firstname, "firstname");
  DTO_FIELD(String, lastname, "lastname");
  DTO_FIELD(String, salutation, "salutation");
  DTO_FIELD(Enum<Role>::AsString, role, "role");

};

#include OATPP_CODEGEN_END(DTO)

#endif//UserDto_hpp
#ifndef AddressDto_hpp
#define AddressDto_hpp

#include "oatpp/core/Types.hpp"
#include "oatpp/core/macro/codegen.hpp"

#include OATPP_CODEGEN_BEGIN(DTO)

class AddressDto : public oatpp::DTO {

  DTO_INIT(AddressDto, DTO)

  DTO_FIELD(String, name);
  DTO_FIELD(Int32, age);

};

#include OATPP_CODEGEN_END(DTO)

#endif//AddressDto_hpp
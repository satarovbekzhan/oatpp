#ifndef AddressDto_hpp
#define AddressDto_hpp

#include "oatpp/core/Types.hpp"
#include "oatpp/core/macro/codegen.hpp"

#include OATPP_CODEGEN_BEGIN(DTO)

class AddressDto : public oatpp::DTO {

    DTO_INIT(AddressDto, DTO)

    DTO_FIELD(Int32, id);
    DTO_FIELD(String, town, "town");
    DTO_FIELD(String, street, "street");
    DTO_FIELD(String, house, "house");
    DTO_FIELD(String, note, "note");
    DTO_FIELD(Int32, user, "user");

};

#include OATPP_CODEGEN_END(DTO)

#endif//AddressDto_hpp
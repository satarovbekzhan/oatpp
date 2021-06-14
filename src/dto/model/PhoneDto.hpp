#ifndef PhoneDto_hpp
#define PhoneDto_hpp

#include "oatpp/core/Types.hpp"
#include "oatpp/core/macro/codegen.hpp"

#include OATPP_CODEGEN_BEGIN(DTO)

class PhoneDto : public oatpp::DTO {

    DTO_INIT(PhoneDto, DTO)

    DTO_FIELD(Int32, id);
    DTO_FIELD(String, number, "number");
    DTO_FIELD(Int32, user, "user");

};

#include OATPP_CODEGEN_END(DTO)

#endif//PhoneDto_hpp
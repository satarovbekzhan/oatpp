#ifndef CartDto_hpp
#define CartDto_hpp

#include "oatpp/core/Types.hpp"
#include "oatpp/core/macro/codegen.hpp"

#include OATPP_CODEGEN_BEGIN(DTO)

class CartDto : public oatpp::DTO {

    DTO_INIT(CartDto, DTO)

    DTO_FIELD(Int32, id);
    DTO_FIELD(Int32, product, "product");
    DTO_FIELD(Int32, user, "user");
    DTO_FIELD(Int32, amount, "amount");

};

#include OATPP_CODEGEN_END(DTO)

#endif//CartDto_hpp
#ifndef ProductDto_hpp
#define ProductDto_hpp

#include "oatpp/core/Types.hpp"
#include "oatpp/core/macro/codegen.hpp"

#include OATPP_CODEGEN_BEGIN(DTO)

class ProductDto : public oatpp::DTO {

  DTO_INIT(ProductDto, DTO)

  DTO_FIELD(Int32, id);

};

#include OATPP_CODEGEN_END(DTO)

#endif//ProductDto_hpp
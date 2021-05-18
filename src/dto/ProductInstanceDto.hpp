#ifndef ProductInstanceDto_hpp
#define ProductInstanceDto_hpp

#include "oatpp/core/Types.hpp"
#include "oatpp/core/macro/codegen.hpp"

#include OATPP_CODEGEN_BEGIN(DTO)

class ProductInstanceDto : public oatpp::DTO {

  DTO_INIT(ProductInstanceDto, DTO)

  DTO_FIELD(Int32, id);

};

#include OATPP_CODEGEN_END(DTO)

#endif//ProductInstanceDto_hpp
#ifndef PriceDto_hpp
#define PriceDto_hpp

#include "oatpp/core/Types.hpp"
#include "oatpp/core/macro/codegen.hpp"

#include OATPP_CODEGEN_BEGIN(DTO)

class PriceDto : public oatpp::DTO {

  DTO_INIT(PriceDto, DTO)

  DTO_FIELD(Int32, id);
  DTO_FIELD(Int32, product, "product");
  DTO_FIELD(Int32, value, "value");
  DTO_FIELD(Int64, timestamp, "timestamp");

};

#include OATPP_CODEGEN_END(DTO)

#endif//PriceDto_hpp
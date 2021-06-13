#ifndef OrderDto_hpp
#define OrderDto_hpp

#include "oatpp/core/Types.hpp"
#include "oatpp/core/macro/codegen.hpp"

#include OATPP_CODEGEN_BEGIN(DTO)

class OrderDto : public oatpp::DTO {

  DTO_INIT(OrderDto, DTO)

  DTO_FIELD(Int32, id);
  DTO_FIELD(Int32, product, "product");
  DTO_FIELD(Int32, user, "user");
  DTO_FIELD(Int32, amount, "amount");
  DTO_FIELD(Int32, address, "address");
  DTO_FIELD(Int64, timestamp, "timestamp");

};

#include OATPP_CODEGEN_END(DTO)

#endif//OrderDto_hpp
#ifndef OrderItemDto_hpp
#define OrderItemDto_hpp

#include "oatpp/core/Types.hpp"
#include "oatpp/core/macro/codegen.hpp"

#include OATPP_CODEGEN_BEGIN(DTO)

class OrderItemDto : public oatpp::DTO {

  DTO_INIT(OrderItemDto, DTO)

  DTO_FIELD(Int32, id);

};

#include OATPP_CODEGEN_END(DTO)

#endif//OrderItemDto_hpp
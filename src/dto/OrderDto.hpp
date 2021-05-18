#ifndef OrderDto_hpp
#define OrderDto_hpp

#include "oatpp/core/Types.hpp"
#include "oatpp/core/macro/codegen.hpp"

#include OATPP_CODEGEN_BEGIN(DTO)

class OrderDto : public oatpp::DTO {

  DTO_INIT(OrderDto, DTO)

  DTO_FIELD(Int32, id);

};

#include OATPP_CODEGEN_END(DTO)

#endif//OrderDto_hpp
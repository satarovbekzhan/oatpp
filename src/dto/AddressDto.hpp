#include "oatpp/core/Types.hpp"
#include "oatpp/core/macro/codegen.hpp"

#include OATPP_CODEGEN_BEGIN(DTO)

class TableDto : public oatpp::DTO {

  DTO_INIT(TableDto, DTO)

  DTO_FIELD(String, name);
  DTO_FIELD(Int32, age);

};

#include OATPP_CODEGEN_END(DTO)
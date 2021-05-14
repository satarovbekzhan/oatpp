#include "oatpp/core/Types.hpp"
#include "oatpp/core/macro/codegen.hpp"

#include OATPP_CODEGEN_BEGIN(DTO)

class HistoryDto : public oatpp::DTO {

  DTO_INIT(HistoryDto, DTO)

  DTO_FIELD(Int32, id);

};

#include OATPP_CODEGEN_END(DTO)
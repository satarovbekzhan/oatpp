#ifndef SizeDto_hpp
#define SizeDto_hpp

#include "oatpp/core/Types.hpp"
#include "oatpp/core/macro/codegen.hpp"

#include OATPP_CODEGEN_BEGIN(DTO)

class SizeDto : public oatpp::DTO {

  DTO_INIT(SizeDto, DTO)

  DTO_FIELD(Int32, id);

};

#include OATPP_CODEGEN_END(DTO)

#endif//SizeDto_hpp
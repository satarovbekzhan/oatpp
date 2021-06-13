#ifndef IngredientDto_hpp
#define IngredientDto_hpp

#include "oatpp/core/Types.hpp"
#include "oatpp/core/macro/codegen.hpp"

#include OATPP_CODEGEN_BEGIN(DTO)

class IngredientDto : public oatpp::DTO {

  DTO_INIT(IngredientDto, DTO)

  DTO_FIELD(Int32, id);
  DTO_FIELD(String, name, "name");

};

#include OATPP_CODEGEN_END(DTO)

#endif//IngredientDto_hpp
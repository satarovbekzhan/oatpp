#ifndef RefProductIngredientDto_hpp
#define RefProductIngredientDto_hpp

#include "oatpp/core/Types.hpp"
#include "oatpp/core/macro/codegen.hpp"

#include OATPP_CODEGEN_BEGIN(DTO)

class RefProductIngredientDto : public oatpp::DTO {

  DTO_INIT(RefProductIngredientDto, DTO)

  DTO_FIELD(Int32, id);
  DTO_FIELD(Int32, ingredient, "ingredient");
  DTO_FIELD(Int32, product, "product");

};

#include OATPP_CODEGEN_END(DTO)

#endif//RefProductIngredientDto_hpp
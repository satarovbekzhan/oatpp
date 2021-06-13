#ifndef RefProductCategoryDto_hpp
#define RefProductCategoryDto_hpp

#include "oatpp/core/Types.hpp"
#include "oatpp/core/macro/codegen.hpp"

#include OATPP_CODEGEN_BEGIN(DTO)

class RefProductCategoryDto : public oatpp::DTO {

  DTO_INIT(RefProductCategoryDto, DTO)

  DTO_FIELD(Int32, id);
  DTO_FIELD(Int32, category, "category");
  DTO_FIELD(Int32, product, "product");

};

#include OATPP_CODEGEN_END(DTO)

#endif//RefProductCategoryDto_hpp
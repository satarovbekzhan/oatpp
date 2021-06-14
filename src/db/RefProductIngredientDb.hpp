#ifndef RefProductIngredientDb_hpp
#define RefProductIngredientDb_hpp

#include "oatpp/orm/SchemaMigration.hpp"
#include "oatpp/orm/DbClient.hpp"
#include "oatpp/core/macro/codegen.hpp"
#include "../dto/model/RefProductIngredientDto.hpp"

#include OATPP_CODEGEN_BEGIN(DbClient)

class RefProductIngredientDb : public oatpp::orm::DbClient {
public:

    RefProductIngredientDb(const std::shared_ptr<oatpp::orm::Executor> &executor) : oatpp::orm::DbClient(executor) {}

    QUERY(createRefPI,
          "INSERT INTO ref_product_ingredient "
          "(product, ingredient) "
          "VALUES (:ref_pi.product, "
          ":ref_pi.ingredient);",
          PARAM(oatpp::Object<RefProductIngredientDto>, ref_pi))

    QUERY(getAllRefPIs,
          "SELECT * FROM ref_product_ingredient LIMIT :limit OFFSET :offset;",
          PARAM(oatpp::UInt32, offset),
          PARAM(oatpp::UInt32, limit))

    QUERY(getRefPIById,
          "SELECT * FROM ref_product_ingredient WHERE id=:id;",
          PARAM(oatpp::Int32, id))

    QUERY(updateRefPI,
          "UPDATE ref_product_ingredient "
          "SET "
          "product=:ref_pi.product, "
          "ingredient=:ref_pi.ingredient "
          "WHERE id=:ref_pi.id",
          PARAM(oatpp::Object<RefProductIngredientDto>, ref_pi))

    QUERY(deleteRefPIById,
          "DELETE FROM ref_product_ingredient WHERE id=:id",
          PARAM(oatpp::Int32, id))
};

#include OATPP_CODEGEN_END(DbClient)

#endif//RefProductIngredientDb_hpp

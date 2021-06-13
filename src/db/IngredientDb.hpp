#ifndef IngredientDb_hpp
#define IngredientDb_hpp

#include "oatpp/orm/SchemaMigration.hpp"
#include "oatpp/orm/DbClient.hpp"
#include "oatpp/core/macro/codegen.hpp"
#include "../dto/IngredientDto.hpp"

#include OATPP_CODEGEN_BEGIN(DbClient)

class IngredientDb : public oatpp::orm::DbClient {
public:

  IngredientDb(const std::shared_ptr<oatpp::orm::Executor>& executor) : oatpp::orm::DbClient(executor) {
//    oatpp::orm::SchemaMigration migration(executor);
//    migration.addFile(1, "src/sql/ingredient_init.sql");
//    migration.migrate();
  }

  QUERY(createIngredient,
        "INSERT INTO ingredient "
        "(name) "
        "VALUES (:ingredient.name);",
        PARAM(oatpp::Object<IngredientDto>, ingredient))

  QUERY(getAllIngredients,
        "SELECT * FROM ingredient LIMIT :limit OFFSET :offset;",
        PARAM(oatpp::UInt32, offset),
        PARAM(oatpp::UInt32, limit))

  QUERY(getIngredientById,
        "SELECT * FROM ingredient WHERE id=:id;",
        PARAM(oatpp::Int32, id))

  QUERY(updateIngredient,
        "UPDATE ingredient "
        "SET "
        "name=:ingredient.name "
        "WHERE id=:user.id",
        PARAM(oatpp::Object<IngredientDto>, ingredient))

  QUERY(deleteIngredientById,
        "DELETE FROM ingredient WHERE id=:id",
        PARAM(oatpp::Int32, id))
};

#include OATPP_CODEGEN_END(DbClient)

#endif//IngredientDb_hpp

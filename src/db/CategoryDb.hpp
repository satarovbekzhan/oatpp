#ifndef CategoryDb_hpp
#define CategoryDb_hpp

#include "oatpp/orm/SchemaMigration.hpp"
#include "oatpp/orm/DbClient.hpp"
#include "oatpp/core/macro/codegen.hpp"
#include "../dto/CategoryDto.hpp"

#include OATPP_CODEGEN_BEGIN(DbClient)

class CategoryDb : public oatpp::orm::DbClient {
public:

  CategoryDb(const std::shared_ptr<oatpp::orm::Executor>& executor) : oatpp::orm::DbClient(executor) {
//    oatpp::orm::SchemaMigration migration(executor);
//    migration.addFile(1, "src/sql/category_init.sql");
//    migration.migrate();
  }

  QUERY(createCategory,
        "INSERT INTO category "
        "(name) "
        "VALUES (:category.name);",
        PARAM(oatpp::Object<CategoryDto>, category))

  QUERY(getAllCategories,
        "SELECT * FROM category LIMIT :limit OFFSET :offset;",
        PARAM(oatpp::UInt32, offset),
        PARAM(oatpp::UInt32, limit))

  QUERY(getCategoryById,
        "SELECT * FROM category WHERE id=:id;",
        PARAM(oatpp::Int32, id))

  QUERY(updateCategory,
        "UPDATE category "
        "SET "
        "name=:category.name "
        "WHERE id=:category.id",
        PARAM(oatpp::Object<CategoryDto>, category))

  QUERY(deleteCategoryById,
        "DELETE FROM category WHERE id=:id",
        PARAM(oatpp::Int32, id))
};

#include OATPP_CODEGEN_END(DbClient)

#endif//CategoryDb_hpp

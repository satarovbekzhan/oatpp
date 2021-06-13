#ifndef RefProductCategoryDb_hpp
#define RefProductCategoryDb_hpp

#include "oatpp/orm/SchemaMigration.hpp"
#include "oatpp/orm/DbClient.hpp"
#include "oatpp/core/macro/codegen.hpp"
#include "../dto/RefProductCategoryDto.hpp"

#include OATPP_CODEGEN_BEGIN(DbClient)

class RefProductCategoryDb : public oatpp::orm::DbClient {
public:

  RefProductCategoryDb(const std::shared_ptr<oatpp::orm::Executor>& executor) : oatpp::orm::DbClient(executor) {
//    oatpp::orm::SchemaMigration migration(executor);
//    migration.addFile(1, "src/sql/ref_p_c_init.sql");
//    migration.migrate();
  }

  QUERY(createRefPC,
        "INSERT INTO ref_product_category "
        "(product, category) "
        "VALUES (:ref_pc.product, "
        ":ref_pc.category);",
        PARAM(oatpp::Object<RefProductCategoryDto>, ref_pc))

  QUERY(getAllRefPCs,
        "SELECT * FROM ref_product_category LIMIT :limit OFFSET :offset;",
        PARAM(oatpp::UInt32, offset),
        PARAM(oatpp::UInt32, limit))

  QUERY(getRefPCById,
        "SELECT * FROM ref_product_category WHERE id=:id;",
        PARAM(oatpp::Int32, id))

  QUERY(updateRefPC,
        "UPDATE ref_product_category "
        "SET "
        "product=:ref_pc.product, "
        "category=:ref_pc.category "
        "WHERE id=:ref_pc.id",
        PARAM(oatpp::Object<RefProductCategoryDto>, ref_pc))

  QUERY(deleteRefPCById,
        "DELETE FROM ref_product_category WHERE id=:id",
        PARAM(oatpp::Int32, id))
};

#include OATPP_CODEGEN_END(DbClient)

#endif//RefProductCategoryDb_hpp

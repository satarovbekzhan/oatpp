#ifndef PriceDb_hpp
#define PriceDb_hpp

#include "oatpp/orm/SchemaMigration.hpp"
#include "oatpp/orm/DbClient.hpp"
#include "oatpp/core/macro/codegen.hpp"
#include "../dto/model/PriceDto.hpp"

#include OATPP_CODEGEN_BEGIN(DbClient)

class PriceDb : public oatpp::orm::DbClient {
public:

  PriceDb(const std::shared_ptr<oatpp::orm::Executor>& executor) : oatpp::orm::DbClient(executor) {
//    oatpp::orm::SchemaMigration migration(executor);
//    migration.addFile(1, "src/sql/price_init.sql");
//    migration.migrate();
  }

  QUERY(createPrice,
        "INSERT INTO price "
        "(product, value) "
        "VALUES (:price.product, "
        ":price.value);",
        PARAM(oatpp::Object<PriceDto>, price))

  QUERY(getAllPrices,
        "SELECT * FROM price LIMIT :limit OFFSET :offset;",
        PARAM(oatpp::UInt32, offset),
        PARAM(oatpp::UInt32, limit))

  QUERY(getPriceById,
        "SELECT * FROM price WHERE id=:id;",
        PARAM(oatpp::Int32, id))

  QUERY(updatePrice,
        "UPDATE price "
        "SET "
        "product=:price.product, "
        "value=:price.value "
        "timestamp=:price.timestamp"
        "WHERE id=:price.id",
        PARAM(oatpp::Object<PriceDto>, price))

  QUERY(deletePriceById,
        "DELETE FROM price WHERE id=:id",
        PARAM(oatpp::Int32, id))
};

#include OATPP_CODEGEN_END(DbClient)

#endif//PriceDb_hpp

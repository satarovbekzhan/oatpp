#ifndef PhoneDb_hpp
#define PhoneDb_hpp

#include "oatpp/orm/SchemaMigration.hpp"
#include "oatpp/orm/DbClient.hpp"
#include "oatpp/core/macro/codegen.hpp"
#include "../dto/PhoneDto.hpp"

#include OATPP_CODEGEN_BEGIN(DbClient)

class PhoneDb : public oatpp::orm::DbClient {
public:

  PhoneDb(const std::shared_ptr<oatpp::orm::Executor>& executor) : oatpp::orm::DbClient(executor) {
//    oatpp::orm::SchemaMigration migration(executor);
//    migration.addFile(1, "src/sql/phone_init.sql");
//    migration.migrate();
  }

  QUERY(createPhone,
        "INSERT INTO phone "
        "(number, user) "
        "VALUES (:phone.number, "
        ":phone.user);",
        PARAM(oatpp::Object<PhoneDto>, phone))

  QUERY(getAllPhones,
        "SELECT * FROM phone LIMIT :limit OFFSET :offset;",
        PARAM(oatpp::UInt32, offset),
        PARAM(oatpp::UInt32, limit))

  QUERY(getPhoneById,
        "SELECT * FROM phone WHERE id=:id;",
        PARAM(oatpp::Int32, id))

  QUERY(updatePhone,
        "UPDATE phone "
        "SET "
        "number=:phone.number, "
        "user=:phone.user "
        "WHERE id=:phone.id",
        PARAM(oatpp::Object<PhoneDto>, phone))

  QUERY(deletePhoneById,
        "DELETE FROM phone WHERE id=:id",
        PARAM(oatpp::Int32, id))
};

#include OATPP_CODEGEN_END(DbClient)

#endif//PhoneDb_hpp

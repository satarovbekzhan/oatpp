#ifndef AddressDb_hpp
#define AddressDb_hpp

#include "oatpp/orm/SchemaMigration.hpp"
#include "oatpp/orm/DbClient.hpp"
#include "oatpp/core/macro/codegen.hpp"
#include "../dto/model/AddressDto.hpp"

#include OATPP_CODEGEN_BEGIN(DbClient)

class AddressDb : public oatpp::orm::DbClient {
public:

  AddressDb(const std::shared_ptr<oatpp::orm::Executor>& executor) : oatpp::orm::DbClient(executor) {
//    oatpp::orm::SchemaMigration migration(executor);
//    migration.addFile(1, "src/sql/address_init.sql");
//    migration.migrate();
  }

  QUERY(createAddress,
        "INSERT INTO address "
        "(town, street, house, note, user) "
        "VALUES (:address.town, "
        ":address.street, "
        ":address.house, "
        ":address.note, "
        ":address.user);",
        PARAM(oatpp::Object<AddressDto>, address))

  QUERY(getAllAddresses,
        "SELECT * FROM address LIMIT :limit OFFSET :offset;",
        PARAM(oatpp::UInt32, offset),
        PARAM(oatpp::UInt32, limit))

  QUERY(getAddressById,
        "SELECT * FROM address WHERE id=:id;",
        PARAM(oatpp::Int32, id))

  QUERY(updateAddress,
        "UPDATE address "
        "SET "
        "town=:address.town, "
        "street=:address.street, "
        "house=:address.house, "
        "note=:address.note, "
        "user=:address.user "
        "WHERE id=:address.id",
        PARAM(oatpp::Object<AddressDto>, address))

  QUERY(deleteAddressById,
        "DELETE FROM address WHERE id=:id",
        PARAM(oatpp::Int32, id))
};

#include OATPP_CODEGEN_END(DbClient)

#endif//AddressDb_hpp

#ifndef CartDb_hpp
#define CartDb_hpp

#include "oatpp/orm/SchemaMigration.hpp"
#include "oatpp/orm/DbClient.hpp"
#include "oatpp/core/macro/codegen.hpp"
#include "../dto/CartDto.hpp"

#include OATPP_CODEGEN_BEGIN(DbClient)

class CartDb : public oatpp::orm::DbClient {
public:

  CartDb(const std::shared_ptr<oatpp::orm::Executor>& executor) : oatpp::orm::DbClient(executor) {
//    oatpp::orm::SchemaMigration migration(executor);
//    migration.addFile(1, "src/sql/cart_init.sql");
//    migration.migrate();
  }

  QUERY(createCart,
        "INSERT INTO cart "
        "(product, user, amount) "
        "VALUES (:cart.product, "
        ":cart.user, "
        ":cart.amount);",
        PARAM(oatpp::Object<CartDto>, cart))

  QUERY(getAllCarts,
        "SELECT * FROM cart LIMIT :limit OFFSET :offset;",
        PARAM(oatpp::UInt32, offset),
        PARAM(oatpp::UInt32, limit))

  QUERY(getCartById,
        "SELECT * FROM cart WHERE id=:id;",
        PARAM(oatpp::Int32, id))

  QUERY(updateCart,
        "UPDATE cart "
        "SET "
        "product=:cart.product, "
        "user=:cart.user, "
        "amount=:cart.amount "
        "WHERE id=:user.id",
        PARAM(oatpp::Object<CartDto>, cart))

  QUERY(deleteCartById,
        "DELETE FROM cart WHERE id=:id",
        PARAM(oatpp::Int32, id))
};

#include OATPP_CODEGEN_END(DbClient)

#endif//CartDb_hpp

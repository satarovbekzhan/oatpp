#ifndef OrderDb_hpp
#define OrderDb_hpp

#include "oatpp/orm/SchemaMigration.hpp"
#include "oatpp/orm/DbClient.hpp"
#include "oatpp/core/macro/codegen.hpp"
#include "../dto/model/OrderDto.hpp"

#include OATPP_CODEGEN_BEGIN(DbClient)

class OrderDb : public oatpp::orm::DbClient {
public:

    OrderDb(const std::shared_ptr<oatpp::orm::Executor> &executor) : oatpp::orm::DbClient(executor) {}

    QUERY(createOrder,
          "INSERT INTO order "
          "(product, user, address, amount) "
          "VALUES (:order.product, "
          ":order.user, "
          ":order.address, "
          ":order.amount);",
          PARAM(oatpp::Object<OrderDto>, order))

    QUERY(getAllOrders,
          "SELECT * FROM order LIMIT :limit OFFSET :offset;",
          PARAM(oatpp::UInt32, offset),
          PARAM(oatpp::UInt32, limit))

    QUERY(getOrderById,
          "SELECT * FROM order WHERE id=:id;",
          PARAM(oatpp::Int32, id))

    QUERY(updateOrder,
          "UPDATE order "
          "SET "
          "product=:order.product, "
          "user=:order.user, "
          "address=:order.address, "
          "amount=:order.amount, "
          "timestamp=:order.timestamp "
          "WHERE id=:order.id",
          PARAM(oatpp::Object<OrderDto>, order))

    QUERY(deleteOrderById,
          "DELETE FROM users WHERE id=:id",
          PARAM(oatpp::Int32, id))
};

#include OATPP_CODEGEN_END(DbClient)

#endif//OrderDb_hpp

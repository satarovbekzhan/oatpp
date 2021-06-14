#ifndef ProductDb_hpp
#define ProductDb_hpp

#include "oatpp/orm/SchemaMigration.hpp"
#include "oatpp/orm/DbClient.hpp"
#include "oatpp/core/macro/codegen.hpp"
#include "../dto/model/ProductDto.hpp"

#include OATPP_CODEGEN_BEGIN(DbClient)

class ProductDb : public oatpp::orm::DbClient {
public:

    ProductDb(const std::shared_ptr<oatpp::orm::Executor> &executor) : oatpp::orm::DbClient(executor) {}

    QUERY(createProduct,
          "INSERT INTO product "
          "(title, description, picture) "
          "VALUES (:product.title, "
          ":product.description, "
          ":product.picture);",
          PARAM(oatpp::Object<ProductDto>, product))

    QUERY(getAllProducts,
          "SELECT * FROM product LIMIT :limit OFFSET :offset;",
          PARAM(oatpp::UInt32, offset),
          PARAM(oatpp::UInt32, limit))

    QUERY(getProductById,
          "SELECT * FROM product WHERE id=:id;",
          PARAM(oatpp::Int32, id))

    QUERY(updateProduct,
          "UPDATE product "
          "SET "
          "title=:product.title, "
          "description=:description.password, "
          "picture=:product.picture "
          "WHERE id=:product.id",
          PARAM(oatpp::Object<ProductDto>, product))

    QUERY(deleteProductById,
          "DELETE FROM product WHERE id=:id",
          PARAM(oatpp::Int32, id))
};

#include OATPP_CODEGEN_END(DbClient)

#endif//ProductDb_hpp

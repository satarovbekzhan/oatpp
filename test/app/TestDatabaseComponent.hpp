#ifndef TestDatabaseComponent_hpp
#define TestDatabaseComponent_hpp

#include "../../src/db/UserDb.hpp"
#include "../../src/db/AddressDb.hpp"
#include "../../src/db/PhoneDb.hpp"
#include "../../src/db/ProductDb.hpp"
#include "../../src/db/CategoryDb.hpp"
#include "../../src/db/IngredientDb.hpp"
#include "../../src/db/PriceDb.hpp"
#include "../../src/db/CartDb.hpp"
#include "../../src/db/OrderDb.hpp"
#include "../../src/db/RefProductCategoryDb.hpp"
#include "../../src/db/RefProductIngredientDb.hpp"

class TestDatabaseComponent {
public:
  OATPP_CREATE_COMPONENT(std::shared_ptr<oatpp::provider::Provider<oatpp::sqlite::Connection>>, dbConnectionProvider)([] {
    auto connectionProvider = std::make_shared<oatpp::sqlite::ConnectionProvider>(DATABASE_FILE);
    auto executor = std::make_shared<oatpp::sqlite::Executor>(connectionProvider);

    oatpp::orm::SchemaMigration migration(executor);
    migration.addFile(1, "src/sql/BASE_CONSTRUCTION.sql");
    migration.migrate();

    return oatpp::sqlite::ConnectionPool::createShared(connectionProvider,
                                                       10,
                                                       std::chrono::seconds(5));
  }());

  // User Model Database Client
  OATPP_CREATE_COMPONENT(std::shared_ptr<UserDb>, userDatabaseClient)([] {
    OATPP_COMPONENT(std::shared_ptr<oatpp::provider::Provider<oatpp::sqlite::Connection>>, connectionProvider);
    auto executor = std::make_shared<oatpp::sqlite::Executor>(connectionProvider);
    return std::make_shared<UserDb>(executor);
  }());

  // Address Model Database Client
  OATPP_CREATE_COMPONENT(std::shared_ptr<AddressDb>, addressDatabaseClient)([] {
    OATPP_COMPONENT(std::shared_ptr<oatpp::provider::Provider<oatpp::sqlite::Connection>>, connectionProvider);
    auto executor = std::make_shared<oatpp::sqlite::Executor>(connectionProvider);
    return std::make_shared<AddressDb>(executor);
  }());

  // Phone Model Database Client
  OATPP_CREATE_COMPONENT(std::shared_ptr<PhoneDb>, phoneDatabaseClient)([] {
    OATPP_COMPONENT(std::shared_ptr<oatpp::provider::Provider<oatpp::sqlite::Connection>>, connectionProvider);
    auto executor = std::make_shared<oatpp::sqlite::Executor>(connectionProvider);
    return std::make_shared<PhoneDb>(executor);
  }());

  // Product Model Database Client
  OATPP_CREATE_COMPONENT(std::shared_ptr<ProductDb>, productDatabaseClient)([] {
    OATPP_COMPONENT(std::shared_ptr<oatpp::provider::Provider<oatpp::sqlite::Connection>>, connectionProvider);
    auto executor = std::make_shared<oatpp::sqlite::Executor>(connectionProvider);
    return std::make_shared<ProductDb>(executor);
  }());

  // Category Model Database Client
  OATPP_CREATE_COMPONENT(std::shared_ptr<CategoryDb>, categoryDatabaseClient)([] {
    OATPP_COMPONENT(std::shared_ptr<oatpp::provider::Provider<oatpp::sqlite::Connection>>, connectionProvider);
    auto executor = std::make_shared<oatpp::sqlite::Executor>(connectionProvider);
    return std::make_shared<CategoryDb>(executor);
  }());

  // Ingredient Model Database Client
  OATPP_CREATE_COMPONENT(std::shared_ptr<IngredientDb>, ingredientDatabaseClient)([] {
    OATPP_COMPONENT(std::shared_ptr<oatpp::provider::Provider<oatpp::sqlite::Connection>>, connectionProvider);
    auto executor = std::make_shared<oatpp::sqlite::Executor>(connectionProvider);
    return std::make_shared<IngredientDb>(executor);
  }());

  // Price Model Database Client
  OATPP_CREATE_COMPONENT(std::shared_ptr<PriceDb>, priceDatabaseClient)([] {
    OATPP_COMPONENT(std::shared_ptr<oatpp::provider::Provider<oatpp::sqlite::Connection>>, connectionProvider);
    auto executor = std::make_shared<oatpp::sqlite::Executor>(connectionProvider);
    return std::make_shared<PriceDb>(executor);
  }());

  // Cart Model Database Client
  OATPP_CREATE_COMPONENT(std::shared_ptr<CartDb>, cartDatabaseClient)([] {
    OATPP_COMPONENT(std::shared_ptr<oatpp::provider::Provider<oatpp::sqlite::Connection>>, connectionProvider);
    auto executor = std::make_shared<oatpp::sqlite::Executor>(connectionProvider);
    return std::make_shared<CartDb>(executor);
  }());

  // Order Model Database Client
  OATPP_CREATE_COMPONENT(std::shared_ptr<OrderDb>, orderDatabaseClient)([] {
    OATPP_COMPONENT(std::shared_ptr<oatpp::provider::Provider<oatpp::sqlite::Connection>>, connectionProvider);
    auto executor = std::make_shared<oatpp::sqlite::Executor>(connectionProvider);
    return std::make_shared<OrderDb>(executor);
  }());

  // RefProductCategory Model Database Client
  OATPP_CREATE_COMPONENT(std::shared_ptr<RefProductCategoryDb>, refProductCategoryDatabaseClient)([] {
    OATPP_COMPONENT(std::shared_ptr<oatpp::provider::Provider<oatpp::sqlite::Connection>>, connectionProvider);
    auto executor = std::make_shared<oatpp::sqlite::Executor>(connectionProvider);
    return std::make_shared<RefProductCategoryDb>(executor);
  }());

  // RefProductIngredient Model Database Client
  OATPP_CREATE_COMPONENT(std::shared_ptr<RefProductIngredientDb>, refProductIngredientDatabaseClient)([] {
    OATPP_COMPONENT(std::shared_ptr<oatpp::provider::Provider<oatpp::sqlite::Connection>>, connectionProvider);
    auto executor = std::make_shared<oatpp::sqlite::Executor>(connectionProvider);
    return std::make_shared<RefProductIngredientDb>(executor);
  }());

};

#endif//TestDatabaseComponent_hpp

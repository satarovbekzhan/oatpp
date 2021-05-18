#ifndef DatabaseComponent_hpp
#define DatabaseComponent_hpp

#include "db/UserDb.hpp"

class DatabaseComponent {
public:
  OATPP_CREATE_COMPONENT(std::shared_ptr<oatpp::provider::Provider<oatpp::sqlite::Connection>>, dbConnectionProvider)([] {
    auto connectionProvider = std::make_shared<oatpp::sqlite::ConnectionProvider>(DATABASE_FILE);
    return oatpp::sqlite::ConnectionPool::createShared(connectionProvider,
                                                       10,
                                                       std::chrono::seconds(5));
  }());

  // User Model Database Client
  OATPP_CREATE_COMPONENT(std::shared_ptr<UserDb>, userDatabaseClient)([] {
//    auto connectionProvider = std::make_shared<oatpp::sqlite::ConnectionProvider>(DATABASE_FILE);
    OATPP_COMPONENT(std::shared_ptr<oatpp::provider::Provider<oatpp::sqlite::Connection>>, connectionProvider);
    auto executor = std::make_shared<oatpp::sqlite::Executor>(connectionProvider);
    return std::make_shared<UserDb>(executor);
  }());

};

#endif//DatabaseComponent_hpp

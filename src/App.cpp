#include <iostream>

#include "oatpp/web/server/HttpConnectionHandler.hpp"
#include "oatpp/network/Server.hpp"
#include "oatpp/network/tcp/server/ConnectionProvider.hpp"
#include "oatpp-sqlite/orm.hpp"

#include "db/UserDb.hpp"
#include "AppComponent.hpp"
#include "controller/UserController.hpp"

//class Handler : public oatpp::web::server::HttpRequestHandler {
//private:
//  OATPP_COMPONENT(std::shared_ptr<oatpp::data::mapping::ObjectMapper>, objectMapper);
//  OATPP_COMPONENT(std::shared_ptr<UserDb>, userDatabaseClient);
//public:
//
//  std::shared_ptr<OutgoingResponse> handle(const std::shared_ptr<IncomingRequest>& request) override {
////    userDatabaseClient->createUser("bs@gmail.com", "123", "Bekzhan", "Satarov", "Herr", Role::ADMIN);
////    userDatabaseClient->createUser("jd@yahoo.org", "321", "John", "Doe", "Herr", Role::MODERATOR);
////    userDatabaseClient->createUser("cs@outlook.mi", "213", "Kristen", "Stewart", "Frau", Role::CUSTOMER);
////    userDatabaseClient->createUser("ow@mail.com", "423", "Ollie", "Watkins", "Mr", Role::CUSTOMER);
//
//    auto result = userDatabaseClient->getAllUsers();
//    auto dataset = result->fetch<oatpp::Vector<oatpp::Object<UserDto>>>();
//    auto json = objectMapper->writeToString(dataset);
//
//    return ResponseFactory::createResponse(Status::CODE_200, json);
//  }
//
//};

void run() {
  AppComponent components;

  OATPP_COMPONENT(std::shared_ptr<oatpp::web::server::HttpRouter>, router);

  auto userController = std::make_shared<UserController>();
  userController->addEndpointsToRouter(router);
//  router->route("GET", "/user", std::make_shared<Handler>());

  OATPP_COMPONENT(std::shared_ptr<oatpp::network::ConnectionHandler>, connectionHandler);

  OATPP_COMPONENT(std::shared_ptr<oatpp::network::ServerConnectionProvider>, connectionProvider);

  /* Create server which takes provided TCP connections and passes them to HTTP connection handler */
  oatpp::network::Server server(connectionProvider, connectionHandler);

  /* Priny info about server port */
  OATPP_LOGI("Pizzeria App", "Server running on port %s", connectionProvider->getProperty("port").getData());

  /* Run server */
  server.run();
}

int main() {
  oatpp::base::Environment::init();
  run();
  oatpp::base::Environment::destroy();
  return 0;
}
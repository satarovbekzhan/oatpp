#include <iostream>

#include "oatpp/web/server/HttpConnectionHandler.hpp"
#include "oatpp/network/Server.hpp"
#include "oatpp/network/tcp/server/ConnectionProvider.hpp"
#include "oatpp-sqlite/orm.hpp"

#include "db/UserDb.hpp"
#include "AppComponent.hpp"
#include "controller/UserController.hpp"

void run() {
  AppComponent components;

  OATPP_COMPONENT(std::shared_ptr<oatpp::web::server::HttpRouter>, router);

  auto userController = std::make_shared<UserController>();
  userController->addEndpointsToRouter(router);
//  router->route("GET", "/user", std::make_shared<Handler>());

  OATPP_COMPONENT(std::shared_ptr<oatpp::network::ConnectionHandler>, connectionHandler);
  OATPP_COMPONENT(std::shared_ptr<oatpp::network::ServerConnectionProvider>, connectionProvider);
  oatpp::network::Server server(connectionProvider, connectionHandler);

  OATPP_LOGI("Pizzeria App", "Server running on port %s", connectionProvider->getProperty("port").getData());
  server.run();
}

int main() {
  oatpp::base::Environment::init();
  run();
  oatpp::base::Environment::destroy();
  return 0;
}
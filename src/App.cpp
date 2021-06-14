#include <iostream>

#include "oatpp/web/server/HttpConnectionHandler.hpp"
#include "oatpp/network/Server.hpp"
#include "oatpp/network/tcp/server/ConnectionProvider.hpp"
#include "oatpp-sqlite/orm.hpp"
#include "oatpp/core/utils/ConversionUtils.hpp"

#include "db/UserDb.hpp"
#include "AppComponent.hpp"
#include "util/JwtUtil.hpp"
#include "controller/LoginController.hpp"
#include "controller/UserController.hpp"
#include "controller/MainController.hpp"


void run() {
    AppComponent components;

    OATPP_COMPONENT(std::shared_ptr<oatpp::web::server::HttpRouter>, router);

    auto loginController = std::make_shared<LoginController>();
    loginController->addEndpointsToRouter(router);
    auto userController = std::make_shared<UserController>();
    userController->addEndpointsToRouter(router);
    auto productController = std::make_shared<MainController>();
    productController->addEndpointsToRouter(router);

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
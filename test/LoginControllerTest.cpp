#include "LoginControllerTest.hpp"

void LoginControllerTest::onRun() {

    TestComponent component;

    oatpp::test::web::ClientServerTestRunner runner;
    runner.addController(std::make_shared<LoginController>());

    runner.run([this, &runner] {

        OATPP_COMPONENT(std::shared_ptr<oatpp::network::ClientConnectionProvider>, clientConnectionProvider);
        OATPP_COMPONENT(std::shared_ptr<oatpp::data::mapping::ObjectMapper>, objectMapper);
        auto requestExecutor = oatpp::web::client::HttpRequestExecutor::createShared(clientConnectionProvider);
        auto client = TestClient::createShared(requestExecutor, objectMapper);

//        ///////// correct credentials passed ////////////////////////////

        std::string email = "satarovbekzhan@gmail.com";
        std::string password = "123";
        auto loginDto = LoginDto::createShared();
        loginDto->email = oatpp::String(email.c_str(), email.length(), true);
        loginDto->password = oatpp::String(password.c_str(), password.length(), true);
        auto response = client->getBearerToken(loginDto);

        OATPP_ASSERT(response->getStatusCode() == 200);

        auto tokenDto = response->readBodyToDto<oatpp::Object<TokenDto>>(objectMapper.get());

        OATPP_ASSERT(tokenDto);
        OATPP_ASSERT(tokenDto->token);
        OATPP_ASSERT(tokenDto->email == "satarovbekzhan@gmail.com");

//        //////// incorrect credentials passed ///////////////////////

        email = "satarovbekzhan@gmail.com";
        password = "wrong_password";
        loginDto = LoginDto::createShared();
        loginDto->email = oatpp::String(email.c_str(), email.length(), true);
        loginDto->password = oatpp::String(password.c_str(), password.length(), true);
        response = client->getBearerToken(loginDto);

        OATPP_ASSERT(response->getStatusCode() == 401);

//        OATPP_LOGD(TAG, "[loginData] data='%s'", response->readBodyToString()->c_str());
//         std::cout << userDto->email->std_str() << std::endl;

        OATPP_COMPONENT(std::shared_ptr<oatpp::provider::Provider<oatpp::sqlite::Connection>>, connectionProvider);
        connectionProvider->stop();

    }, std::chrono::minutes(10));

    std::this_thread::sleep_for(std::chrono::seconds(1));

}
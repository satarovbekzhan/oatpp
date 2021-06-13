#include "UserControllerTest.hpp"

void UserControllerTest::onRun() {

  TestComponent component;

  oatpp::test::web::ClientServerTestRunner runner;
  runner.addController(std::make_shared<UserController>());

  runner.run([this, &runner] {

         OATPP_COMPONENT(std::shared_ptr<oatpp::network::ClientConnectionProvider>, clientConnectionProvider);
         OATPP_COMPONENT(std::shared_ptr<oatpp::data::mapping::ObjectMapper>, objectMapper);
         auto requestExecutor = oatpp::web::client::HttpRequestExecutor::createShared(clientConnectionProvider);
         auto client = TestClient::createShared(requestExecutor, objectMapper);


         auto response = client->getBekzhanUser();

         OATPP_ASSERT(response->getStatusCode() == 200);

         auto userDto = response->readBodyToDto<oatpp::Object<UserDto>>(objectMapper.get());
//         std::cout << userDto->email->std_str() << std::endl;

         OATPP_ASSERT(userDto);
         OATPP_ASSERT(userDto->email == "satarovbekzhan@gmail.com");

         OATPP_COMPONENT(std::shared_ptr<oatpp::provider::Provider<oatpp::sqlite::Connection>>, connectionProvider);
         connectionProvider->stop();

  }, std::chrono::minutes(10));

  std::this_thread::sleep_for(std::chrono::seconds(1));

}
#ifndef LoginControllerTest_hpp
#define LoginControllerTest_hpp

#include <iostream>

#include "oatpp-test/UnitTest.hpp"
#include "app/TestClient.hpp"
#include "app/TestComponent.hpp"
#include "oatpp/web/client/HttpRequestExecutor.hpp"
#include "oatpp-test/web/ClientServerTestRunner.hpp"

#include "../src/controller/LoginController.hpp"

class LoginControllerTest : public oatpp::test::UnitTest {
public:

    LoginControllerTest() : UnitTest("TEST[LoginControllerTest]") {}

    void onRun() override;

};

#endif//LoginControllerTest_hpp
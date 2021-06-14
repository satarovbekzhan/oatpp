#ifndef UserControllerTest_hpp
#define UserControllerTest_hpp

#include <iostream>

#include "oatpp-test/UnitTest.hpp"
#include "app/TestClient.hpp"
#include "app/TestComponent.hpp"
#include "oatpp/web/client/HttpRequestExecutor.hpp"
#include "oatpp-test/web/ClientServerTestRunner.hpp"

#include "../src/controller/UserController.hpp"
#include "../src/dto/model/UserDto.hpp"

class UserControllerTest : public oatpp::test::UnitTest {
public:

    UserControllerTest() : UnitTest("TEST[UserControllerTest]") {}

    void onRun() override;

};

#endif//UserControllerTest_hpp
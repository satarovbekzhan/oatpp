cmake_minimum_required(VERSION 3.16)
project(pizzeria CXX)

set(CMAKE_CXX_STANDARD 11)

add_library(pizzeria-lib
        src/AppComponent.hpp
        src/DatabaseComponent.hpp
#        auth
        src/auth/CustomAuthorizationObject.hpp
        src/auth/CustomBearerAuthorizationHandler.hpp
#        controller
        src/controller/UserController.hpp
        src/controller/MainController.hpp
        src/controller/LoginController.hpp
#        dto
        src/dto/model/UserDto.hpp
        src/dto/model/PhoneDto.hpp
        src/dto/model/AddressDto.hpp
        src/dto/model/ProductDto.hpp
        src/dto/model/IngredientDto.hpp
        src/dto/model/RefProductIngredientDto.hpp
        src/dto/model/CategoryDto.hpp
        src/dto/model/RefProductCategoryDto.hpp
        src/dto/model/PriceDto.hpp
        src/dto/model/CartDto.hpp
        src/dto/model/OrderDto.hpp
        src/dto/LoginDto.hpp
        src/dto/TokenDto.hpp
        #        db
        src/db/UserDb.hpp
        src/db/PhoneDb.hpp
        src/db/AddressDb.hpp
        src/db/ProductDb.hpp
        src/db/IngredientDb.hpp
        src/db/RefProductIngredientDb.hpp
        src/db/CategoryDb.hpp
        src/db/RefProductCategoryDb.hpp
        src/db/PriceDb.hpp
        src/db/CartDb.hpp
        src/db/OrderDb.hpp
#        service
        src/service/UserService.hpp
        src/service/UserService.cpp
        src/service/ProductService.hpp
        src/service/ProductService.cpp
        #        util
        src/util/JwtUtil.hpp
        )

find_package(oatpp 1.2.5 REQUIRED)
find_package(oatpp-sqlite 1.2.5 REQUIRED)
find_package(cpp-jwt REQUIRED)

target_link_libraries(pizzeria-lib
        PUBLIC oatpp::oatpp
        PUBLIC oatpp::oatpp-sqlite
        PUBLIC cpp-jwt::cpp-jwt)

add_definitions(
        ## SQLite database file
        -DDATABASE_FILE="${CMAKE_CURRENT_SOURCE_DIR}/db.sqlite"
        ## JWT secret key
        -DJWT_SECRET_KEY="some_secret_key"
        ## JWT signing algorithm
        -DJWT_SIGN_ALGORITHM="HS256"
)

if(CMAKE_SYSTEM_NAME MATCHES Linux)
    find_package(Threads REQUIRED)
    target_link_libraries(pizzeria-lib INTERFACE Threads::Threads ${CMAKE_DL_LIBS})
endif()

add_executable(pizzeria-exe src/App.cpp)
target_link_libraries(pizzeria-exe pizzeria-lib)

add_executable(pizzeria-test
        test/Tests.cpp
        test/app/TestClient.hpp
        test/app/TestDatabaseComponent.hpp
        test/app/TestComponent.hpp
        test/UserControllerTest.hpp
        test/UserControllerTest.cpp
        test/LoginControllerTest.hpp
        test/LoginControllerTest.cpp)
target_link_libraries(pizzeria-test pizzeria-lib)

enable_testing()
add_test(project-tests pizzeria-test)
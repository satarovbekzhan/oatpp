cmake_minimum_required(VERSION 3.16)
project(pizzeria CXX)

include(cmake/StandardProjectSettings.cmake)
include(cmake/PreventInSourceBuilds.cmake)

# Link this 'library' to set the c++ standard / compile-time options requested
add_library(project_options INTERFACE)
target_compile_features(project_options INTERFACE cxx_std_20)

if(CMAKE_CXX_COMPILER_ID MATCHES ".*Clang")
    option(ENABLE_BUILD_WITH_TIME_TRACE "Enable -ftime-trace to generate time tracing .json files on clang" OFF)
    if(ENABLE_BUILD_WITH_TIME_TRACE)
        target_compile_options(project_options INTERFACE -ftime-trace)
    endif()
endif()

# Link this 'library' to use the warnings specified in CompilerWarnings.cmake
add_library(project_warnings INTERFACE)

# enable cache system
include(cmake/Cache.cmake)

# standard compiler warnings
include(cmake/CompilerWarnings.cmake)
set_project_warnings(project_warnings)

# sanitizer options if supported by compiler
include(cmake/Sanitizers.cmake)
enable_sanitizers(project_options)

# allow for static analysis options
include(cmake/StaticAnalyzers.cmake)

option(BUILD_SHARED_LIBS "Enable compilation of shared libraries" OFF)
option(ENABLE_TESTING "Enable Test Builds" ON)
option(ENABLE_FUZZING "Enable Fuzzing Builds" OFF)

# Very basic PCH example
option(ENABLE_PCH "Enable Precompiled Headers" OFF)
if(ENABLE_PCH)
    # This sets a global PCH parameter, each project will build its own PCH, which is a good idea if any #define's change
    #
    # consider breaking this out per project as necessary
    target_precompile_headers(
            project_options
            INTERFACE
            <vector>
            <string>
            <map>
            <utility>)
endif()

# ---- Add dependencies via CPM ----
# see https://github.com/TheLartians/CPM.cmake for more info
include(cmake/CPM.cmake)

CPMAddPackage(
        NAME fmt
        GIT_TAG 7.1.3
        GITHUB_REPOSITORY fmtlib/fmt # to get an installable target
        OPTIONS "FMT_INSTALL YES"
)

CPMAddPackage(
        NAME spdlog
        VERSION 1.8.2
        GITHUB_REPOSITORY gabime/spdlog # to get an installable target
)

if(ENABLE_TESTING)
    enable_testing()
    message("Building Tests. Be sure to check out test/constexpr_tests for constexpr testing")
    add_subdirectory(test)
endif()

if(ENABLE_FUZZING)
    message("Building Fuzz Tests, using fuzzing sanitizer https://www.llvm.org/docs/LibFuzzer.html")
    add_subdirectory(fuzz_test)
endif()

#add_subdirectory(src)

# ############################################################

add_library(pizzeria-lib
        src/AppComponent.hpp
        src/DatabaseComponent.hpp
#        controller
        src/controller/UserController.hpp
#        dto
        src/dto/AddressDto.hpp
        src/dto/CartDto.hpp
        src/dto/CartItemDto.hpp
        src/dto/CategoryDto.hpp
        src/dto/HistoryDto.hpp
        src/dto/IngredientDto.hpp
        src/dto/OrderDto.hpp
        src/dto/OrderItemDto.hpp
        src/dto/PhoneDto.hpp
        src/dto/ProductDto.hpp
        src/dto/ProductInstanceDto.hpp
        src/dto/SizeDto.hpp
        src/dto/UserDto.hpp
#        db
        src/db/UserDb.hpp
#        service
        src/service/UserService.hpp
        src/service/UserService.cpp
        )

find_package(oatpp 1.2.5 REQUIRED)
find_package(oatpp-sqlite 1.2.5 REQUIRED)
target_link_libraries(pizzeria-lib
        PUBLIC oatpp::oatpp
        PUBLIC oatpp::oatpp-sqlite)

if(CMAKE_SYSTEM_NAME MATCHES Linux)
    find_package(Threads REQUIRED)
    target_link_libraries(pizzeria-lib INTERFACE Threads::Threads ${CMAKE_DL_LIBS})
endif()

add_definitions(
        ## SQLite database file
        -DDATABASE_FILE="${CMAKE_CURRENT_SOURCE_DIR}/db.sqlite"
        ## SQLite database test file
#        -DTESTDATABASE_FILE="${CMAKE_CURRENT_SOURCE_DIR}/test-db.sqlite"

        ## Path to database migration scripts
        -DDATABASE_MIGRATIONS="${CMAKE_CURRENT_SOURCE_DIR}/sql"
)

add_executable(pizzeria-exe src/App.cpp)
target_link_libraries(pizzeria-exe pizzeria-lib)
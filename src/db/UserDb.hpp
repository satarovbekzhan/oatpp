#ifndef UserDb_hpp
#define UserDb_hpp

#include "oatpp/orm/SchemaMigration.hpp"
#include "oatpp/orm/DbClient.hpp"
#include "oatpp/core/macro/codegen.hpp"
#include "../dto/UserDto.hpp"

#include OATPP_CODEGEN_BEGIN(DbClient)

class UserDb : public oatpp::orm::DbClient {
public:

  UserDb(const std::shared_ptr<oatpp::orm::Executor>& executor)
    : oatpp::orm::DbClient(executor)
  {}

//  QUERY(createUser,
//        "INSERT INTO users "
//        "(email, password, firstname, "
//        "lastname, salutation, role) "
//        "VALUES (:email, :password, "
//        ":firstname, :lastname, :salutation, :role);",
//        PARAM(oatpp::String, email),
//        PARAM(oatpp::String, password),
//        PARAM(oatpp::String, firstname),
//        PARAM(oatpp::String, lastname),
//        PARAM(oatpp::String, salutation),
//        PARAM(oatpp::Enum<Role>::AsString, role))

  QUERY(createUser,
        "INSERT INTO users "
        "(email, password, firstname, lastname, salutation, role) "
        "VALUES (:user.email, "
        ":user.password, "
        ":user.firstname, "
        ":user.lastname, "
        ":user.salutation, "
        ":user.role);",
        PARAM(oatpp::Object<UserDto>, user))

  QUERY(getAllUsers,
        "SELECT * FROM users LIMIT :limit OFFSET :offset;",
        PARAM(oatpp::UInt32, offset),
        PARAM(oatpp::UInt32, limit))

  QUERY(getUserById,
        "SELECT * FROM users WHERE id=:id;",
        PARAM(oatpp::Int32, id))

  QUERY(updateUser,
        "UPDATE users "
        "SET "
        "email=:user.email, "
        "password=:user.password, "
        "firstname=:user.firstname, "
        "lastname=:user.lastname, "
        "salutation=:user.salutation, "
        "role=:user.role "
        "WHERE id=:user.id",
        PARAM(oatpp::Object<UserDto>, user))

  QUERY(deleteUserById,
        "DELETE FROM users WHERE id=:id",
        PARAM(oatpp::Int32, id))
};

#include OATPP_CODEGEN_END(DbClient)

#endif//UserDb_hpp

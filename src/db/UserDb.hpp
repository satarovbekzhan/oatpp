#ifndef UserDb_hpp
#define UserDb_hpp

#include "oatpp/orm/SchemaMigration.hpp"
#include "oatpp/orm/DbClient.hpp"
#include "oatpp/core/macro/codegen.hpp"
#include "../dto/model/UserDto.hpp"

#include OATPP_CODEGEN_BEGIN(DbClient)

class UserDb : public oatpp::orm::DbClient {
public:

  UserDb(const std::shared_ptr<oatpp::orm::Executor>& executor) : oatpp::orm::DbClient(executor) {}

  QUERY(createUser,
        "INSERT INTO user "
        "(email, password, firstname, lastname, salutation, role) "
        "VALUES (:user.email, "
        ":user.password, "
        ":user.firstname, "
        ":user.lastname, "
        ":user.salutation, "
        ":user.role);",
        PARAM(oatpp::Object<UserDto>, user))

  QUERY(getAllUsers,
        "SELECT * FROM user LIMIT :limit OFFSET :offset;",
        PARAM(oatpp::UInt32, offset),
        PARAM(oatpp::UInt32, limit))

  QUERY(getUserById,
        "SELECT * FROM user WHERE id=:id;",
        PARAM(oatpp::Int32, id))

  QUERY(getUserByEmail,
        "SELECT * FROM user WHERE email=:email;",
        PARAM(oatpp::String, email))

  QUERY(updateUser,
        "UPDATE user "
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
        "DELETE FROM user WHERE id=:id",
        PARAM(oatpp::Int32, id))
};

#include OATPP_CODEGEN_END(DbClient)

#endif//UserDb_hpp

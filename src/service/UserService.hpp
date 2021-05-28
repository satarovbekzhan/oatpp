#ifndef UserService_hpp
#define UserService_hpp

#include "oatpp/core/macro/component.hpp"
#include "oatpp/web/protocol/http/Http.hpp"
#include "oatpp-sqlite/Utils.hpp"
#include "oatpp/core/Types.hpp"

#include "../db/UserDb.hpp"

class UserService {
private:
  typedef oatpp::web::protocol::http::Status Status;
private:
  OATPP_COMPONENT(std::shared_ptr<UserDb>, userDatabaseClient);
public:
  oatpp::Object<UserDto> createUser(const oatpp::Object<UserDto>& dto);
  oatpp::Vector<oatpp::Object<UserDto>> getAllUsers(const oatpp::UInt32& offset, const oatpp::UInt32& limit);
  oatpp::Object<UserDto> getUserById(const oatpp::Int32& id);
  oatpp::Object<UserDto> updateUser(const oatpp::Object<UserDto>& dto);
  oatpp::Object<UserDto> deleteUserById(const oatpp::Int32& id);
};

#endif//UserService_hpp

#include "UserService.hpp"

oatpp::Object<UserDto> UserService::createUser(const oatpp::Object<UserDto>& dto) {
  auto dbResult = userDatabaseClient->createUser(dto);
  OATPP_ASSERT_HTTP(dbResult->isSuccess(), Status::CODE_500, dbResult->getErrorMessage());
  auto userId = oatpp::sqlite::Utils::getLastInsertRowId(dbResult->getConnection());
  return getUserById((v_int32) userId);
}

oatpp::Vector<oatpp::Object<UserDto>> UserService::getAllUsers(const oatpp::UInt32& offset, const oatpp::UInt32& limit) {
  auto dbResult = userDatabaseClient->getAllUsers(offset, limit);
  OATPP_ASSERT_HTTP(dbResult->isSuccess(), Status::CODE_500, dbResult->getErrorMessage());
  auto result = dbResult->fetch<oatpp::Vector<oatpp::Object<UserDto>>>();
  return result;
}

oatpp::Object<UserDto> UserService::getUserById(const oatpp::Int32& id) {
  auto dbResult = userDatabaseClient->getUserById(id);
  OATPP_ASSERT_HTTP(dbResult->isSuccess(), Status::CODE_500, dbResult->getErrorMessage());
  OATPP_ASSERT_HTTP(dbResult->hasMoreToFetch(), Status::CODE_404, "User not found");
  auto result = dbResult->fetch<oatpp::Vector<oatpp::Object<UserDto>>>();
  OATPP_ASSERT_HTTP(result->size() == 1, Status::CODE_500, "Unknown error");
  return result[0];
}

oatpp::Object<UserDto> UserService::updateUser(const oatpp::Object<UserDto>& dto) {
  auto dbResult = userDatabaseClient->updateUser(dto);
  OATPP_ASSERT_HTTP(dbResult->isSuccess(), Status::CODE_500, dbResult->getErrorMessage());
  return getUserById(dto->id);
}

oatpp::Object<UserDto> UserService::deleteUserById(const oatpp::Int32& id) {
  auto tempUser = getUserById(id);
  auto dbResult = userDatabaseClient->deleteUserById(id);
  OATPP_ASSERT_HTTP(dbResult->isSuccess(), Status::CODE_500, dbResult->getErrorMessage());
  return tempUser;
}

#include "ProductService.hpp"


oatpp::Vector<oatpp::Object<ProductDto>> ProductService::getAllProducts(const oatpp::UInt32& offset, const oatpp::UInt32& limit) {
  auto dbResult = productDatabaseClient->getAllProducts(offset, limit);
  OATPP_ASSERT_HTTP(dbResult->isSuccess(), Status::CODE_500, dbResult->getErrorMessage());
  auto result = dbResult->fetch<oatpp::Vector<oatpp::Object<ProductDto>>>();
  return result;
}
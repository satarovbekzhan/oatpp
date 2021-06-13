#ifndef MainController_hpp
#define MainController_hpp

#include "oatpp/web/server/api/ApiController.hpp"
#include "oatpp/parser/json/mapping/ObjectMapper.hpp"
#include "oatpp/core/macro/codegen.hpp"

#include "../service/ProductService.hpp"

#include OATPP_CODEGEN_BEGIN(ApiController)

class MainController : public oatpp::web::server::api::ApiController {
public:
  MainController(OATPP_COMPONENT(std::shared_ptr<ObjectMapper>, objectMapper))
    : oatpp::web::server::api::ApiController(objectMapper)
  {}
private:
  ProductService productService;
public:
  static std::shared_ptr<MainController> createShared(OATPP_COMPONENT(std::shared_ptr<ObjectMapper>, objectMapper)) {
    return std::make_shared<MainController>(objectMapper);
  }

  // READ ALL
  ENDPOINT_INFO(getProducts) {
    info->summary = "Get all stored products";
  }
  ENDPOINT("GET", "products/offset/{offset}/limit/{limit}", getProducts, PATH(UInt32, offset), PATH(UInt32, limit)) {
    return createDtoResponse(Status::CODE_200, productService.getAllProducts(offset, limit));
  }

};

#include OATPP_CODEGEN_BEGIN(ApiController)

#endif//MainController_hpp
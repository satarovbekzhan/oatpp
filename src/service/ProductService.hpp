#ifndef ProductService_hpp
#define ProductService_hpp

#include "oatpp/core/macro/component.hpp"
#include "oatpp/web/protocol/http/Http.hpp"
#include "oatpp-sqlite/Utils.hpp"
#include "oatpp/core/Types.hpp"

#include "../db/ProductDb.hpp"

class ProductService {
private:

    typedef oatpp::web::protocol::http::Status Status;

private:

    OATPP_COMPONENT(std::shared_ptr<ProductDb>, productDatabaseClient);

public:

    oatpp::Vector<oatpp::Object<ProductDto>> getAllProducts(const oatpp::UInt32 &offset, const oatpp::UInt32 &limit);
};

#endif//ProductService_hpp

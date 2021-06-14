#include <chrono>
#include <cassert>
#include <iostream>
#include "jwt/jwt.hpp"
#include "../dto/model/UserDto.hpp"

using namespace jwt::params;

class JwtUtil {
public:
    std::string secretKey = "pizzeria_secret_code";
    std::string algorithmType = "HS256";

    oatpp::String generateToken(oatpp::Object<UserDto> &userDto) {
        std::string role = "ROLE_ADMIN";
        if (userDto->role == UserDto_hpp::Role::MODERATOR) role = "ROLE_MODERATOR";
        if (userDto->role == UserDto_hpp::Role::CUSTOMER) role = "ROLE_CUSTOMER";

        jwt::jwt_object obj{algorithm(algorithmType), secret(secretKey),
                            payload({{"id",   oatpp::utils::conversion::int32ToStdStr(userDto->id)},
                                     {"role", role}})};
        obj.add_claim("exp", std::chrono::system_clock::now() + std::chrono::seconds{600});
        auto token = obj.signature();
        return oatpp::String(token.c_str(), token.length(), true);
    }

    bool verifyToken(oatpp::String token) {
        try {
            auto obj = jwt::decode(token->std_str(), algorithms({algorithmType}), secret(secretKey));
        } catch (const jwt::TokenExpiredError &e) {
            return false;
        } catch (const jwt::SignatureFormatError &e) {
            return false;
        } catch (const jwt::DecodeError &e) {
            return false;
        } catch (const jwt::VerificationError &e) {
            return false;
        }
        return true;
    }

    oatpp::String extractIdFromToken(oatpp::String token) {
        auto obj = jwt::decode(token->std_str(), algorithms({algorithmType}), secret(secretKey));
        auto id = obj.payload().get_claim_value<std::string>("id");
        return oatpp::String(id.c_str(), id.length(), true);
    }

    oatpp::String extractRoleFromToken(oatpp::String token) {
        auto obj = jwt::decode(token->std_str(), algorithms({algorithmType}), secret(secretKey));
        auto role = obj.payload().get_claim_value<std::string>("role");
        return oatpp::String(role.c_str(), role.length(), true);
    }
};

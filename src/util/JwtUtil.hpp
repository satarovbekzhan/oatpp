#include <chrono>
#include <cassert>
#include <iostream>
#include "jwt/jwt.hpp"
#include "../dto/model/UserDto.hpp"

using namespace jwt::params;

class JwtUtil {
public:
    static oatpp::String generateToken(oatpp::Object<UserDto> &userDto) {
        std::string id = oatpp::utils::conversion::int32ToStdStr(userDto->id);
        std::string role = "ROLE_ADMIN";
        if (userDto->role == UserDto_hpp::Role::MODERATOR) role = "ROLE_MODERATOR";
        if (userDto->role == UserDto_hpp::Role::CUSTOMER) role = "ROLE_CUSTOMER";

        jwt::jwt_object obj{algorithm(JWT_SIGN_ALGORITHM),
                            secret(JWT_SECRET_KEY),
                            payload({{"id", id},
                                     {"role", role}})};
        obj.add_claim("exp", std::chrono::system_clock::now() + std::chrono::seconds{600});
        auto token = obj.signature();
        return oatpp::String(token.c_str(), token.length(), true);
    }

    static bool verifyToken(oatpp::String token) {
        try {
            auto obj = jwt::decode(token->std_str(), algorithms({JWT_SIGN_ALGORITHM}), secret(JWT_SECRET_KEY));
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

    static oatpp::String extractIdFromToken(oatpp::String token) {
        auto obj = jwt::decode(token->std_str(), algorithms({JWT_SIGN_ALGORITHM}), secret(JWT_SECRET_KEY));
        auto id = obj.payload().get_claim_value<std::string>("id");
        return oatpp::String(id.c_str(), id.length(), true);
    }

    static oatpp::String extractRoleFromToken(oatpp::String token) {
        auto obj = jwt::decode(token->std_str(), algorithms({JWT_SIGN_ALGORITHM}), secret(JWT_SECRET_KEY));
        auto role = obj.payload().get_claim_value<std::string>("role");
        return oatpp::String(role.c_str(), role.length(), true);
    }
};

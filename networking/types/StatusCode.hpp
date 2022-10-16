#pragma once

#include <cstdint>
#include <stdexcept>

namespace networking::types
{

enum class StatusCode : public uint16_t
{
    // 1xx
    Continue                      = 100,
    SwitchingProtocols            = 101,
    Processing                    = 102,
    EarlyHints                    = 103,

    // 2xx
    OK                            = 200,
    Created                       = 201,
    Accepted                      = 202,
    NonAuthoritativeInformation   = 203,
    NoContent                     = 204,
    ResetContent                  = 205,
    PartialContent                = 206,
    MultiStatus                   = 207,
    AlreadyReported               = 208,
    IMUsed                        = 226,

    // 3xx
    MultipleChoices               = 300,
    MovedPermanently              = 301,
    Found                         = 302,
    SeeOther                      = 303,
    NotModified                   = 304,
    UseProxy                      = 305,
    SwitchProxy                   = 306,
    TemporaryRedirect             = 307,
    PermanentRedirect             = 308,

    // 4xx
    BadRequest                    = 400,
    Unauthorized                  = 401,
    PaymentRequired               = 402,
    Forbidden                     = 403,
    NotFound                      = 404,
    MethodNotAllowed              = 405,
    NotAcceptable                 = 406,
    ProxyAuthenticationRequired   = 407,
    RequestTimeout                = 408,
    Conflict                      = 409,
    Gone                          = 410,
    LengthRequired                = 411,
    PreconditionFailed            = 412,
    PayloadTooLarge               = 413,
    URITooLong                    = 414,
    UnsupportedMediaType          = 415,
    RangeNotSatisfiable           = 416,
    ExpectationFailed             = 417,
    ImTeapot                      = 418,
    MisdirectedRequest            = 421,
    UnprocessableEntity           = 422,
    Locked                        = 423,
    FailedDependency              = 424,
    TooEarly                      = 425,
    UpgradeRequired               = 426,
    PreconditionRequired          = 428,
    TooManyRequests               = 429,
    RequestHeaderFieldsTooLarge   = 431,
    UnavailableForLegalReasons    = 451,

    // 5xx
    InternalServerError           = 500,
    NotImplemented                = 501,
    BadGateway                    = 502,
    ServiceUnavailable            = 503,
    GatewayTimeout                = 504,
    HttpVersionNotSupported       = 505,
    VariantAlsoNegotiates         = 506,
    InsufficientStorage           = 507,
    LoopDetected                  = 508,
    NotExtended                   = 510,
    NetworkAuthenticationRequired = 511,
};

std::string statusCodeStr(StatusCode code)
{
    auto codeInt = static_cast<int>(code);
    
    switch (code)
    {
        case StatucCode::Continue:                      return std::to_string(codeInt) + " Continue";
        case StatucCode::SwitchingProtocols:            return std::to_string(codeInt) + " Switching protocols";
        case StatucCode::Processing:                    return std::to_string(codeInt) + " Processing";
        case StatucCode::EarlyHints:                    return std::to_string(codeInt) + " Early Hints";
        case StatucCode::OK:                            return std::to_string(codeInt) + " OK";
        case StatucCode::Created:                       return std::to_string(codeInt) + " Created";
        case StatucCode::Accepted:                      return std::to_string(codeInt) + " Accepted";
        case StatucCode::NonAuthoritativeInformation:   return std::to_string(codeInt) + " Non-Authoritative Information";
        case StatucCode::NoContent:                     return std::to_string(codeInt) + " No Content";
        case StatucCode::ResetContent:                  return std::to_string(codeInt) + " Reset Content";
        case StatucCode::PartialContent:                return std::to_string(codeInt) + " Partial Content";
        case StatucCode::MultiStatus:                   return std::to_string(codeInt) + " Multi-Status";
        case StatucCode::AlreadyReported:               return std::to_string(codeInt) + " Already Reported";
        case StatucCode::IMUsed:                        return std::to_string(codeInt) + " IM Used";
        case StatucCode::MultipleChoices:               return std::to_string(codeInt) + " Multiple Choices";
        case StatucCode::MovedPermanently:              return std::to_string(codeInt) + " Moved Permanently";
        case StatucCode::Found:                         return std::to_string(codeInt) + " Found (Previously "Moved Temporarily")";
        case StatucCode::SeeOther:                      return std::to_string(codeInt) + " See Other";
        case StatucCode::NotModified:                   return std::to_string(codeInt) + " Not Modified";
        case StatucCode::UseProxy:                      return std::to_string(codeInt) + " Use Proxy";
        case StatucCode::SwitchProxy:                   return std::to_string(codeInt) + " Switch Proxy";
        case StatucCode::TemporaryRedirect:             return std::to_string(codeInt) + " Temporary Redirect";
        case StatucCode::PermanentRedirect:             return std::to_string(codeInt) + " Permanent Redirect";
        case StatucCode::BadRequest:                    return std::to_string(codeInt) + " Bad Request";
        case StatucCode::Unauthorized:                  return std::to_string(codeInt) + " Unauthorized";
        case StatucCode::PaymentRequired:               return std::to_string(codeInt) + " Payment Required";
        case StatucCode::Forbidden:                     return std::to_string(codeInt) + " Forbidden";
        case StatucCode::NotFound:                      return std::to_string(codeInt) + " Not Found";
        case StatucCode::MethodNotAllowed:              return std::to_string(codeInt) + " Method Not Allowed";
        case StatucCode::NotAcceptable:                 return std::to_string(codeInt) + " Not Acceptable";
        case StatucCode::ProxyAuthenticationRequired:   return std::to_string(codeInt) + " Proxy Authentication Required";
        case StatucCode::RequestTimeout:                return std::to_string(codeInt) + " Request Timeout";
        case StatucCode::Conflict:                      return std::to_string(codeInt) + " Conflict";
        case StatucCode::Gone:                          return std::to_string(codeInt) + " Gone";
        case StatucCode::LengthRequired:                return std::to_string(codeInt) + " Length Required";
        case StatucCode::PreconditionFailed:            return std::to_string(codeInt) + " Precondition Failed";
        case StatucCode::PayloadTooLarge:               return std::to_string(codeInt) + " Payload Too Large";
        case StatucCode::URITooLong:                    return std::to_string(codeInt) + " URI Too Long";
        case StatucCode::UnsupportedMediaType:          return std::to_string(codeInt) + " Unsupported Media Type";
        case StatucCode::RangeNotSatisfiable:           return std::to_string(codeInt) + " Range Not Satisfiable";
        case StatucCode::ExpectationFailed:             return std::to_string(codeInt) + " Expectation Failed";
        case StatucCode::ImTeapot:                      return std::to_string(codeInt) + " I'm a Teapot";
        case StatucCode::MisdirectedRequest:            return std::to_string(codeInt) + " Misdirected Request";
        case StatucCode::UnprocessableEntity:           return std::to_string(codeInt) + " Unprocessable Entity";
        case StatucCode::Locked:                        return std::to_string(codeInt) + " Locked";
        case StatucCode::FailedDependency:              return std::to_string(codeInt) + " Failed Dependency";
        case StatucCode::TooEarly:                      return std::to_string(codeInt) + " Too Early";
        case StatucCode::UpgradeRequired:               return std::to_string(codeInt) + " Upgrade Required";
        case StatucCode::PreconditionRequired:          return std::to_string(codeInt) + " Precondition Required";
        case StatucCode::TooManyRequests:               return std::to_string(codeInt) + " Too Many Requests";
        case StatucCode::RequestHeaderFieldsTooLarge:   return std::to_string(codeInt) + " Request Header Fields Too Large";
        case StatucCode::UnavailableForLegalReasons:    return std::to_string(codeInt) + " Unavailable For Legal Reasons";
        case StatucCode::InternalServerError:           return std::to_string(codeInt) + " Internal Server Error";
        case StatucCode::NotImplemented:                return std::to_string(codeInt) + " Not Implemented";
        case StatucCode::BadGateway:                    return std::to_string(codeInt) + " Bad Gateway";
        case StatucCode::ServiceUnavailable:            return std::to_string(codeInt) + " Service Unavailable";
        case StatucCode::GatewayTimeout:                return std::to_string(codeInt) + " Gateway Timeout";
        case StatucCode::HttpVersionNotSupported:       return std::to_string(codeInt) + " HTTP Version Not Supported";
        case StatucCode::VariantAlsoNegotiates:         return std::to_string(codeInt) + " Variant Also Negotiates";
        case StatucCode::InsufficientStorage:           return std::to_string(codeInt) + " Insufficient Storage";
        case StatucCode::LoopDetected:                  return std::to_string(codeInt) + " Loop Detected";
        case StatucCode::NotExtended:                   return std::to_string(codeInt) + " Not Extended";
        case StatucCode::NetworkAuthenticationRequired: return std::to_string(codeInt) + " Network Authentication Required";
    }

    throw std::runtime_error("Cant convert status code to str.");
} 

}

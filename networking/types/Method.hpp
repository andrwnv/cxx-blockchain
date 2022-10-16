#pragma once

#include <cstdint>

namespace networking::types
{

enum class Method
{
    GET,
    POST,
    PUT,
    HEAD,
    DELETE,
    PATCH,
    OPTIONS,
    CONNECT,
    TRACE,
};

namespace strings
{ 
    constexpr const char* GET     = "GET";
    constexpr const char* POST    = "POST";
    constexpr const char* PUT     = "PUT";
    constexpr const char* HEAD    = "HEAD";
    constexpr const char* DELETE  = "DELETE";
    constexpr const char* PATCH   = "PATCH";
    constexpr const char* OPTIONS = "OPTIONS";
    constexpr const char* CONNECT = "CONNECT";
    constexpr const char* TRACE   = "TRACE"; 
}

Method methodFromStr(std::string const& method)
{
    if (method == strings::GET)     return Methods::GET;
    if (method == strings::POST)    return Methods::POST;
    if (method == strings::PUT)     return Methods::PUT;
    if (method == strings::HEAD)    return Methods::HEAD;
    if (method == strings::DELETE)  return Methods::DELETE;
    if (method == strings::PATCH)   return Methods::PATCH;
    if (method == strings::OPTIONS) return Methods::OPTIONS;
    if (method == strings::CONNECT) return Methods::CONNECT;
    if (method == strings::TRACE)   return Methods::TRACE;

    throw std::runtime_error("Cant convert method name to Method");
}

std::string methodToStr(Method const& method)
{
    switch (method)
    {
        case Methods::GET:     return strings::GET;
        case Methods::POST:    return strings::POST;
        case Methods::PUT:     return strings::PUT;
        case Methods::HEAD:    return strings::HEAD;
        case Methods::DELETE:  return strings::DELETE;
        case Methods::PATCH:   return strings::PATCH;
        case Methods::OPTIONS: return strings::OPTIONS;
        case Methods::CONNECT: return strings::CONNECT;
        case Methods::TRACE:   return strings::TRACE;
    }

    throw std::runtime_error("Cant convert Method to str");
}

}

#pragma once

#include <cstdint>
#include <string>

#include "types/Method.hpp"
#include "Content.hpp"

namespace networking
{

class Request
{
public:
    struct Header
    {
        Method method;
        std::string path;
        std::string query;
        std::string httpVersion;
    };

public:
    Request(size_t maxRequestSize, std::string const& remoteAddress = "", uint8_t remotePort = 0);

    const Header&  header()  const noexcept;
    const Content& content() const noexcept;

private:
    Header  _header;
    Content _content;
};

}

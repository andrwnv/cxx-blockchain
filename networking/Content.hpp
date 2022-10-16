#pragma once

namespace networking
{

class Content
{
public:
    size_t size() const noexcept 
    { return _buffer.size(); }

    std::string str() const noexcept 
    { return _buffer; }

private:
    std::string _buffer; // TODO(andrwnv): boost sreambuf
};

}

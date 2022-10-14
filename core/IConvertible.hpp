#pragma once

namespace core
{

template <class T>
class IConvertible
{
public:
    virtual ~IConvertible() = default;

    virtual T convert() const noexcept = 0;
};

} // namespace core

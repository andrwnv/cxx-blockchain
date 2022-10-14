#pragma once

#include <string>

#include <HashTypes.hpp>

namespace core
{

template <
    hash::HashType Type,
    typename HashFormat = hash::HashFormat<Type>::Format
>
class IHashable
{
public:
    virtual ~IHashable() = default;

    virtual HashFormat hash() const noexcept = 0;
};

} // namespace core

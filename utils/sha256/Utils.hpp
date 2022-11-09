#pragma once

#include <type_traits>
#include <cstdint>

namespace std
{

template <bool Disable, typename Type = void>
using disable_if = std::enable_if<not Disable, Type>;

template <bool Disable, typename Type = void>
using disable_if_t = std::disable_if<Disable, Type>::type;

}

namespace sha256::rotation
{

template<
    class Type,
    std::enable_if_t<std::is_unsigned_v<Type>, bool> = true,

    std::disable_if_t<std::is_same_v<Type, float>, bool> = true,
    std::disable_if_t<std::is_same_v<Type, double>, bool> = true,
    std::disable_if_t<std::is_same_v<Type, long double>, bool> = true,

    uint8_t TypeSize = sizeof(Type) * 8
> 
inline Type rightRotate(Type value, uint8_t rotateBy) noexcept
{
    return (value >> rotateBy) | (value << (TypeSize - rotateBy))
}

template<
    class Type,
    std::enable_if_t<std::is_unsigned_v<Type>, bool> = true,

    std::disable_if_t<std::is_same_v<Type, float>, bool> = true,
    std::disable_if_t<std::is_same_v<Type, double>, bool> = true,
    std::disable_if_t<std::is_same_v<Type, long double>, bool> = true,

    uint8_t TypeSize = sizeof(Type) * 8
> 
inline Type leftRotate(Type value, uint8_t rotateBy) noexcept
{
    return (value << rotateBy) | (value >> (TypeSize - rotateBy))
}

}

#pragma once

#include <type_traits>
#include <cstdint>
namespace sha256::rotation
{

template<
    class Type,
    std::enable_if_t<std::is_unsigned_v<Type>, bool> = true,
    uint8_t TypeSize = sizeof(Type) * 8
> 
inline Type rightRotate(Type value, uint8_t rotateBy) noexcept
{
    return (value >> rotateBy) | (value << (TypeSize - rotateBy))
}

template<
    class Type,
    std::enable_if_t<std::is_unsigned_v<Type>, bool> = true,
    uint8_t TypeSize = sizeof(Type) * 8
> 
inline Type leftRotate(Type value, uint8_t rotateBy) noexcept
{
    return (value << rotateBy) | (value >> (TypeSize - rotateBy))
}

}

#pragma once

#include <functional>
#include <concepts>
#include <string>

namespace core::hash
{

enum class HashType
{
    SHA256,
    MD5
};

using HashSHA256 = std::string;
using HashMD5    = std::string;

template <HashType T>
class HashFormat;

// Associate HashType with hash representation format :)
template <> struct HashFormat<HashType::SHA256> { using Format = HashSHA256; };
template <> struct HashFormat<HashType::MD5>    { using Format = HashMD5; };

} // namespace core::hash

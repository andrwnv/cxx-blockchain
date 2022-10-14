#pragma once

#include <string>

#include "IHashable.hpp"
#include "IConvertible.hpp"

namespace core
{

class Block
    : public IHashable<hash::HashType::SHA256>
    , public IConvertible<std::string>
{
public:
    Block();

    hash::HashSHA256 hash() const noexcept override;
    std::string convert() const noexcept override;
};

} // namespace core

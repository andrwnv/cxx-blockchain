#pragma once

#include <array>
#include <string>
#include <memory>
#include <vector>
#include <cstdint>

namespace sha256
{

class Encode
{
public:
    using Hash = std::array<uint8_t, 32>;
    using RawData = std::vector<uint8_t>;

public:
    Encode(RawData const&);
    ~Encode();

    [[nodiscard]] Hash hash() const noexcept;

private:
    using PreprocessedData = std::array<uint8_t, 64>;

    void _preprocess() noexcept;
    void _encode() noexcept;
    void _finalize() noexcept;

    void _compressBlock() noexcept;

private:
    struct Data;
    std::unique_ptr<Data> _data;
};

Encode::RawData toRaw(std::string const& str) noexcept
{ return Encode::RawData(str.cbegin(), str.cend()); }

template <size_t Size>
Encode::RawData toRaw(std::array<uint8_t, Size> const& arr) noexcept
{ return Encode::RawData(arr.cbegin(), arr.cend()); }

}

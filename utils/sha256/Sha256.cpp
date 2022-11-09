#include "Sha256.hpp"

#include "Constants.hpp"

using namespace sha256;

namespace
{

union U32Bytes
{
    struct {
        uint8_t b1;
        uint8_t b2;
        uint8_t b3;
        uint8_t b4;
    };
    uint32_t value = 0x0;
};

uint32_t __unpack(uint32_t pack) noexcept
{
    U32Bytes result;
    result.b1 = static_cast<uint8_t>(pack);
    result.b2 = static_cast<uint8_t>(pack >> 8);
    result.b3 = static_cast<uint8_t>(pack >> 16);
    result.b4 = static_cast<uint8_t>(pack >> 24);
    
    return result.value;
}

uint32_t __pack(uint32_t value) noexcept
{
    U32Bytes bytes; bytes.value = value;
    return static_cast<uint32_t>(bytes.b4) | static_cast<uint32_t>(bytes.b3) | 
           static_cast<uint32_t>(bytes.b2) | static_cast<uint32_t>(bytes.b1);
}

}


struct Encode::Data
{
    Data(Encode::RawData const& source)
        : source(source) {}
    
    Encode::Hash hash;
    Encode::RawData source;

    size_t length = 0;
    size_t totalLength = 0;
};

Encode::~Encode() = default;

Encode::Encode(RawData const& source)
    : _data(std::make_unique<Data>(source))
{
    _preprocess();
    _encode();
    _finalize();
}

Encode::Hash Encode::hash() const noexcept
{
    return _data->hash;
}

void Encode::_preprocess() noexcept
{
    _data->hash.at(0) = static_cast<uint32_t>(InitialHashValue::H0);
    _data->hash.at(1) = static_cast<uint32_t>(InitialHashValue::H1);
    _data->hash.at(2) = static_cast<uint32_t>(InitialHashValue::H2);
    _data->hash.at(3) = static_cast<uint32_t>(InitialHashValue::H3);
    _data->hash.at(4) = static_cast<uint32_t>(InitialHashValue::H4);
    _data->hash.at(5) = static_cast<uint32_t>(InitialHashValue::H5);
    _data->hash.at(6) = static_cast<uint32_t>(InitialHashValue::H6);
    _data->hash.at(7) = static_cast<uint32_t>(InitialHashValue::H7);

    uint32_t block;
}

void Encode::_encode() noexcept
{

}

void Encode::_finalize() noexcept
{

}

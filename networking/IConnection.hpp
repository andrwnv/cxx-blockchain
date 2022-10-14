#pragma once

#include <chrono>

namespace networking
{

class IConnection
{
public:
    virtual ~IConnection() = default;

    virtual void setTimeout(std::chrono::nanoseconds timeout = std::chrono::nanoseconds::zero()) noexcept = 0;
    virtual std::chrono::nanoseconds currentTimeout() const noexcept = 0;

    virtual void stopByTimeout() noexcept = 0;

    virtual void close() noexcept = 0;
};

} // namespace networking

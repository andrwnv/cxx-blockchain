#pragma once

#include <chrono>

namespace networking
{

class IConnection
{
public:
    virtual ~IConnection() = default;

    [[nodiscard]] virtual bool setTimeout(std::chrono::nanoseconds timeout) noexcept = 0;
    [[nodiscard]] virtual std::chrono::nanoseconds currentTimeout() const noexcept = 0;

    virtual void stopByTimeout() noexcept = 0;

    virtual void close() noexcept = 0;
};

} // namespace networking

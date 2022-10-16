#pragma once

#include <chrono>
#include <memory>
#include <mutex>

#include <boost/asio/steady_timer.hpp>
#include <boost/asio/ip/tcp.hpp>

#include "IConnection.hpp"

namespace networking
{

template <typename T> 
concept ISocketType = requires(T t) 
{ 
    t.get_io_service(); 
    t.lowest_layer();
};

template <
    ISocketType SocketType,
    class ...Args
>
class TcpConnection 
    : public IConnection
    , public std::enable_shared_from_this<IConnection>
{
    TcpConnection(Args && ...args)
        : _socket(std::make_unique<SocketType>(std::forward<Args>(args)...))
        , _timer(std::make_unique<Timer>(_socket->get_io_service())) { }

    [[nodiscard]] bool setTimeout(std::chrono::nanoseconds timeout) noexcept override
    {
        if (timeout == std::chrono::nanoseconds::zero())
        {
            auto ptr = _timer.release();
            delete ptr;

            return true;
        }
        
        if (not _socket)
            return false;
        
        _timer = std::make_unique<Timer>(_socket->get_io_service());
        _timer->expires_from_now(timeout);

        auto _this = shared_from_this();
        _timer->async_wait(
            [_this](boost::system::error_code const& errCode) -> void
            {
                if (not errCode)
                    _this->close();
            }
        );
    }

    [[nodiscard]] std::chrono::nanoseconds currentTimeout() const noexcept override
    {
        return _timeout;
    }

    void stopByTimeout() noexcept override
    {
        if (_timer)
        {
            boost::system::error_code code;
            _timer->cancel(code);
        }
    }

    void close() noexcept override
    {
        std::lock_guard<decltype(_onCloseMutex)> lock(_onCloseMutex);
        
        boost::system::error_code code;
        code = _socket->shutdown(boost::asio::ip::tcp::socket::shutdown_both, code);
        _socket->lowest_layer().close(code);
    }

private:
    using Timer = boost::asio::steady_timer;

private:
    std::unique_ptr<SocketType> _socket;

    std::chrono::nanoseconds _timeout {std::chrono::nanoseconds::zero()};
    std::unique_ptr<Timer> _timer;

    std::mutex _onCloseMutex;
};

}

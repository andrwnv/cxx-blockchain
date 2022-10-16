#pragma once

#include <memory>

namespace networking
{

class IConnection;
class Request;

class Session
{
public:
    Session(std::shared_ptr<IConnection> connection, size_t maxBufferSize)
        : _connection(std::move(connection))
    {
        // TODO(andrwnv): wait request impl.   
    }
        
private:
    std::shared_ptr<IConnection> _connection;
    std::shared_ptr<Request>     _request;
};

}


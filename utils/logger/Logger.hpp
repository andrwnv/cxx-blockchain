#pragma once

#include <string_view>
#include <type_traits>
#include <functional>
#include <string>
#include <mutex>

#include <concepts>

namespace logger
{

template <typename T> 
concept IStringConvertible = requires(T t) { std::to_string(t); };

enum class LogLevel
{
    Debug,
    Info,
    Warning,
    Error
};

class LoggerExecutor
{
public:
    LoggerExecutor(LoggerExecutor &&)     = delete;
    LoggerExecutor(LoggerExecutor const&) = delete;

    static LoggerExecutor& instance() noexcept;

    using Executor = std::function<void(LogLevel, std::string_view const&, std::string const&)>;
    static void initExecutor(Executor) noexcept;

    void execute(LogLevel level, std::string_view const& category, std::string const& message) noexcept;

private:
    LoggerExecutor();
    void _initExecutor(Executor) noexcept;

private:
    Executor _executor;

    mutable std::mutex _mutex;
};

template <LogLevel Level>
class Logger
{
public:
    Logger(std::string_view category)
        : _category(std::move(category)) { }

    ~Logger() 
    {
        LoggerExecutor::instance().execute(Level, _category, _message);
    }

    template <IStringConvertible T>
    Logger& operator<<(T const& message)
    {
        message += " " + std::to_string(message);
        return *this;
    }

    Logger& operator<<(const char* message)
    {
        _message += " " + std::string(message);
        return *this;
    }

    Logger& operator<<(std::string const& message)
    {
        _message += " " + message;
        return *this;
    }

    Logger& operator<<(std::string && message)
    {
        _message += " " + message;
        return *this;
    }

private:
    const std::string_view _category;
    std::string _message;
};

using DebugLog   = Logger<LogLevel::Debug>;
using InfoLog    = Logger<LogLevel::Info>;
using WarningLog = Logger<LogLevel::Warning>;
using ErrorLog   = Logger<LogLevel::Error>;

} // namespace logger

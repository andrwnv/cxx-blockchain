#include "Logger.hpp"

#include <iostream>
#include <iomanip>

using namespace logger;

using Executor = LoggerExecutor::Executor;

namespace strings
{
    constexpr std::string_view Debug     = "DEBUG";
    constexpr std::string_view Info      = "INFO";
    constexpr std::string_view Warning   = "WARNING";
    constexpr std::string_view Error     = "ERROR";
    constexpr std::string_view Undefined = "UNDEFINED";
}

constexpr std::string_view levelToStr(LogLevel const& level) noexcept
{
    switch (level)
    {
        case LogLevel::Debug:   return strings::Debug;
        case LogLevel::Info:    return strings::Info;
        case LogLevel::Warning: return strings::Warning;
        case LogLevel::Error:   return strings::Error;
    }

    return strings::Undefined;
}

LoggerExecutor::LoggerExecutor()
{
    std::lock_guard<decltype(_mutex)> lock(_mutex);
    _executor = [](LogLevel level, std::string_view const& category, std::string const& message) noexcept -> void
    {
        std::cout.width(10);
        std::cout << std::setiosflags(std::ios::left) 
                  << levelToStr(level) 
                  << category << ": "
                  << message << std::endl;
    };
}

LoggerExecutor& LoggerExecutor::instance() noexcept
{
    static LoggerExecutor logger;
    return logger;
}

void LoggerExecutor::initExecutor(Executor executor) noexcept
{
    instance()._initExecutor(executor);
}

void LoggerExecutor::_initExecutor(Executor executor) noexcept
{
    std::lock_guard<decltype(_mutex)> lock(_mutex);
    _executor = executor;
}

void LoggerExecutor::execute(LogLevel level, std::string_view const& category, std::string const& message) noexcept
{
    std::lock_guard<decltype(_mutex)> lock(_mutex);
    _executor(level, category, message);
}

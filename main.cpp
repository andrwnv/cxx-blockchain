#include <iostream>

#include <logger/Logger.hpp>

int main(int, char **)
{
    logger::DebugLog("CategoryName")   << "test message";
    logger::InfoLog("CategoryName")    << "test message";
    logger::WarningLog("CategoryName") << "test message";
    logger::ErrorLog("CategoryName")   << "test message";
}

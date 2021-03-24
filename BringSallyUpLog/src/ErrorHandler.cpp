#include "ErrorHandler.h"
#include <iostream>

void ErrorHandler::Log()
{
	std::cout << "[ERR : " << errorCode << "] - " << message << std::endl;
}

ErrorHandler::ErrorHandler(Error code, const char* msg, bool noLog) : errorCode(code), message(msg)
{
    if (errorCode != Error::OK && noLog == false)
    {
        Log();
    }
}


#pragma once


enum Error
{
    OK = 0,
    FAILED_OPERATION,
    NOT_FOUND = 404
};

struct ErrorHandler {


    const char* message;
    Error errorCode = Error::OK;

    void Log();

    ErrorHandler() : errorCode(Error::OK), message("") {}
    ErrorHandler(Error code, const char* msg, bool noLog = false);

    bool operator != (const Error& rhs)
    {
        return errorCode != rhs;
    }

    bool operator == (const Error& rhs)
    {
        return errorCode == rhs;
    }
};
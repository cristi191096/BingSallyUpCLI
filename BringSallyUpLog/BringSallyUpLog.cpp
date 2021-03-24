// BringSallyUpLog.cpp : This file contains the 'main' function. Program execution begins and ends there.
//


#include <vector>
#include <iomanip>
#include <ctime>
#include <chrono>
#include <string>
#include <sstream>

#include "src/Flags.h"
#include "src/ErrorHandler.h"
#include "src/Exercise.h"
#include "src/File.h"
#include "src/Utils.h"
#include "src/Flags.h"

// Main functionality

ErrorHandler ProcessDataFromFile(Exercises& exercises)
{
    std::stringstream stream;
    ErrorHandler errHandle; 

    errHandle = ReadFile(stream);

    if (errHandle != Error::OK)
    {
        return errHandle;
    }

    // Split the file data into lines (\n), Parse the lines, and store them in the out vector.
    size_t start;
    size_t end = 0;

    while ((start = stream.str().find_first_not_of("\n", end)) != std::string::npos)
    {
        end = stream.str().find("\n", start);
        exercises.push_back(ExerciseData(stream.str().substr(start, end - start)));
    }

    return ErrorHandler(Error::OK, "Success");

}

struct ReturnArgData
{
    ErrorHandler    err;
    uint32_t        sets;
    uint32_t        reps;
};

ReturnArgData ProcessArguments(int argc, char** argv, Flags<ArgFlag>& argFlags)
{
    if (strcmp(argv[1], "-h") == 0 || strcmp(argv[1], "--help") == 0)
    {
        argFlags.set(ArgFlag::HELP);
        return { ErrorHandler(Error::OK, "Success"),0,0 };
    }

    uint32_t repCount = 0;
    uint32_t setCount = 0;

    for (uint32_t i = 0; i < argc; i++)
    {
        if (strcmp(argv[i], "--reps") == 0 || strcmp(argv[i], "-r") == 0)
        {
            if (i + 1 >= argc) break;
            repCount = std::atoi(argv[i + 1]);
            argFlags.set(ArgFlag::REPS);
        }
        if (strcmp(argv[i], "--sets") == 0 || strcmp(argv[i], "-s") == 0)
        {
            if (i + 1 >= argc) break;
            setCount = std::atoi(argv[i + 1]);
            argFlags.set(ArgFlag::SETS);
        }
        if (strcmp(argv[i], "--show") == 0 || strcmp(argv[i], "-sh") == 0)
        {
            argFlags.set(ArgFlag::SHOW);
          
        }
    }

    if (argFlags.test(ArgFlag::REPS) && argFlags.test(ArgFlag::SETS))
    {
        return { ErrorHandler(Error::OK, "Success"), setCount, repCount };
    }
    else if(argFlags.test(ArgFlag::SHOW))
    {
        return { ErrorHandler(Error::OK, "Either the number of reps or the number of sets was not set"), 0, 0 };
    }
    else
    {
        const char* msg = argFlags.test(ArgFlag::REPS | ArgFlag::SETS) ? "Either the number of reps or the number of sets was not set" : "Unrecognized arguments please check the options below:";
        return { ErrorHandler(Error::NOT_FOUND, msg), 0, 0 };
    }


}



// main

int main(int argc, char** argv)
{
    Flags<ArgFlag> argFlags;
    ReturnArgData data = ProcessArguments(argc, argv, argFlags);

    if (data.err != Error::OK || argFlags.test(ArgFlag::HELP))
    {
        PrintUsage();
        return 0;
    }

    if (argFlags.test(ArgFlag::REPS | ArgFlag::SETS))
    {
        auto now = std::chrono::system_clock::now();
        auto in_time_t = std::chrono::system_clock::to_time_t(now);

        std::stringstream ss;
        ss << std::put_time(std::localtime(&in_time_t), "[%d/%m/%Y] #%a") << " -s" << data.sets << " -r" << data.reps;

        WriteFile(ss.str());

        PrintSuccessFeedback();
    }

    if (argFlags.test(ArgFlag::SHOW))
    {
        Exercises ex;
        ProcessDataFromFile(ex);
        PrintLogs(ex);
    }


}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file

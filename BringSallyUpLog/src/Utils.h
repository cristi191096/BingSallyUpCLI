#pragma once

#include <iostream>
#include "ErrorHandler.h"
#include "Exercise.h"

void PrintLogs(const Exercises& exercises)
{
    if (exercises.empty())
    {
        ErrorHandler(Error::NOT_FOUND, "No Logs found in log.txt");
        return;
    }
    std::cout << std::endl << "=============================| LOGS |==============================" << std::endl;
    std::cout << "\tDate\t | \tDay\t | \tSets\t | \tReps" << std::endl;

    std::cout << "===================================================================" << std::endl;

    for (uint32_t i = 0; i < exercises.size(); i++)
    {
        std::cout << exercises[i].date << "\t | \t" << exercises[i].weekDay << "\t | \t" << exercises[i].sets << "\t | \t" << exercises[i].reps << std::endl;
    }
    std::cout << "===================================================================" << std::endl << std::endl;
    std::cout << "Total Workouts : " << exercises.size() << std::endl;
}

void PrintUsage()
{
    std::cout << std::endl << "====================| HELP |====================" << std::endl;
    std::cout << "1. [-r] / [--reps] \t -> \t Add the number of reps per set." << std::endl;
    std::cout << "2. [-s] / [--sets] \t -> \t Add the number of sets to the current workout." << std::endl;
    std::cout << "3. [-sh] / [--show] \t -> \t Print the options." << std::endl;
    std::cout << "4. [-h] / [--help] \t -> \t Print the options." << std::endl;
    std::cout << "=================| KEEP PUSHING |=================" << std::endl;
}

void PrintUnhandledArgs()
{
    std::cout << "Unrecognized arguments please check the options below:" << std::endl;
    PrintUsage();
}

void PrintSuccessFeedback()
{
    std::cout << "Workout logged successfully!" << std::endl;
}
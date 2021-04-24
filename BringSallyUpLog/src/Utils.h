#pragma once

#include <iostream>
#include <cstdio>
#include <stdlib.h>
#include <thread>
#include <chrono>
#include "ErrorHandler.h"
#include "Exercise.h"
#include "color_console.h"
//
//#pragma warning(disable:4717)

void PrintLogs(const Exercises& exercises)
{
    if (exercises.empty())
    {
        ErrorHandler(Error::NOT_FOUND, "No Logs found in log.txt");
        return;
    }

    std::cout << "Loading..." << std::endl;
    for (int i = 0; i < 100; i++)
    {
        std::this_thread::sleep_for(std::chrono::milliseconds(30));
        std::cout << std::to_string(i+1).c_str() << "%" << "\r" << std::flush;
    }

    std::cout << std::endl << "=============================| LOGS |==============================" << std::endl;
    std::cout << "\tDate\t | \tDay\t | \tSets\t | \tReps" << std::endl;

    std::cout << "===================================================================" << std::endl;

    int deltaSets = 0, deltaReps = 0;

    for (uint32_t i = 0; i < exercises.size(); i++)
    {
        if (i > 0)
        {
            deltaSets = std::atoi(exercises[i].sets.c_str()) - std::atoi(exercises[i - 1].sets.c_str());
            deltaReps = std::atoi(exercises[i].reps.c_str()) - std::atoi(exercises[i - 1].reps.c_str());
        }
        std::cout << exercises[i].date << "\t | \t";
        std::cout << exercises[i].weekDay << "\t | \t";

        if (deltaSets > 0)
        {
            std::cout << exercises[i].sets << Color::Green << " (+" << deltaSets << ")" << reset << "\t | \t";
        }
        else if (deltaSets < 0)
        {
            std::cout << exercises[i].sets << Color::Red <<  " (" << deltaSets << ")" << reset << "\t | \t";
        }
        else
        {
            std::cout << exercises[i].sets << Color::Yellow << " (--)" << reset << "\t | \t";
        }

        if (deltaReps > 0)
        {
            std::cout << exercises[i].reps << Color::Green << " (+" << deltaReps << ")" << reset << "\t | \t";
        }
        else if (deltaReps < 0)
        {
            std::cout << exercises[i].reps << Color::Red << " (" << deltaReps << ")" << reset << "\t | \t";
        }
        else
        {
            std::cout << exercises[i].reps << Color::Yellow << " (--)" << reset << "\t | \t";
        }
        std::cout << std::endl;
    }
    std::cout << "===================================================================" << std::endl << std::endl;
    std::cout << "Total Workouts : " << Color::Green << exercises.size() << reset << std::endl;
}

void PrintToken(const Exercises& exercises)
{
    if (exercises.empty())
    {
        ErrorHandler(Error::NOT_FOUND, "No Logs found in log.txt");
        return;
    }

    std::string out;

    for (uint32_t i = 0; i < exercises.size(); i++)
    {
        out += exercises[i].date + "|" + exercises[i].weekDay + "|" + exercises[i].sets + "|" + exercises[i].reps + "#";
    }
    out.pop_back();
    std::cout << out;
}

void PrintUsage()
{ 
 
    std::cout << std::endl <<"====================| HELP |====================" << reset << std::endl;

    
    std::cout << "1. [-r] / [--reps] \t -> \t Add the number of reps per set." << std::endl;
    std::cout << "2. [-s] / [--sets] \t -> \t Add the number of sets to the current workout." << std::endl;
    std::cout << "3. [-sh] / [--show] \t -> \t Display logs." << std::endl;
    std::cout << "4. [-gt] / [--getToken]  -> \t Get a token version of the logs printed on the screen." << std::endl;
    std::cout << "5. [-h] / [--help] \t -> \t Print the options." << std::endl;
    std::cout << "=================| KEEP PUSHING |=================" << std::endl;


    std::cout << "\033[1;31mbold red text\033[0m\n";



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
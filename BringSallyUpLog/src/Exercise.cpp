#include "Exercise.h"

ExerciseData::ExerciseData(const std::string& data)
{
    std::size_t token = data.find("]");

    if (token != std::string::npos)
    {
        date = data.substr(token - 10, token - 1);
    }

    token = data.find("#");

    if (token != std::string::npos)
    {
        weekDay = data.substr(token + 1, 3);
    }

    token = data.find("-s");

    if (token != std::string::npos)
    {
        sets = data.substr(token + 2, 2);
    }
    token = data.find("-r");

    if (token != std::string::npos)
    {
        reps = data.substr(token + 2);
    }
}

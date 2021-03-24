#pragma once
#include <string>
#include <vector>

struct ExerciseData
{
    std::string date, weekDay, sets, reps;

    ExerciseData(const std::string& data);      // Format : [DD/MM/YYYY] #MON -s3 -r10
};

typedef std::vector<ExerciseData> Exercises;
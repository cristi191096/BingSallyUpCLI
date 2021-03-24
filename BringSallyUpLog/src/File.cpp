#include "File.h"
#include <iostream>
#include <fstream>

ErrorHandler WriteFile(std::string log)
{
    std::ofstream file(LOG_FILE, std::ios_base::app);
    if (file.is_open())
    {
        file << log << "\n";
        file.close();

        return ErrorHandler(Error::OK, "Success");
    }

    return ErrorHandler(Error::FAILED_OPERATION, "Failed to open the file for write");

}

ErrorHandler ReadFile(std::stringstream& stream)
{
    std::string line;
    std::ifstream file(LOG_FILE);
    if (file.is_open())
    {
        while (std::getline(file, line))
        {
            stream << line << "\n";
        }
        file.close();
        return ErrorHandler(Error::OK, "Success");
    }

    return ErrorHandler(Error::FAILED_OPERATION, "Failed to open the file for read");
}


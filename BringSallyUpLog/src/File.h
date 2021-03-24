#pragma once

#include <string>
#include <sstream>
#include "ErrorHandler.h"

#define LOG_FILE                   R"(log.txt)"

ErrorHandler WriteFile(std::string log);
ErrorHandler ReadFile(std::stringstream& stream);

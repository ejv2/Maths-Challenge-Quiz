/* Maths challenge quiz
   Copyright Ethan Marshall - 2019

   Licensed under the GPL V.3.0
*/

#include <string>
#include <algorithm>
#include <cstdlib>
#include <iostream>
#include <chrono>
#include <thread>
#include <cctype>
#include <math.h>

#include "Startup.h"

namespace util
{

std::string getSemanticVersion(int major, int minor, int build)
{
    std::string majorS = std::to_string(major);
    std::string minorS = std::to_string(minor);
    std::string buildS = std::to_string(build);

    return majorS + "." + minorS + "." + buildS;
}

void stringLower(std::string *str)
{
    std::string data = *str;
    std::transform(data.begin(), data.end(), data.begin(),
                   [](unsigned char c) { return std::tolower(c); });

    *str = data;
}

bool isValidNumber(std::string str)
{
    try
    {
        int num = std::stoi(str);
        return true;
    }
    catch (std::invalid_argument)
    {
        return false;
    }
}

void sleep(int seconds)
{
    std::this_thread::sleep_for(std::chrono::milliseconds(seconds * 1000));
}

void setupRandomSeed()
{
    std::srand(time(NULL));
}

void exitProgram(int exitCode, std::string message)
{
    std::string exitMessage = (message == "") ? "Maths Challenge Quiz exiting..." : message;

    std::cout << std::endl;
    std::cout << exitMessage;
}

/* ALERT - HACKY METHOD WARNING
   
   This method is a quick, dirty method of clearing the screen that should never be used
   in a real application.

   However, this is currently the best method available to me that does what I want

*/
void clearScreen()
{
#ifdef COMP_WINDOWS
    system("cls");
#else
    system("clear");
#endif
}

double roundDecimalPlaces(double d0, int dp)
{
    double factor = (double)std::pow(10, dp);
    return (int)(d0 * factor) / factor;
}

} // namespace util
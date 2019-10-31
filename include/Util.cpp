/* Maths challenge quiz
   Copyright Ethan Marshall - 2019

   Licensed under the GPL V.3.0
*/

#include <string>
#include <cstdlib>
#include <iostream>
#include <chrono>
#include <thread>

#include "Startup.h"

namespace util
{

void stringLower(std::string *str)
{
    int len = str->length();
    std::string string = *str;

    for (int i = 0; i < len; i++)
    {
        str[i] = std::tolower(string[i]);
    }
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
    // Due to compiler complications, this method is not compiled when compiling for windows
#ifndef COMP_WINDOWS
    std::this_thread::sleep_for(std::chrono::milliseconds(seconds * 1000));
#endif
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

} // namespace util
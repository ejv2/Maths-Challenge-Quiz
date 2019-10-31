/* Maths challenge quiz
   Copyright Ethan Marshall - 2019

   Licensed under the GPL V.3.0
*/

#include <string>
#include <cstdlib>

#ifndef UTIL_HEADER
#define UTIL_HEADER

namespace util
{

void stringLower(std::string *str);

bool isValidNumber(std::string str);

void sleep(int seconds);

void setupRandomSeed();

void exitProgram(int exitCode, std::string message);

void clearScreen();

} // namespace util

#endif // End header
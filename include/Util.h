/* Maths challenge quiz
   Copyright Ethan Marshall - 2019

   Licensed under the GPL V.3.0
*/

#include <string>
#include <vector>
#include <cstdlib>

#ifndef UTIL_HEADER
#define UTIL_HEADER

namespace util
{

   std::string getSemanticVersion(int major, int minor, int build);

   void stringLower(std::string *str);
   std::vector<std::string> split(const std::string &s, char delimiter);

   bool isValidNumber(std::string str);

   void sleep(int seconds);

   void setupRandomSeed();

   void exitProgram(int exitCode, std::string message);

   void clearScreen();

   double roundDecimalPlaces(double d0, int dp);
} // namespace util

#endif // End header
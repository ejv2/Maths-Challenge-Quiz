/* Maths challenge quiz
   Copyright Ethan Marshall - 2019

   Licensed under the GPL V.3.0
*/

#include <vector>
#include <string>

#ifndef STARTUP_HEADER
#define STARTUP_HEADER

namespace startup
{

struct startup_information
{
    std::string name = "";
    unsigned int difficulty = 1;
    bool first = false;
};

std::vector<std::string> *parseCmdLine(char *argv[], int count);
void handleCmdLine(std::vector<std::string> *cmds);

void handleStartQuestions(startup_information *info);

void haltPreGame();

void printWelcome();
void printCopyright();
void printHelp();

} // namespace startup

#endif // End header
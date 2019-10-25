/* Maths challenge quiz
   Copyright Ethan Marshall - 2019

   Licensed under the GPL V.3.0
*/

#include <iostream>
#include <cstring>
#include <string>
#include <cmath>
#include <vector>

#include "include/Constants.h"
#include "include/Startup.h"
#include "include/Util.h"
#include "include/Round.h"

using namespace gameround;
using namespace std;

int main(int argc, char *argv[])
{
    // Setup random behaviour seed based on system time
    util::setupRandomSeed();

    vector<string> *parsedArgs = startup::parseCmdLine(argv, argc);
    startup::handleCmdLine(parsedArgs);

    startup::printWelcome();

    startup::startup_information info;
    startup::handleStartQuestions(&info);

    startup::haltPreGame();

    // Main game loop
    while (true)
    {

        // Round setup
        GameRound *currentround = new GameRound();
        RoundType rt = currentround->selectRoundType();
        int questionCount = currentround->selectQuestionAmount();

        util::sleep(5);
        break;
    }

    return 0;
}
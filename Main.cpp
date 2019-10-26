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

    PreviousRound prevRound = {
        RoundType::arithmetic,
        false,
    };

    // Main game loop
    while (true)
    {

        // Round setup
        GameRound *currentRound = new GameRound(prevRound);
        RoundType rt = currentRound->selectRoundType();
        int questionCount = currentRound->selectQuestionAmount();

        // START OF ROUND
        while (!currentRound->isRoundOver())
        {
        }

        // END OF ROUND

        // Fill in the prevRound information
        currentRound->getRoundInfo(&prevRound);

        // TODO: Fill in failure detection

        // Free the current round
        delete currentRound;
    }

    return 0;
}
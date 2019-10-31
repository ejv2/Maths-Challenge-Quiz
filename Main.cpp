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
#include "include/Scoring.h"
#include "include/GameOver.h"

using namespace gameround;
using namespace game_over;
using namespace std;

static PreviousRound prevRound = {
    RoundType::arithmetic,
    false,
};

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

        GameRound *currentRound = new GameRound(prevRound, info.difficulty);

        // ==================== [START OF ROUND] ====================

        while (!currentRound->isRoundOver())
        {

            float ans = currentRound->askQuestion();
            bool correct = currentRound->verifyAnswer(ans);
            currentRound->creditAnswer(correct);
        }

        // ==================== [END OF ROUND] ====================

        // Fill in the previous round's information
        currentRound->getRoundInfo(&prevRound);

        if (!scoring::shouldPassRound(currentRound))
        {
            scoring::run_roundFailureCutscene();
            scoring::displayResults();
            break;
        }

        currentRound->runInterlude();

        // Free the current round
        delete currentRound;

        std::memset(currentRound, 0, sizeof(GameRound));
    }

    // When we reach this point, the game is over
    gameExiting();

    return 0;
}
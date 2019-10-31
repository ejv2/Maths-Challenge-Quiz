/* Maths challenge quiz
   Copyright Ethan Marshall - 2019

   Licensed under the GPL V.3.0
*/

#include "Scoring.h"
#include "Round.h"
#include "Util.h"
#include "Constants.h"

#include <iostream>
#include <string>

#define QUICK_PRINT(msg)      \
    std::cout << msg << "\n"; \
    std::cout.flush();

namespace scoring
{

bool shouldPassRound(gameround::GameRound *round)
{
#if ALWAYS_PASS != true

    if (round->type == gameround::RoundType::skip)
        return true;

    double percentCorrect = round->getPercentCorrect();
    float requiredPercent = 0.5 + ((round->difficulty / 10) - 0.1);

    return percentCorrect >= requiredPercent;
#else
    return true;
#endif
}

void run_roundFailureCutscene()
{
    util::clearScreen();
    std::cout.flush();

    QUICK_PRINT("Your result that round was...");
    util::sleep(3.5);

    QUICK_PRINT("Unsatisfactory");
    util::sleep(5);

    util::clearScreen();
    QUICK_PRINT("The penalty is...");
    util::sleep(3);

    QUICK_PRINT("Failure");
    util::sleep(5);

    util::clearScreen();
    QUICK_PRINT("Goodbye");
    util::sleep(5);

    util::clearScreen();
    std::cout.flush();
}

void displayResults()
{
    // TODO: Implement result showing
}

OverallResult getFinalResult(int point, int rounds)
{
}

} // namespace scoring
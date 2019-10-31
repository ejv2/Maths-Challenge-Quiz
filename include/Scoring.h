/* Maths challenge quiz
   Copyright Ethan Marshall - 2019

   Licensed under the GPL V.3.0
*/

#ifndef SCORING_HEADER
#define SCORING_HEADER

#include "Round.h"

namespace scoring
{

enum OverallResult
{
    awful = 0,
    bad = 1,
    ok = 2,
    good = 3,
    great = 4,
    perfect = 5

};

bool shouldPassRound(gameround::GameRound *round);

void run_roundFailureCutscene();
void displayResults();

OverallResult getFinalResult(int points, int rounds);

} // namespace scoring

#endif
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

const std::string resultMessages[6] = {"Awful",
                                       "Bad",
                                       "Ok",
                                       "Good",
                                       "Great",
                                       "Perfect"};

struct GameStatus
{
    int rounds_completed = 0;
    int overall_points = 0;
    int questions_answered = 0;

    double percent_correct;
};

bool shouldPassRound(gameround::GameRound *round);

void run_roundFailureCutscene();
void displayResults(GameStatus state, int difficulty);
void resultAcceptance(int difficulty);

OverallResult getFinalResult(int points, int rounds);

void processGameStatus(GameStatus *state, gameround::GameRound *round);

} // namespace scoring

#endif
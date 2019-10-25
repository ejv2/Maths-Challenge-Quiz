/* Maths challenge quiz
   Copyright Ethan Marshall - 2019

   Licensed under the GPL V.3.0
*/

#ifndef ROUND_HEADER
#define ROUND_HEADER

namespace gameround
{

enum RoundType
{
    arithmetic = 0,
    multiplication = 1,
    division = 2,
    speed = 3,
    skip = 4
};

class GameRound
{

public:
    GameRound();
    ~GameRound();

    int current_question[1];
    RoundType type;

    RoundType selectRoundType();
    const int selectQuestionAmount();

private:
    int difficulty;
    int question_amount;
    int question_bounds;

    bool previousSkipRound = false;
    bool invalidRound = false;
    bool showInterlude = true;
};

} // namespace round

#endif // End header
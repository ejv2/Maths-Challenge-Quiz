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

struct PreviousRound
{
    RoundType previousType = arithmetic;
    bool previousSkip = false;
};

class GameRound
{

public:
    GameRound(PreviousRound prevround);
    ~GameRound();

    int current_question[1];
    RoundType type;

    RoundType selectRoundType();
    const int selectQuestionAmount();

    bool isRoundOver();

    void getRoundInfo(PreviousRound *prevRound);

private:
    int difficulty;
    int question_amount;
    int question_bounds;

    int points;
    float percent_correct;

    bool previousSkipRound = false;
    bool invalidRound = false;
    bool showInterlude = true;
};

} // namespace gameround

#endif // End header
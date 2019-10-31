/* Maths challenge quiz
   Copyright Ethan Marshall - 2019

   Licensed under the GPL V.3.0
*/

#include <string>

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

enum OperandType
{
    add = 0,
    sub = 1,
    mult = 2,
    div = 3
};

struct PreviousRound
{
    int previousType = arithmetic;
    bool previousSkip = false;
};

static const std::string intro_texts[5] = {"Arithmetic round\n\nAdd or subtract the numbers shown to gain points. Incorrect answers may result in an unsatisfactory mark on your official testing record.",
                                           "Multiplication round\n\nMultiply the numbers shown to gain points.\nIncorrect answers will result in permanent data loss and system destruction.",
                                           "Division round\n\nDivide the numbers shown to gain points\nIn the case of a non-whole answer, you may truncate the decimal to a whole.",
                                           "Speed round\n\nYou will be asked regular multiplication questions, but the speed at which you answer will be measured.\nPoints will be awarded for fast answers, but slow answers may result in deduction.",
                                           "Skip round\n\nYou have been blessed with a skip round\nYou will not be asked any questions for 10 seconds\nRegular questions will resume next round."};

static const int bounds[6][5] = {{2, 2, 2, 2, 0},
                                 {100, 12, 12, 12, 0},
                                 {250, 20, 15, 15, 0},
                                 {1000, 25, 25, 20, 0},
                                 {1000, 50, 50, 25, 0},
                                 {100000000, 100000000, 100000000, 100000000, 100000000}};

class GameRound
{

public:
    GameRound(PreviousRound prevround, int difficulty);
    ~GameRound();

    int difficulty;

    int current_question[2];
    std::string current_question_string;
    int type;

    RoundType getRoundType();
    const int getQuestionAmount();

    double getPercentCorrect();

    bool isRoundOver();
    void runInterlude();

    float askQuestion();
    bool verifyAnswer(float answer);
    void creditAnswer(bool correct);

    void getRoundInfo(PreviousRound *prevRound);
    int getPoints();

private:
    void handleSpeedReward();
    void generateQuestion();

    void setupSkipRound();
    void runSkipRound();

    void runSpeedIntro();

    std::string getIntroText();
    std::string getOperatorString();

    int question_amount;
    int question_bounds;

    int question_number;
    int question_time;

    int points;

    bool previousSkipRound = false;
    bool invalidRound = false;
    bool showInterlude = true;
};

} // namespace gameround

#endif // End header
/* Maths challenge quiz
   Copyright Ethan Marshall - 2019

   Licensed under the GPL V.3.0
*/

#include "Round.h"

#include <string>

#ifndef BASE_ROUND
#define BASE_ROUND

namespace gameround
{

class BaseRound
{
public:
    BaseRound(PreviousRound previousRound);
    ~BaseRound();

    virtual double askQuestion() = 0;
    virtual void handleAnswer(double answer) = 0;

    virtual bool isRoundOver();
    virtual bool questionsRequired() = 0;

    virtual void runIntro() = 0;
    virtual void runInterlude();

    virtual int getPoints();
    virtual bool shouldPassRound();

    void updateGameState(PreviousRound *prevRound);

private:
    int difficulty;

    int points;

    int amount_questions;
    int current_question_number;

    double currentQuestion[2];

    bool previousSkipRound = false;
    bool invalidRound = false;
    bool showInterlude = true;

    virtual bool checkRoundValidity();

    virtual inline std::string getRoundName() = 0;
    virtual inline std::string getIntroText() = 0;

    virtual bool verifyAnswer() = 0;

    virtual inline std::string getOperator() = 0;
    virtual std::string getQuestionString() = 0;

    virtual void generateQuestion();
};

} // namespace gameround

#endif
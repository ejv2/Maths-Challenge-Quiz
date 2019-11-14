/* Maths challenge quiz
   Copyright Ethan Marshall - 2019

   Licensed under the GPL V.3.0
*/

#include "BaseRound.h"

#ifndef ARITHMETIC_ROUND
#define ARITHMETIC_ROUND

namespace gameround
{

class ArithmeticRound : public BaseRound
{

public:
    ArithmeticRound();
    ~ArithmeticRound();

    double askQuestion() override;
    void handleAnswer(double answer) override;

    bool isRoundOver() override;
    bool questionsRequired() override;

    void runIntro() override;
    void runInterlude() override;

private:
    bool checkRoundValidity() override;

    inline std::string getRoundName() override;
    inline std::string getIntroText() override;

    bool verifyAnswer() override;

    inline std::string getOperator() override;
    std::string getQuestionString() override;

    double generateQuestion() override;
};

} // namespace gameround

#endif
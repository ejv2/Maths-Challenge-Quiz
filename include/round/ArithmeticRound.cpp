/* Maths challenge quiz
   Copyright Ethan Marshall - 2019

   Licensed under the GPL V.3.0
*/

#include "ArithmeticRound.h"

namespace gameround
{

ArithmeticRound::ArithmeticRound(PreviousRound *prevround)
{
}

ArithmeticRound::~ArithmeticRound()
{
}

double ArithmeticRound::askQuestion()
{
}

void ArithmeticRound::handleAnswer(double answer)
{
}

bool ArithmeticRound::isRoundOver()
{
    BaseRound::isRoundOver();
}

bool ArithmeticRound::questionsRequired()
{
    return true;
}

void ArithmeticRound::runIntro()
{
}

void ArithmeticRound::runInterlude()
{
}

int ArithmeticRound::getRoundType()
{
    return RoundType::arithmetic;
}

int ArithmeticRound::getSize()
{
    return sizeof(ArithmeticRound);
}

bool ArithmeticRound::checkRoundValidity()
{
    return true;
}

inline std::string ArithmeticRound::getRoundName()
{
    return "Arithmetic round";
}

inline std::string ArithmeticRound::getIntroText()
{
    return "Add or subtract the displayed numbers to gain points\nInaccurate answers will result in an unsatisfactory mark on your official testing record.\nGood luck!";
}

bool ArithmeticRound::verifyAnswer(double answer)
{
}

inline std::string ArithmeticRound::getOperator()
{
}

std::string ArithmeticRound::getQuestionString()
{
}

void ArithmeticRound::generateQuestion()
{
}

} // namespace gameround
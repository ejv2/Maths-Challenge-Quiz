/* Maths challenge quiz
   Copyright Ethan Marshall - 2019

   Licensed under the GPL V.3.0
*/

#include "BaseRound.h"
#include "../Util.h"
#include "../Scoring.h"
#include "Round.h"

#include <iostream>

namespace gameround
{

BaseRound::BaseRound(PreviousRound previousRound)
{
}

BaseRound::BaseRound()
{
}

BaseRound::~BaseRound()
{
}

double BaseRound::askQuestion()
{
}

void BaseRound::handleAnswer(double answer)
{
}

bool BaseRound::isRoundOver()
{
    return (this->current_question_number >= this->amount_questions);
}

bool BaseRound::questionsRequired()
{
    return true;
}

void BaseRound::runInterlude()
{

    util::clearScreen();

    std::cout << "You have completed this round";
    std::cout << "The next round will begin shortly...";
    std::cout << "This round's points total: " << this->points;
}

void BaseRound::runIntro()
{
}

int BaseRound::getPoints()
{
    return this->points;
}

double BaseRound::getPercentCorrect()
{
    return this->points / this->amount_questions;
}

int BaseRound::getRoundType()
{
    return RoundType::arithmetic;
}

bool BaseRound::shouldPassRound()
{
    return ((this->points / this->amount_questions) > 0.5);
}

bool BaseRound::checkRoundValidity()
{
    return true;
}

void BaseRound::generateQuestion()
{
    this->currentQuestion[0] = 1;
    this->currentQuestion[1] = 1;
}

void BaseRound::updateGameState(scoring::GameStatus *status)
{
    status->rounds_completed++;
    status->questions_answered += this->amount_questions;

    status->overall_points += this->points;

    status->percent_correct = (status->overall_points / status->questions_answered) * 100;
}

void BaseRound::getRoundInfo(PreviousRound *prevround)
{
    prevround->previousType = this->getRoundType();
    prevround->previousSkip = (this->getRoundType() == RoundType::skip);
}

int BaseRound::getSize()
{
    return sizeof(BaseRound);
}

inline std::string BaseRound::getRoundName()
{
}

inline std::string BaseRound::getIntroText()
{
}

bool BaseRound::verifyAnswer(double answer)
{
}

inline std::string BaseRound::getOperator()
{
}

std::string BaseRound::getQuestionString()
{
}

} // namespace gameround
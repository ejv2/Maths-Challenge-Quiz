/* Maths challenge quiz
   Copyright Ethan Marshall - 2019

   Licensed under the GPL V.3.0
*/

#include "BaseRound.h"
#include "../Util.h"
#include "../Scoring.h"
#include "../Constants.h"
#include "../Startup.h"
#include "Round.h"

#include <iostream>
#include <math.h>

using namespace startup;

namespace gameround
{

BaseRound::BaseRound(PreviousRound previousRound, startup_information info)
{
}

BaseRound::BaseRound()
{
    util::clearScreen();
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
    return (this->current_question_number > this->amount_questions);
}

bool BaseRound::questionsRequired()
{
    return true;
}

void BaseRound::runInterlude()
{

    util::clearScreen();

    std::cout << "You have completed this round\n";
    std::cout << "The next round will begin shortly...\n\n";

    std::cout << "This round's points total: " << this->points << "\n";
    std::cout << "Percentage of answers correct: " << std::floor(this->getPercentCorrect() * 100) << "%\n";

    util::sleep(5);
}

void BaseRound::runIntro()
{
    std::cout << "[INSERT ROUND NAME HERE]\n";
    std::cout << "[INSERT ROUND DESCRIPTION HERE]\n";
    std::cout << "You will answer " << this->amount_questions << " questions this round\n";
    std::cout << "Good luck!\n\n";
}

int BaseRound::getPoints()
{
    return this->points;
}

double BaseRound::getPercentCorrect()
{
    return (double)this->points / (double)this->amount_questions;
}

int BaseRound::getRoundType()
{
    return RoundType::arithmetic;
}

bool BaseRound::shouldPassRound()
{
    return (((double)this->points / (double)this->amount_questions) >= 0.5);
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

    status->percent_correct = ((double)status->overall_points / (double)status->questions_answered) * 100;
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
    return "[INSERT ROUND NAME HERE]";
}

inline std::string BaseRound::getIntroText()
{
    return "[INSERT DESCRIPTION HERE]";
}

bool BaseRound::verifyAnswer(double answer)
{
}

inline std::string BaseRound::getOperator()
{
    return "?";
}

std::string BaseRound::getQuestionString()
{
}

int BaseRound::getMaxQuestions()
{
    return BASE_MAX_QUESTIONS;
}

int BaseRound::getMaxQuestionValue()
{
    return 100;
}

} // namespace gameround
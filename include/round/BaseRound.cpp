/* Maths challenge quiz
   Copyright Ethan Marshall - 2019

   Licensed under the GPL V.3.0
*/

#include "BaseRound.h"
#include "../Util.h"
#include "Round.h"

#include <iostream>

namespace gameround
{

bool BaseRound::isRoundOver()
{
    return (this->current_question_number >= this->amount_questions);
}

void BaseRound::runInterlude()
{

    util::clearScreen();

    std::cout << "You have completed this round";
    std::cout << "The next round will begin shortly...";
    std::cout << "This round's points total: " << this->points;
}

int BaseRound::getPoints()
{
    return this->points;
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

} // namespace gameround
/* Maths challenge quiz
   Copyright Ethan Marshall - 2019

   Licensed under the GPL V.3.0
*/

#include "SkipRound.h"
#include "../Constants.h"
#include "../Startup.h"
#include "../Util.h"

#include <iostream>
#include <string>

using namespace startup;

namespace gameround
{

SkipRound::SkipRound(PreviousRound *prevround, startup_information info)
{

    this->difficulty = info.difficulty;
    this->current_question_number = 1;
    this->points = 0;

    this->currentQuestion[0] = 1;
    this->currentQuestion[1] = 1;

    this->amount_questions = std::rand() % this->getMaxQuestions() + 1;

    this->skipEnded = false;

    this->runIntro();
    this->runSkip();
}

SkipRound::~SkipRound()
{
}

bool SkipRound::isRoundOver()
{
    return this->skipEnded;
}

bool SkipRound::questionsRequired()
{
    return true;
}

bool SkipRound::shouldPassRound()
{
    return true;
}

void SkipRound::runIntro()
{
    std::cout << this->getRoundName() << "\n";
    std::cout << this->getIntroText() << "\n\n";
}

void SkipRound::runInterlude()
{
    util::clearScreen();
}

int SkipRound::getRoundType()
{
    return RoundType::skip;
}

int SkipRound::getSize()
{
    return sizeof(SkipRound);
}

bool SkipRound::checkRoundValidity()
{
    return true;
}

inline std::string SkipRound::getRoundName()
{
    return "Skip round";
}

inline std::string SkipRound::getIntroText()
{
    return "You have been blessed with a skip round\nYou will not be asked any questions for 10 seconds\nRegular questions will resume next round.";
}

inline std::string SkipRound::getOperator()
{
    return " ";
}

void SkipRound::runSkip()
{
    for (int i = 1; i < SKIP_ROUND_TIME; i++)
    {
        std::cout << i << "\n";
        std::cout.flush();
        util::sleep(1);
    }

    this->skipEnded = true;

    std::cout << "Questions resuming now...";
    std::cout.flush();
    util::sleep(2);
}

} // namespace gameround
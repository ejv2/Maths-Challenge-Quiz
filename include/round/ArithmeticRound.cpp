/* Maths challenge quiz
   Copyright Ethan Marshall - 2019

   Licensed under the GPL V.3.0
*/

#include "ArithmeticRound.h"
#include "../Constants.h"
#include "../Startup.h"

#include <iostream>
#include <string>

using namespace startup;

namespace gameround
{

ArithmeticRound::ArithmeticRound(PreviousRound *prevround, startup_information info)
{
    this->roundType = RoundType::arithmetic;

    this->difficulty = info.difficulty;
    this->current_question_number = 1;
    this->points = 0;
    this->current_operator = "+";

    this->currentQuestion[0] = 1;
    this->currentQuestion[1] = 1;

    this->amount_questions = std::rand() % this->getMaxQuestions() + 1;

    this->runIntro();
}

ArithmeticRound::~ArithmeticRound()
{
}

double ArithmeticRound::askQuestion()
{

    this->current_question_number++;

    this->generateQuestion();

    std::cout << "Enter the answer to " << this->getQuestionString() << ":";

    std::string givenAnswer;
    std::getline(std::cin, givenAnswer);

    double answer;
    try
    {
        answer = std::stod(givenAnswer);
    }
    catch (std::invalid_argument)
    {
        return INVALID_ANSWER;
    }

    return answer;
}

void ArithmeticRound::handleAnswer(double answer)
{
    if (answer == INVALID_ANSWER)
    {
        std::cout << "Invalid answer\n\n";
        return;
    }

    if (this->verifyAnswer(answer))
    {
        std::cout << "Correct\n\n";

        this->points++;
    }
    else
    {
        std::cout << "Incorrect\n\n";
    }
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
    std::cout << this->getRoundName() << "\n";
    std::cout << this->getIntroText() << "\n";
    std::cout << "You will answer " << this->amount_questions << " questions this round\n";
    std::cout << "Good luck!\n\n";
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
    return "Add or subtract the displayed numbers to gain points\nInaccurate answers will result in an unsatisfactory mark on your official testing record";
}

bool ArithmeticRound::verifyAnswer(double answer)
{
    if (this->current_operator == "+")
    {
        return answer == (this->currentQuestion[0] + this->currentQuestion[1]);
    }
    else
    {
        return answer == (this->currentQuestion[0] - this->currentQuestion[1]);
    }
}

inline std::string ArithmeticRound::getOperator()
{
    return this->current_operator;
}

std::string ArithmeticRound::getQuestionString()
{
    std::string str0 = std::to_string((int)this->currentQuestion[0]);
    std::string str1 = std::to_string((int)this->currentQuestion[1]);

    std::string final = str0 + this->getOperator() + str1;
    return final;
}

void ArithmeticRound::generateQuestion()
{

    int randint0 = std::rand() % 2;

    if (randint0)
    {
        this->current_operator = "+";
    }
    else
    {
        this->current_operator = "-";
    }

    if (this->difficulty < 0)
    {
        this->currentQuestion[0] = 1;
        this->currentQuestion[1] = 1;
    }
    else
    {

        this->currentQuestion[0] = std::rand() % this->getMaxQuestionValue();
        this->currentQuestion[1] = std::rand() % this->getMaxQuestionValue();
    }
}

int ArithmeticRound::getMaxQuestions()
{
    return 15;
}

int ArithmeticRound::getMaxQuestionValue()
{
    if (this->difficulty > 4)
    {
        return 100000000;
    }

    return 100 * this->difficulty;
}

} // namespace gameround
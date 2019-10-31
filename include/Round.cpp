/* Maths challenge quiz
   Copyright Ethan Marshall - 2019

   Licensed under the GPL V.3.0
*/

#include "Round.h"

#include "Util.h"
#include "Constants.h"

#include <iostream>
#include <string>
#include <chrono>
#include <math.h>

namespace gameround
{

GameRound::GameRound(PreviousRound prevround, int difficulty)
{
    util::clearScreen();

    this->difficulty = difficulty;

    this->question_amount = std::rand() % MAX_QUESTION_AMOUNT + 1;
    this->type = std::rand() % MAX_ROUND_TYPES;

    this->previousSkipRound = prevround.previousSkip;
    this->invalidRound = ((this->type == RoundType::skip) and (this->previousSkipRound));
    this->showInterlude = not this->invalidRound;

    this->current_question[0] = 1;
    this->current_question[1] = 1;

    this->question_bounds = bounds[this->difficulty][this->type];

    if (this->type == RoundType::skip)
    {
        this->setupSkipRound();
    }

    // Intro text
    std::string intro = this->getIntroText();

    std::cout << intro << "\n";
    std::cout << "You will answer " << this->question_amount << " questions this round\n\n";

    if (this->type == RoundType::speed)
    {
	this->runSpeedIntro();
    }
}

GameRound::~GameRound()
{
}

void GameRound::getRoundInfo(PreviousRound *previousRound)
{
    previousRound->previousType = this->type;

    previousRound->previousSkip = (this->type == RoundType::skip) ? true : false;
}

double GameRound::getPercentCorrect()
{
    double points = (double)this->points;
    double amount = (double)this->question_amount;

    double percent_correct = points / amount;

    return percent_correct;
}

bool GameRound::isRoundOver()
{
    return (this->question_number >= this->question_amount);
}

void GameRound::runInterlude()
{
    if (this->showInterlude)
    {
        util::clearScreen();

        std::cout << "You have completed this round\n";
        std::cout << "The next round will begin shortly\n";
        std::cout << "This round's points total:  " + std::to_string(this->points);
        std::cout.flush();

        util::sleep(5);
    }
}

float GameRound::askQuestion()
{

    this->question_number++;

    if (this->type == RoundType::skip)
    {
        this->runSkipRound();
        return INVALID_ANSWER_FLOAT;
    }

    // Generate question
    this->generateQuestion();

    // Start timing the question
    time_t timeNow;
    std::time(&timeNow);

    // Ask the question
    std::cout << QUESTION_FORMAT_BEGINNING << this->current_question_string << QUESTION_FORMAT_ENDING;

    std::string givenAnswer;
    std::getline(std::cin, givenAnswer);

    float answer;
    try
    {
        answer = std::stof(givenAnswer);
    }
    catch (std::invalid_argument)
    {
        return INVALID_ANSWER_FLOAT;
    }

    // End timing
    time_t timeAfter;
    std::time(&timeAfter);
    this->question_time = (int)timeAfter - timeNow;

    return answer;
}

bool GameRound::verifyAnswer(float answer)
{

    if (answer == -1.5f)
        return false;

    if (this->type == skip)
        return true;

    switch (this->type)
    {

    case arithmetic:
        return (answer == (this->current_question[0] + this->current_question[1]));
        break;
    case multiplication:
        return (answer == (this->current_question[0] * this->current_question[1]));
        break;
    case division:
        return (answer == (this->current_question[0] / this->current_question[1]));
        break;
    case speed:
        return (answer == (this->current_question[0] * this->current_question[1]));
        break;
    default:
        return (answer == (this->current_question[0] + this->current_question[1]));
        break;
    }
}

void GameRound::creditAnswer(bool correct)
{
    if (this->type == skip)
        return;

    if (this->type != speed)
    {
        if (correct)
        {
            std::cout << "Correct\n";
            this->points++;
        }
        else
        {
            std::cout << "Incorrect\n";
            // TODO: Add random insults here
        }
    }
    else
    {
        if (correct)
        {
            this->handleSpeedReward();
        }
        else
        {
            std::cout << "Incorrect\n";
            std::cout << "0 points awarded\n\n";
        }
    }
}

void GameRound::handleSpeedReward()
{
    std::cout << "Correct\n";
    std::cout << "You took " << this->question_time << " seconds\n";

    switch (this->question_time)
    {

    case EXCELLENT:
        std::cout << "Excellent\n";
        std::cout << EXCELLENT_POINTS << " points awarded\n\n";
        this->points += EXCELLENT_POINTS;
        break;

    case GREAT:
        std::cout << "Great\n";
        std::cout << GREAT_POINTS << " points awarded\n\n";
        this->points += GREAT_POINTS;
        break;

    case OK:
        std::cout << "OK\n";
        std::cout << OK_POINTS << " points awarded\n\n";
        this->points += OK_POINTS;
        break;

    case POOR:
        std::cout << "Slow\n";
        std::cout << "Speed up\n";
        std::cout << POOR_POINTS << " points awarded\n\n";
        this->points += POOR_POINTS;
        break;

    default:
        std::cout << "Very slow\n";
        std::cout << "You must speed up\n";
        std::cout << "1 point has been deducted\n\n";
        this->points += BAD_POINTS;
        break;
    }
}

void GameRound::generateQuestion()
{
    int randint1 = std::rand() % (this->question_bounds - 1) + 1;
    int randint2 = std::rand() % (this->question_bounds - 1) + 1;

    this->current_question[0] = randint1;
    this->current_question[1] = randint2;

    std::string randstr1 = std::to_string(randint1);
    std::string randstr2 = std::to_string(randint2);

    this->current_question_string = randstr1 + this->getOperatorString() + randstr2;
}

std::string GameRound::getIntroText()
{
    return intro_texts[this->type];
}

std::string GameRound::getOperatorString()
{
    switch (this->type)
    {
    case arithmetic:
        return "+";

    case multiplication:
        return "x";

    case division:
        return "÷";

    case speed:
        return "x";

    default:
        return "+";
    }
}

void GameRound::setupSkipRound()
{
    this->question_amount = 0;
    this->question_number = -1;
}

void GameRound::runSkipRound()
{
    for (int i = 0; i < 10; i++)
    {
        std::cout << i << "\n";
        std::cout.flush();

        util::sleep(1);
    }
}

void GameRound::runSpeedIntro()
{
    std::cout << "\n\nPress enter when you are ready to play the round...";
    std::getchar();

    for (int i = 0; i < 5; i++)
    {
        std::cout << i << "\n";
        std::cout.flush();

        util::sleep(1);
    }
}

} // namespace gameround

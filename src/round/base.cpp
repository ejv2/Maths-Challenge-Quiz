/* Maths challenge quiz
   Copyright Ethan Marshall - 2019

   Licensed under the GPL V.3.0
*/

#include "base.hpp"
#include "../const.hpp"
#include "../scoring.hpp"
#include "../startup.hpp"
#include "../util.hpp"
#include "round.hpp"

#include <iostream>
#include <math.h>

using namespace startup;

namespace gameround {

BaseRound::BaseRound(startup_information *info) {
}

BaseRound::BaseRound() {
	util::clearScreen();
}

BaseRound::~BaseRound() {
}

double BaseRound::askQuestion() {
	return 1.0;
}

void BaseRound::handleAnswer(double answer) {
}

void BaseRound::handleFeedback() {
	int rng = (std::rand() % (5 - 1)) + 1;

	switch (rng) {
	case 1:
		std::cout
			<< "Wow, that was really well done! Too bad computers can't "
			   "understand sarcasm because this sentence is full of it!\n";
		break;
	case 2:
		std::cout << "Let's just forget this ever happened, shall we?\n";
		break;
	case 3:
		std::cout << "How old are you again?\n";
		break;
	case 4:
		std::cout << "That was so obvious, it took me a negative amount of "
					 "time to answer it\n";
		break;
	case 5:
		std::cout
			<< "'I think therefore I am', then what does that make you?\n";
		break;
	case 6:
		std::cout << "You are the weakest link, goodbye\n";
		break;
	}
}

bool BaseRound::isRoundOver() {
	return (this->current_question_number > this->amount_questions);
}

bool BaseRound::questionsRequired() {
	return true;
}

void BaseRound::runInterlude() {
#if !NO_ROUND_WAIT
	std::cout << "You have completed this round\n";
	std::cout << "The next round will begin shortly...\n\n";

	std::cout << "This round's points total: " << this->points << "\n";
	std::cout << "Percentage of answers correct: "
			  << std::floor(this->getPercentCorrect() * 100) << "%\n";

	util::sleep(5);
#endif
}

void BaseRound::haltPostRound() {
#if !NO_ROUND_WAIT
	util::sleep(3);
	util::clearScreen();
#endif
}

void BaseRound::runIntro() {
	std::cout << this->name << std::endl;
	std::cout << this->description << std::endl;
	if (this->amount_questions > 0) {
		std::cout << "You will answer " << this->amount_questions
				  << " questions this round\n";
	}
	std::cout << "Good luck!\n\n";
}

int BaseRound::getPoints() {
	return this->points;
}

double BaseRound::getPercentCorrect() {
	return (double)this->points / (double)this->amount_questions;
}

bool BaseRound::shouldPassRound() {
#if ALWAYS_PASS
	return true;
#else
	return (((double)this->points / (double)this->amount_questions) >= 0.5);
#endif
}

bool BaseRound::checkRoundValidity() {
	return true;
}

void BaseRound::generateQuestion() {
	this->currentQuestion[0] = 1;
	this->currentQuestion[1] = 1;
}

void BaseRound::updateGameState(scoring::GameStatus *status) {
	status->rounds_completed++;
	status->questions_answered += this->amount_questions;

	status->overall_points += this->points;

	status->percent_correct =
		((double)status->overall_points / (double)status->questions_answered) *
		100;
}

int BaseRound::getSize() {
	return sizeof(BaseRound);
}

bool BaseRound::verifyAnswer(double answer) {
	return true;
}

inline std::string BaseRound::getOperator() {
	return "?";
}

std::string BaseRound::getQuestionString() {
	return "x?x";
}

int BaseRound::getMaxQuestions() {
	return BASE_MAX_QUESTIONS;
}

int BaseRound::getMaxQuestionValue() {
	return 100;
}

} // namespace gameround

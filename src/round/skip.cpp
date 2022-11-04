/* Maths challenge quiz
   Copyright Ethan Marshall - 2019

   Licensed under the GPL V.3.0
*/

#include "skip.hpp"
#include "../const.hpp"
#include "../startup.hpp"
#include "../util.hpp"

#include <iostream>
#include <string>

using namespace startup;

namespace gameround {

SkipRound::SkipRound(startup_information *info, bool previousSkip) {
	this->difficulty = info->difficulty;
	this->current_question_number = 1;
	this->points = 0;

	this->currentQuestion[0] = 1;
	this->currentQuestion[1] = 1;

	this->amount_questions = std::rand() % this->getMaxQuestions() + 1;

	this->skipEnded = false;
	this->previousSkipRound = previousSkip;
	this->invalidRound = !this->checkRoundValidity();

	if (!invalidRound) {
		this->runIntro();
		this->runSkip();
	}

	this->skipEnded = true;
}

SkipRound::~SkipRound() {
}

bool SkipRound::isRoundOver() {
	return this->skipEnded;
}

bool SkipRound::questionsRequired() {
	return true;
}

bool SkipRound::shouldPassRound() {
	return true;
}

void SkipRound::runIntro() {
	std::cout << this->getRoundName() << "\n";
	std::cout << this->getIntroText() << "\n\n";
}

void SkipRound::runInterlude() {
	util::clearScreen();
}

void SkipRound::haltPostRound() {
	return;
}

int SkipRound::getSize() {
	return sizeof(SkipRound);
}

bool SkipRound::checkRoundValidity() {
	return !this->previousSkipRound;
}

bool SkipRound::skipRound() {
	return true;
}

inline std::string SkipRound::getRoundName() {
	return "Skip round";
}

inline std::string SkipRound::getIntroText() {
	return "You have been blessed with a skip round\nYou will not be asked any "
		   "questions for 10 seconds\nRegular questions will resume next "
		   "round.";
}

inline std::string SkipRound::getOperator() {
	return " ";
}

void SkipRound::runSkip() {
#if DISABLE_SKIP_ROUNDS
	std::cout << "Skip rounds have been disabled in this copy of the game\n";
	std::cout << "Questions resuming now...\n";
	std::cout.flush();

	util::sleep(2);
#else
	this->currentCounterText = "";

	for (int i = SKIP_ROUND_TIME; i > 0; i--) {
		this->printCounterText(i);
	}

	std::cout << "\nQuestions resuming now...";
	std::cout.flush();
	util::sleep(2);
#endif
}

void SkipRound::printCounterText(int counterValue) {
	std::cout << std::string(this->currentCounterText.length(), '\b');

	this->currentCounterText =
		"Time remaining: " + std::to_string(counterValue) + "s ";
	std::cout << this->currentCounterText;

	std::cout.flush();
	util::sleep(1);
}

} // namespace gameround

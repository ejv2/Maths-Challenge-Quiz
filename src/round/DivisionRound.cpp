/* Maths challenge quiz
   Copyright Ethan Marshall - 2019

   Licensed under the GPL V.3.0
*/

#include "DivisionRound.h"
#include "../Constants.h"
#include "../Startup.h"
#include "../Util.h"

#include <iostream>
#include <math.h>
#include <string>

using namespace startup;

namespace gameround {

DivisionRound::DivisionRound(PreviousRound *prevround,
							 startup_information *info) {
	this->roundType = RoundType::division;

	this->difficulty = info->difficulty;
	this->current_question_number = 1;
	this->points = 0;

	this->currentQuestion[0] = 1;
	this->currentQuestion[1] = 1;

	this->amount_questions = std::rand() % this->getMaxQuestions() + 1;

	this->runIntro();
}

DivisionRound::~DivisionRound() {
}

double DivisionRound::askQuestion() {

	this->current_question_number++;

	this->generateQuestion();

	std::cout << "Enter the answer to " << this->getQuestionString() << ":";

	std::string givenAnswer;
	std::getline(std::cin, givenAnswer);

	double answer;
	try {
		answer = std::stod(givenAnswer);
	} catch (std::invalid_argument) {
		return INVALID_ANSWER;
	}

	return answer;
}

void DivisionRound::handleAnswer(double answer) {
	if (answer == INVALID_ANSWER) {
		std::cout << "Invalid answer\n\n";
		return;
	}

	if (this->verifyAnswer(answer)) {
		std::cout << "Correct\n\n";

		this->points++;
	} else {
		std::cout << "Incorrect\n\n";

		int rng = (std::rand() % (4)) + 1;
		if (rng == 1) {
			this->handleFeedback();
		}
	}
}

bool DivisionRound::questionsRequired() {
	return true;
}

void DivisionRound::runIntro() {
	std::cout << this->getRoundName() << "\n";
	std::cout << this->getIntroText() << "\n";
	std::cout << "You will answer " << this->amount_questions
			  << " questions this round\n";
	std::cout << "Good luck!\n\n";
}

int DivisionRound::getSize() {
	return sizeof(DivisionRound);
}

bool DivisionRound::checkRoundValidity() {
	return true;
}

inline std::string DivisionRound::getRoundName() {
	return "Division round";
}

inline std::string DivisionRound::getIntroText() {
	return "Divide the numbers shown to gain points\nYou may truncate the "
		   "answer to 2 decimal places or to a whole.";
}

bool DivisionRound::verifyAnswer(double answer) {
	return (answer == (this->currentQuestion[0] / this->currentQuestion[1]) ||
			(answer ==
			 util::roundDecimalPlaces(
				 (this->currentQuestion[0] / this->currentQuestion[1]), 2)));
}

inline std::string DivisionRound::getOperator() {
	return "÷";
}

std::string DivisionRound::getQuestionString() {
	std::string str0 = std::to_string((int)this->currentQuestion[0]);
	std::string str1 = std::to_string((int)this->currentQuestion[1]);

	std::string final = str0 + this->getOperator() + str1;
	return final;
}

void DivisionRound::generateQuestion() {

	if (this->difficulty < 0) {
		this->currentQuestion[0] = 1;
		this->currentQuestion[1] = 1;
	} else {

		this->currentQuestion[0] =
			std::rand() % (this->getMaxQuestionValue() - 1) + 1;
		this->currentQuestion[1] =
			std::rand() % (this->getMaxQuestionValue() - 1) + 1;
	}
}

int DivisionRound::getMaxQuestions() {
	return 15;
}

int DivisionRound::getMaxQuestionValue() {
	if (this->difficulty > 4) {
		return 100000000;
	}

	return 10 * this->difficulty;
}

} // namespace gameround

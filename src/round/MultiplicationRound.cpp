/* Maths challenge quiz
   Copyright Ethan Marshall - 2019

   Licensed under the GPL V.3.0
*/

#include "MultiplicationRound.h"
#include "../Constants.h"
#include "../Startup.h"

#include <iostream>
#include <string>

using namespace startup;

namespace gameround {

MultiplicationRound::MultiplicationRound(PreviousRound *prevround,
										 startup_information *info) {
	this->roundType = RoundType::multiplication;

	this->difficulty = info->difficulty;
	this->current_question_number = 1;
	this->points = 0;

	this->currentQuestion[0] = 1;
	this->currentQuestion[1] = 1;

	this->amount_questions = std::rand() % this->getMaxQuestions() + 1;

	this->runIntro();
}

MultiplicationRound::~MultiplicationRound() {
}

double MultiplicationRound::askQuestion() {

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

void MultiplicationRound::handleAnswer(double answer) {
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

void MultiplicationRound::handleFeedback() {
	int rng = (std::rand() % (5 - 1)) + 1;

	switch (rng) {
	case 1:
		BaseRound::handleFeedback();
		break;
	case 2:
		std::cout << "Bacteria dividing by binary fission do a better job than "
					 "that\n";
		break;
	case 3:
		std::cout << "People who get that wrong shouldn't be allowed to "
					 "multiply - in more than one way\n";
		break;
	case 4:
		std::cout << "Well done, you successfully multiplied my rage by 100\n";
		break;
	case 5:
		std::cout << "It gives me a headache just trying to think down to your "
					 "level\n";
		break;
	}
}

bool MultiplicationRound::questionsRequired() {
	return true;
}

void MultiplicationRound::runIntro() {
	std::cout << this->getRoundName() << "\n";
	std::cout << this->getIntroText() << "\n";
	std::cout << "You will answer " << this->amount_questions
			  << " questions this round\n";
	std::cout << "Good luck!\n\n";
}

int MultiplicationRound::getSize() {
	return sizeof(MultiplicationRound);
}

bool MultiplicationRound::checkRoundValidity() {
	return true;
}

inline std::string MultiplicationRound::getRoundName() {
	return "Multiplication round";
}

inline std::string MultiplicationRound::getIntroText() {
	return "Multiply the numbers shown to gain points.\nIncorrect answers will "
		   "result in permanent data loss and system destruction";
}

bool MultiplicationRound::verifyAnswer(double answer) {
	return answer == (this->currentQuestion[0] * this->currentQuestion[1]);
}

inline std::string MultiplicationRound::getOperator() {
	return "x";
}

std::string MultiplicationRound::getQuestionString() {
	std::string str0 = std::to_string((int)this->currentQuestion[0]);
	std::string str1 = std::to_string((int)this->currentQuestion[1]);

	std::string final = str0 + this->getOperator() + str1;
	return final;
}

void MultiplicationRound::generateQuestion() {

	if (this->difficulty <= 0) {
		this->currentQuestion[0] = 1;
		this->currentQuestion[1] = 1;
	} else {

		this->currentQuestion[0] = std::rand() % this->getMaxQuestionValue();
		this->currentQuestion[1] = std::rand() % this->getMaxQuestionValue();
	}
}

int MultiplicationRound::getMaxQuestions() {
	return 15;
}

int MultiplicationRound::getMaxQuestionValue() {
	if (this->difficulty > 4) {
		return 100000000;
	}

	return 12 * this->difficulty;
}

} // namespace gameround

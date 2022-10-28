/* Maths challenge quiz
   Copyright Ethan Marshall - 2019

   Licensed under the GPL V.3.0
*/

#include "SpeedRound.hpp"
#include "../const.hpp"
#include "../startup.hpp"
#include "../util.hpp"

#include <iostream>
#include <string>
#include <time.h>

using namespace startup;

namespace gameround {

SpeedRound::SpeedRound(PreviousRound *prevround, startup_information *info) {
	this->roundType = RoundType::speed;

	this->difficulty = info->difficulty;
	this->current_question_number = 1;
	this->points = 0;

	this->currentQuestion[0] = 1;
	this->currentQuestion[1] = 1;

	this->amount_questions = std::rand() % this->getMaxQuestions() + 1;

	this->runIntro();
}

SpeedRound::~SpeedRound() {
}

double SpeedRound::askQuestion() {
	time_t timenow;
	time_t timelater;
	time(&timenow);

	this->current_question_number++;

	this->generateQuestion();

	std::cout << "Enter the answer to " << this->getQuestionString() << ":";

	std::string givenAnswer;
	std::getline(std::cin, givenAnswer);

	time(&timelater);

	this->timediff = difftime(timelater, timenow);

	double answer;
	try {
		answer = std::stod(givenAnswer);
	} catch (std::invalid_argument) {
		return INVALID_ANSWER;
	}

	return answer;
}

void SpeedRound::creditAnswer() {
	int timediff = (unsigned int)this->timediff;
	int pointsToAward = 0;

	std::cout << "You took " << timediff << "s to answer\n\n";

	switch (timediff) {

	case EXCELLENT:
		std::cout << "EXCELLENT\n";
		pointsToAward = EXCELLENT_POINTS;
		break;
	case GREAT:
		std::cout << "GREAT\n";
		pointsToAward = GREAT_POINTS;
		break;
	case OK:
		std::cout << "OK\n";
		pointsToAward = OK_POINTS;
		break;
	case POOR:
		std::cout << "POOR\n";
		std::cout << "Speed up\n";
		pointsToAward = POOR_POINTS;
		break;
	default:
		std::cout << "BAD\n";
		std::cout << "Too slow, you must speed up\n";
		pointsToAward = BAD_POINTS;
		break;
	}

	std::cout << pointsToAward << " points awarded\n\n";
	this->points += pointsToAward;
}

void SpeedRound::handleAnswer(double answer) {
	if (answer == INVALID_ANSWER) {
		std::cout << "Invalid answer\n\n";
		return;
	}

	if (this->verifyAnswer(answer)) {
		this->creditAnswer();
	} else {
		std::cout << "Incorrect\n";
		std::cout << "0 points awarded\n\n";

		int rng = (std::rand() % (4)) + 1;
		if (rng == 1) {
			this->handleFeedback();
		}
	}
}

bool SpeedRound::questionsRequired() {
	return true;
}

void SpeedRound::runCountdown() {
	this->currentCountdownText = "";

	for (int i = 5; i > 0; i--) {
		std::cout << std::string(this->currentCountdownText.length(), '\b');

		this->currentCountdownText =
			"Round begins in: " + std::to_string(i) + "s ";
		std::cout << this->currentCountdownText;

		std::cout.flush();
		util::sleep(1);
	}

	util::clearScreen();
}

void SpeedRound::runIntro() {
	std::cout << this->getRoundName() << "\n";
	std::cout << this->getIntroText() << "\n";
	std::cout << "You will answer " << this->amount_questions
			  << " questions this round\n";
	std::cout << "Good luck!\n\n";

	std::cout << "Press enter when you are ready to play...";
	std::cin.get();
	std::cout << "\n";

	this->runCountdown();
}

int SpeedRound::getSize() {
	return sizeof(SpeedRound);
}

bool SpeedRound::checkRoundValidity() {
	return true;
}

inline std::string SpeedRound::getRoundName() {
	return "Speed round";
}

inline std::string SpeedRound::getIntroText() {
	return "You will be asked regular multiplication questions, but the speed "
		   "at which you answer will be measured.\nPoints will be awarded for "
		   "fast answers, but slow answers may result in deduction.";
}

bool SpeedRound::verifyAnswer(double answer) {
	return answer == (this->currentQuestion[0] * this->currentQuestion[1]);
}

inline std::string SpeedRound::getOperator() {
	return "x";
}

std::string SpeedRound::getQuestionString() {
	std::string str0 = std::to_string((int)this->currentQuestion[0]);
	std::string str1 = std::to_string((int)this->currentQuestion[1]);

	std::string final = str0 + this->getOperator() + str1;
	return final;
}

void SpeedRound::generateQuestion() {

	if (this->difficulty <= TRAINING_DIFFICULTY_THRESHOLD) {
		this->currentQuestion[0] = 1;
		this->currentQuestion[1] = 1;
	} else {

		this->currentQuestion[0] = std::rand() % this->getMaxQuestionValue();
		this->currentQuestion[1] = std::rand() % this->getMaxQuestionValue();
	}
}

int SpeedRound::getMaxQuestions() {
	return 15;
}

int SpeedRound::getMaxQuestionValue() {
	if (this->difficulty > 4) {
		return 100000000;
	}

	return 12 * this->difficulty;
}

} // namespace gameround

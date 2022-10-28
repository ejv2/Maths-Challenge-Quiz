/* Maths challenge quiz
   Copyright Ethan Marshall - 2019

   Licensed under the GPL V.3.0
*/

#include <iostream>
#include <stdexcept>

#include "const.hpp"
#include "dilemma.hpp"
#include "scoring.hpp"
#include "startup.hpp"
#include "util.hpp"

using namespace startup;

namespace gameround {
DilemmaRound::DilemmaRound(PreviousRound *prevround, startup_information *info,
						   scoring::GameStatus state) {
	this->roundType = RoundType::dilemma;

	this->info = info;

	this->difficulty = info->difficulty;
	this->current_question_number = 1;

	this->initialPoints = state.overall_points;
	this->points = 0;

	this->amount_questions = 1;
	this->runIntro();
}

DilemmaRound::~DilemmaRound() {
}

inline std::string DilemmaRound::getRoundName() {
	return "Dilemma Round";
}

inline std::string DilemmaRound::getIntroText() {
	return "Avast! A dilemma approaches...\nRise to the challenge for handsome "
		   "reward, but fail to do so and it will cost you\n";
}

inline std::string DilemmaRound::getOperator() {
	return "";
}

int DilemmaRound::getSize() {
	return sizeof(DilemmaRound);
}

double DilemmaRound::askQuestion() {
	this->hasAsked = true;

	std::cout << "Will you accept the challenge? Enter your answer below:\n";
	std::cout << "\t1) Increase difficulty by 1 level, in exchange for your "
				 "points being doubled...\n";
	std::cout << "\t2) Keep your difficulty the same, but lose 25% of your "
				 "points...\n\n";

	std::cout << "Your decision? ";
	std::string givenAnswer;
	std::getline(std::cin, givenAnswer);

	double answer;
	try {
		answer = std::stod(givenAnswer);
		this->decision = (int)answer;
	} catch (std::invalid_argument) {
		this->wasValidResponse = false;
		return INVALID_ANSWER;
	}

	if (answer > 2) {
		this->wasValidResponse = false;
		return INVALID_ANSWER;
	}

	return answer;
}

void DilemmaRound::handleAnswer(double answer) {
	if (answer == INVALID_ANSWER || !this->wasValidResponse) {
		std::cout << "I was expecting a yes or a no\n";
		std::cout << "Neither was never an option...\n";
		util::sleep(2);

		return;
	}

	if (answer == 1.0) {
		std::cout << "You have chosen wisely. Good luck...\n";

		this->info->difficulty++;
		this->points = this->initialPoints * 2;

		return;
	}

	if (answer == 2.0) {
		std::cout << "Not enough to tempt you? It will be next time...\n";

		this->points = (this->initialPoints / 4) * 3;

		return;
	}
}

void DilemmaRound::runIntro() {
	std::cout << this->getRoundName() << "\n";
	std::cout << this->getIntroText() << "\n\n";
}

void DilemmaRound::runInterlude() {
#if NO_ROUND_WAIT
	return;
#endif

	util::sleep(3);

	util::clearScreen();

	std::cout << "You have passed the test\n";
	std::cout << "The next round will begin shortly\n\n";

	if (this->decision == 1) {
		std::cout << "This round's points outcome: x2 points\n";
	} else {
		std::cout << "This round's points outcome: -25% points\n";
	}

	std::cout << "\nNew points total: " << (this->initialPoints + this->points)
			  << "\n";

	if (this->decision == 1) {
		std::cout << "New difficulty: " << this->difficulty + 1 << "\n";
	} else {
		std::cout << "New difficulty: " << this->difficulty << "\n";
	}

	util::sleep(5);
}

bool DilemmaRound::isRoundOver() {
	return this->hasAsked;
}

bool DilemmaRound::questionsRequired() {
	return true;
}

bool DilemmaRound::shouldPassRound() {
	return this->wasValidResponse;
}

int DilemmaRound::getMaxQuestions() {
	return 1;
}

} // namespace gameround

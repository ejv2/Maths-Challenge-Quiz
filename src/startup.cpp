/* Maths challenge quiz
   Copyright Ethan Marshall - 2019

   Licensed under the GPL V.3.0
*/

#include <iostream>
#include <string>
#include <vector>

#include "const.hpp"
#include "startup.hpp"
#include "util.hpp"

#define MAX_TUTORIAL_QUESTIONS 12
#define MIN_TUTORIAL_QUESTIONS 1

namespace startup {

bool warnImpossibleDifficulty() {
	std::cout << "\nWARNING: Impossible difficulty selected\n";
	std::cout << "You have selected impossible difficulty, which removes the "
				 "limit for how high question amounts can be\n";
	std::cout
		<< "You may encounter impossible to calculate values, extremely long "
		   "questions or numbers larger than the program can handle\n";
	std::cout << "You proceed at your own risk\n\n";

	std::string choice;
	std::cout << "Do you wish to continue? [Y/N]";
	std::getline(std::cin, choice);

	util::stringLower(choice);

	if (choice == "y") {
		std::cout << "Good luck, padawan\n\n";
		return true;
	} else {
		std::cout << "\n\n";
		return false;
	}
}

bool warnTrainingDifficulty() {
	std::cout << "\nWARNING: Training difficulty selected\n";
	std::cout << "You have selected training difficulty, meaning that all "
				 "questions will only contain the number 1\n";
	std::cout << "This mode is designed to be a trial run of the game and will "
				 "not give a true reflection of your mathamatical ability.\n";
	std::cout
		<< "Your score in this mode is considered non-genuine and certain "
		   "features of the game may be altered to reflect that.\n\n";

	std::string choice;
	std::cout << "Do you wish to continue? [Y/N]";
	std::getline(std::cin, choice);

	util::stringLower(choice);

	if (choice == "y") {
		std::cout << "Training mode has been applied for this round, and your "
					 "score is not genuine from this point forward\n\n";
		return true;
	} else {
		std::cout << "\n\n";
		return false;
	}
}

void handleDifficultyEnter(startup_information *info) {
	bool success = false;

	while (!success) {
		std::string difficulty;
		std::cout << "Enter your difficulty (1-4, ? for help)\n";
		std::cout << "Enter difficulty:";
		std::getline(std::cin, difficulty);

		if (difficulty.empty()) {
			std::cout << "Please enter a valid difficulty\n\n";
			continue;
		}

		if (difficulty == "?") {
			std::cout << "Difficulty levels:\n"
			 	     "==================\n"
				     "		[< 1]: Practice mode: All questions only contain the number one\n"
				     "		[ 1 ]: Easy mode: Should be able to complete using mental maths alone\n"
				     "		[ 2 ]: Normal mode: Should be able to complete most using mental maths alone\n"
				     "		[ 3 ]: Hard mode: You may need a calculator\n"
				     "		[ 4 ]: Very hard mode: You WILL need a calculator\n"
				     "		[> 4]: Impossible mode: You may need a supercomputer/more memory\n\n"
				     "Scores gained in practice mode are not legitimate and will be marked as such.\n"
				     "Success in impossible mode is not a thing.\n";
			continue;
		}

		try {
			info->difficulty = std::stoi(difficulty);
		} catch (const std::invalid_argument e) {
			std::cout << "Please enter a valid difficulty\n\n";
			continue;
		}

		if (info->difficulty <= TRAINING_DIFFICULTY_THRESHOLD) {
			success = warnTrainingDifficulty();
			continue;
		} else if (info->difficulty >= IMPOSSIBLE_DIFFICULTY_THRESHOLD) {
			success = warnImpossibleDifficulty();
			continue;
		}

		success = true;
		std::cout << "Your difficulty has been set to " << info->difficulty
				  << "\n\n";
	}
}

void runTutorial() {
	std::cout << std::endl;
	std::cout << "Welcome to the Maths Challenge Quiz!\n";
	std::cout << "In this game you stay ahead of the game by answering maths "
				 "problems correctly\n";
	std::cout << "You can select any difficulty to cater to your mathematical "
				 "ability\n";
	std::cout << "\n";
	std::cout << "Let's try out a simple tutorial\n";
	std::cout << "\n";

	int randint1 =
		std::rand() % (MAX_TUTORIAL_QUESTIONS - MIN_TUTORIAL_QUESTIONS) +
		MIN_TUTORIAL_QUESTIONS;
	int randint2 =
		std::rand() % (MAX_TUTORIAL_QUESTIONS - MIN_TUTORIAL_QUESTIONS) +
		MIN_TUTORIAL_QUESTIONS;

	std::string randstr1 = std::to_string(randint1);
	std::string randstr2 = std::to_string(randint2);

	std::string input;
	int answer;
	int correct_answer = randint1 * randint2;

	while (true) {
		std::cout << "Please enter the answer to " + randstr1 + "x" + randstr2 +
						 ":";
		std::getline(std::cin, input);

		if (!util::isValidNumber(input)) {
			std::cout << "Please enter a valid answer\n";
			continue;
		}

		answer = std::stoi(input);

		if (answer == correct_answer) {
			std::cout << "Correct, you've got the idea\n";
			std::cout << "You will now play the real game which will get you a "
						 "score\n";
			std::cout << "Good luck\n";
			std::cout.flush();
			util::sleep(2);
			std::cout.clear();
			break;
		} else {
			std::cout << "Incorrect, please try again\n\n";
		}
	}
}

bool askFirstTime() {
	std::string input;
	bool first = false;

	std::cout << "Is this your first time playing? [Y/N]";
	std::getline(std::cin, input);

	util::stringLower(input);

	if (input == "y") {
		runTutorial();
		first = true;
	}

	return first;
}

void handleStartQuestions(startup_information *info) {
	std::cout << "Please enter your name:";
	std::getline(std::cin, info->name);
	std::cout << "\n";

	handleDifficultyEnter(info);

	bool isFirst = askFirstTime();
	info->first = isFirst;
}

void handleDebugWarning() {
	std::cout << "WARNING\n";
	std::cout << "This copy of Maths Challenge Quiz has been compiled with the "
				 "debug flag!\n";
	std::cout << "This means that possible game-critical data will be "
				 "outputted and a substandard experience can be expected\n";
	std::cout << "If you didn't mean to obtain a debug build, please download "
				 "the program again or contact the vendor for this copy of the "
				 "program\n\n";
}

void haltPreGame() {
	std::cout << "\nGame commencing in 5 seconds...\n";
	std::cout.flush();
	util::sleep(5);
	util::clearScreen();
}

void printWelcome() {
	std::cout << "Welcome to the Maths Challenge Quiz\n";
	std::cout << "Copyright 2019 Ethan Marshall\n\n";
}

} // namespace startup

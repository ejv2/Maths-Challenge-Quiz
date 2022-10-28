/* Maths challenge quiz
   Copyright Ethan Marshall - 2019

   Licensed under the GPL V.3.0
*/

#include <string>
#include <vector>

#ifndef STARTUP_HEADER
#define STARTUP_HEADER

namespace startup {

struct startup_information {
	std::string name = "";
	int difficulty = 1;
	bool first = false;
};

void handleStartQuestions(startup_information *info);

void handleDebugWarning();

void haltPreGame();

void printWelcome();

} // namespace startup

#endif // header startup.h

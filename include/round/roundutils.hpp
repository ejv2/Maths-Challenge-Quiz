/* Maths challenge quiz
   Copyright Ethan Marshall - 2019

   Licensed under the GPL V.3.0
*/

#include "../scoring.hpp"
#include "../startup.hpp"
#include "base.hpp"

#ifndef ROUND_UTILS_HEADER
#define ROUND_UTILS_HEADER

namespace gameround {

enum RoundType {
	arithmetic = 1,
	multiplication = 2,
	division = 3,
	speed = 4,
	skip = 5,
	dilemma = 6
};

BaseRound *constructRound(int randint, bool previousSkip,
						  startup::startup_information *info,
						  scoring::GameStatus state);

} // namespace gameround

#endif // header roundutils.h

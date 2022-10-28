/* Maths challenge quiz
   Copyright Ethan Marshall - 2019

   Licensed under the GPL V.3.0
*/

#include "../scoring.hpp"
#include "../startup.hpp"
#include "BaseRound.hpp"

#ifndef ROUND_UTILS_HEADER
#define ROUND_UTILS_HEADER

namespace gameround {

BaseRound *constructRound(int randint, PreviousRound *previousRound,
						  startup::startup_information *info,
						  scoring::GameStatus state);

} // namespace gameround

#endif // header roundutils.h

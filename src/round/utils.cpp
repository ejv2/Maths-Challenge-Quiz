/* Maths challenge quiz
   Copyright Ethan Marshall - 2019

   Licensed under the GPL V.3.0
*/

#include "arithmetic.hpp"
#include "base.hpp"
#include "dilemma.hpp"
#include "division.hpp"
#include "multiplication.hpp"
#include "skip.hpp"
#include "speed.hpp"

#include "../const.hpp"
#include "../scoring.hpp"
#include "../startup.hpp"

namespace gameround {

BaseRound *constructRound(int randint, bool previousSkip,
						  startup::startup_information *info,
						  scoring::GameStatus state) {
#if FIX_ROUND
	return new FIX_ROUND_TYPE(info);
#else
	switch (randint) {

	case 1:
		return new ArithmeticRound(info);
		break;
	case 2:
		return new MultiplicationRound(info);
		break;
	case 3:
		return new DivisionRound(info);
		break;
	case 4:
		return new SpeedRound(info);
		break;
	case 5:
		return new SkipRound(info, previousSkip);
		break;
	case 6:
		return new DilemmaRound(info, state);
	default:
		return new ArithmeticRound(info);
		break;
	}
#endif
}

} // namespace gameround

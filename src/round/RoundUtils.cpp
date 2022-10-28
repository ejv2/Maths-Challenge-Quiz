/* Maths challenge quiz
   Copyright Ethan Marshall - 2019

   Licensed under the GPL V.3.0
*/

#include "ArithmeticRound.hpp"
#include "BaseRound.hpp"
#include "DilemmaRound.hpp"
#include "DivisionRound.hpp"
#include "MultiplicationRound.hpp"
#include "SkipRound.hpp"
#include "SpeedRound.hpp"

#include "../Constants.hpp"
#include "../Scoring.hpp"
#include "../Startup.hpp"

namespace gameround {

BaseRound *constructRound(int randint, PreviousRound *previousRound,
						  startup::startup_information *info,
						  scoring::GameStatus state) {
#if FIX_ROUND
	return new FIX_ROUND_TYPE(previousRound, info);
#else
	switch (randint) {

	case 1:
		return new ArithmeticRound(previousRound, info);
		break;
	case 2:
		return new MultiplicationRound(previousRound, info);
		break;
	case 3:
		return new DivisionRound(previousRound, info);
		break;
	case 4:
		return new SpeedRound(previousRound, info);
		break;
	case 5:
		return new SkipRound(previousRound, info);
		break;
	case 6:
		return new DilemmaRound(previousRound, info, state);
	default:
		return new ArithmeticRound(previousRound, info);
		break;
	}
#endif
}

} // namespace gameround

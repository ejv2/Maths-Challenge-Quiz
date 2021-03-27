/* Maths challenge quiz
   Copyright Ethan Marshall - 2019

   Licensed under the GPL V.3.0
*/

#include "ArithmeticRound.h"
#include "BaseRound.h"
#include "DilemmaRound.h"
#include "DivisionRound.h"
#include "MultiplicationRound.h"
#include "SkipRound.h"
#include "SpeedRound.h"

#include "../Constants.h"
#include "../Scoring.h"
#include "../Startup.h"

namespace gameround {

BaseRound *constructRound(int randint, PreviousRound *previousRound,
						  startup::startup_information *info,
						  scoring::GameStatus state) {
#if FIX_ROUND
	return new FIX_ROUND_TYPE(previousRound, &info);
#else
	switch (randint) {

	case 1:
		return new ArithmeticRound(previousRound, *info);
		break;
	case 2:
		return new MultiplicationRound(previousRound, *info);
		break;
	case 3:
		return new DivisionRound(previousRound, *info);
		break;
	case 4:
		return new SpeedRound(previousRound, *info);
		break;
	case 5:
		return new SkipRound(previousRound, *info);
		break;
	case 6:
		return new DilemmaRound(previousRound, info, state);
	default:
		return new ArithmeticRound(previousRound, *info);
		break;
	}
#endif
}

} // namespace gameround

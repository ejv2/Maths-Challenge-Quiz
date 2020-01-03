/* Maths challenge quiz
   Copyright Ethan Marshall - 2019

   Licensed under the GPL V.3.0
*/

#include "BaseRound.h"
#include "ArithmeticRound.h"
#include "MultiplicationRound.h"
#include "DivisionRound.h"
#include "SpeedRound.h"
#include "SkipRound.h"

#include "../Startup.h"

namespace gameround
{

BaseRound *constructRound(int randint, PreviousRound *previousRound, startup::startup_information info)
{
    switch (randint)
    {

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
    default:
        return new ArithmeticRound(previousRound, info);
        break;
    }
}

} // namespace gameround
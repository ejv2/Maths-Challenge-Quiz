/* Maths challenge quiz
   Copyright Ethan Marshall - 2019

   Licensed under the GPL V.3.0
*/

#include "BaseRound.h"
#include "ArithmeticRound.h"
#include "../Startup.h"

namespace gameround
{

BaseRound *constructRound(int randint, PreviousRound *previousRound, startup::startup_information info)
{
    return new ArithmeticRound(previousRound, info);
}

} // namespace gameround
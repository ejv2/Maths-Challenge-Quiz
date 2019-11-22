/* Maths challenge quiz
   Copyright Ethan Marshall - 2019

   Licensed under the GPL V.3.0
*/

#include "BaseRound.h"
#include "ArithmeticRound.h"

namespace gameround
{

BaseRound *constructRound(int randint, PreviousRound *previousRound)
{
    return new ArithmeticRound(previousRound);
}

} // namespace gameround
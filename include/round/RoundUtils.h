/* Maths challenge quiz
   Copyright Ethan Marshall - 2019

   Licensed under the GPL V.3.0
*/

#include "BaseRound.h"

#ifndef ROUND_UTILS_HEADER
#define ROUND_UTILS_HEADER

namespace gameround
{

BaseRound *constructRound(int randint, PreviousRound *previousRound);

} // namespace gameround

#endif
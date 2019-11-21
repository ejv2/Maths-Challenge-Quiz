/* Maths challenge quiz
   Copyright Ethan Marshall - 2019

   Licensed under the GPL V.3.0
*/

#ifndef ROUND_HEADER
#define ROUND_HEADER

namespace gameround
{

enum RoundType
{
    arithmetic = 0,
    multiplication = 1,
    division = 2,
    speed = 3,
    skip = 4
};

enum OperandType
{
    add = 0,
    sub = 1,
    mult = 2,
    div = 3
};

struct PreviousRound
{
    int previousType = arithmetic;
    bool previousSkip = false;
};

} // namespace gameround

#endif
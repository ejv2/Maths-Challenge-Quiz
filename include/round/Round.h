/* Maths challenge quiz
   Copyright Ethan Marshall - 2019

   Licensed under the GPL V.3.0
*/

#ifndef ROUND_SYSTEM_HEADER
#define ROUND_SYSTEM_HEADER

namespace gameround
{

    enum RoundType
    {
        arithmetic = 1,
        multiplication = 2,
        division = 3,
        speed = 4,
        skip = 5
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

#endif // header round.h
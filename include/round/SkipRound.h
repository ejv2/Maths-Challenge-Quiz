/* Maths challenge quiz
   Copyright Ethan Marshall - 2019

   Licensed under the GPL V.3.0
*/

#include "BaseRound.h"
#include "../Startup.h"

using namespace startup;

#ifndef SKIP_ROUND
#define SKIP_ROUND

namespace gameround
{

    class SkipRound : public BaseRound
    {

    public:
        SkipRound(PreviousRound *prevround, startup_information info);
        ~SkipRound();

        bool isRoundOver() override;
        bool questionsRequired() override;

        bool shouldPassRound() override;

        void runIntro() override;
        void runInterlude() override;

        int getSize() override;

    private:
        bool checkRoundValidity() override;

        inline std::string getRoundName() override;
        inline std::string getIntroText() override;
        inline std::string getOperator() override;

        void runSkip();

        std::string currentCounterText;
        void printCounterText(int counterValue);

        bool skipEnded;
    };

} // namespace gameround

#endif // header skipround.h
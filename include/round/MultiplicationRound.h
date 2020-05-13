/* Maths challenge quiz
   Copyright Ethan Marshall - 2019

   Licensed under the GPL V.3.0
*/

#include "BaseRound.h"
#include "../Startup.h"

using namespace startup;

#ifndef MULTIPLICATION_ROUND
#define MULTIPLICATION_ROUND

namespace gameround
{

    class MultiplicationRound : public BaseRound
    {

    public:
        MultiplicationRound(PreviousRound *prevround, startup_information info);
        ~MultiplicationRound();

        double askQuestion() override;
        void handleAnswer(double answer) override;

        bool questionsRequired() override;

        void runIntro() override;

        int getSize() override;

    private:
        bool checkRoundValidity() override;

        inline std::string getRoundName() override;
        inline std::string getIntroText() override;

        bool verifyAnswer(double answer) override;
        void handleFeedback() override;

        inline std::string getOperator() override;
        std::string getQuestionString() override;

        void generateQuestion() override;

        int getMaxQuestions() override;
        int getMaxQuestionValue() override;
    };

} // namespace gameround

#endif
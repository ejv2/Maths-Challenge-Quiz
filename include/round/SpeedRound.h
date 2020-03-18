/* Maths challenge quiz
   Copyright Ethan Marshall - 2019

   Licensed under the GPL V.3.0
*/

#include "BaseRound.h"
#include "../Startup.h"
#include <time.h>

using namespace startup;

#ifndef SPEED_ROUND
#define SPEED_ROUND

namespace gameround
{

class SpeedRound : public BaseRound
{

public:
    SpeedRound(PreviousRound *prevround, startup_information info);
    ~SpeedRound();

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
    void creditAnswer();

    inline std::string getOperator() override;
    std::string getQuestionString() override;

    void generateQuestion() override;

    int getMaxQuestions() override;
    int getMaxQuestionValue() override;

    void runCountdown();
    std::string currentCountdownText;

    double timediff;
};

} // namespace gameround

#endif
/* Maths challenge quiz
   Copyright Ethan Marshall - 2019

   Licensed under the GPL V.3.0
*/

#include "../startup.hpp"
#include "base.hpp"
#include <time.h>

using namespace startup;

#ifndef SPEED_ROUND
#define SPEED_ROUND

namespace gameround {

class SpeedRound : public BaseRound {

  public:
	SpeedRound(startup_information *info);
	~SpeedRound();

	double askQuestion() override;
	void handleAnswer(double answer) override;
	bool questionsRequired() override;

	int getSize() override;

  private:
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
}; // class SpeedRound

} // namespace gameround

#endif // header speedround.h

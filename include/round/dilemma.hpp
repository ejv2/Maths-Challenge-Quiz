/* Maths challenge quiz
   Copyright Ethan Marshall - 2019

   Licensed under the GPL V.3.0
*/

#include "../startup.hpp"
#include "base.hpp"
#include "scoring.hpp"

using namespace startup;

#ifndef DILEMMA_ROUND
#define DILEMMA_ROUND

namespace gameround {

class DilemmaRound : public BaseRound {

  public:
	DilemmaRound(startup_information *info,
				 scoring::GameStatus state);
	~DilemmaRound();

	bool isRoundOver() override;
	bool shouldPassRound() override;

	double askQuestion() override;
	void handleAnswer(double answer) override;
	bool questionsRequired() override;
	void runInterlude() override;

	int getSize() override;

  private:
	bool wasValidResponse = true;
	bool hasAsked = false;

	int initialPoints = 0;
	int decision = 0;

	startup_information *info;

	inline std::string getOperator() override;

	int getMaxQuestions() override;
}; // class DilemmaRound

} // namespace gameround

#endif // header dilemmaround.h

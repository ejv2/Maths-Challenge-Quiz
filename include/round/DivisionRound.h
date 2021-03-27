/* Maths challenge quiz
   Copyright Ethan Marshall - 2019

   Licensed under the GPL V.3.0
*/

#include "../Startup.h"
#include "BaseRound.h"

using namespace startup;

#ifndef DIVISION_ROUND
#define DIVISION_ROUND

namespace gameround {

class DivisionRound : public BaseRound {

  public:
	DivisionRound(PreviousRound *prevround, startup_information *info);
	~DivisionRound();

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

	inline std::string getOperator() override;
	std::string getQuestionString() override;

	void generateQuestion() override;

	int getMaxQuestions() override;
	int getMaxQuestionValue() override;
}; // class DivisionRound

} // namespace gameround

#endif // header divisionround.h

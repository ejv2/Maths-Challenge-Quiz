/* Maths challenge quiz
   Copyright Ethan Marshall - 2019

   Licensed under the GPL V.3.0
*/

#include "../startup.hpp"
#include "BaseRound.hpp"

using namespace startup;

#ifndef ARITHMETIC_ROUND
#define ARITHMETIC_ROUND

namespace gameround {

class ArithmeticRound : public BaseRound {

  public:
	ArithmeticRound(PreviousRound *prevround, startup_information *info);
	~ArithmeticRound();

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

	std::string current_operator;
}; // class ArithmeticRound

} // namespace gameround

#endif // header arithmeticround.h

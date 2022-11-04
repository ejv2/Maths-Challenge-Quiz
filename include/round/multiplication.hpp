/* Maths challenge quiz
   Copyright Ethan Marshall - 2019

   Licensed under the GPL V.3.0
*/

#include "../startup.hpp"
#include "base.hpp"

using namespace startup;

#ifndef MULTIPLICATION_ROUND
#define MULTIPLICATION_ROUND

namespace gameround {

class MultiplicationRound : public BaseRound {

  public:
	MultiplicationRound(startup_information *info);
	~MultiplicationRound();

	double askQuestion() override;
	void handleAnswer(double answer) override;
	bool questionsRequired() override;

	int getSize() override;

  private:
	bool verifyAnswer(double answer) override;
	void handleFeedback() override;

	inline std::string getOperator() override;
	std::string getQuestionString() override;

	void generateQuestion() override;

	int getMaxQuestions() override;
	int getMaxQuestionValue() override;
}; // class MultiplicationRound

} // namespace gameround

#endif // header multiplicationround.h

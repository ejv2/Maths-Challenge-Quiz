/* Maths challenge quiz
   Copyright Ethan Marshall - 2019

   Licensed under the GPL V.3.0
*/

#include "../startup.hpp"
#include "base.hpp"

using namespace startup;

#ifndef DIVISION_ROUND
#define DIVISION_ROUND

namespace gameround {

class DivisionRound : public BaseRound {

  public:
	DivisionRound(startup_information *info);
	~DivisionRound();

	double askQuestion() override;
	void handleAnswer(double answer) override;

	bool questionsRequired() override;
	int getSize() override;

  private:
	bool verifyAnswer(double answer) override;
	inline std::string getOperator() override;
	std::string getQuestionString() override;

	void generateQuestion() override;

	int getMaxQuestions() override;
	int getMaxQuestionValue() override;
}; // class DivisionRound

} // namespace gameround

#endif // header divisionround.h

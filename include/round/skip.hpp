/* Maths challenge quiz
   Copyright Ethan Marshall - 2019

   Licensed under the GPL V.3.0
*/

#include "../startup.hpp"
#include "base.hpp"

using namespace startup;

#ifndef SKIP_ROUND
#define SKIP_ROUND

namespace gameround {

class SkipRound : public BaseRound {

  public:
	SkipRound(startup_information *info, bool prevSkip);
	~SkipRound();

	bool isRoundOver() override;
	bool questionsRequired() override;

	bool shouldPassRound() override;

	void runInterlude() override;
	void haltPostRound() override;

	int getSize() override;

  private:
	bool checkRoundValidity() override;
	inline std::string getOperator() override;

	void runSkip();

	std::string currentCounterText;
	void printCounterText(int counterValue);

	bool skipEnded;
}; // class SkipRound

} // namespace gameround

#endif // header skipround.h

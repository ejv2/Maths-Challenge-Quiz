/* Maths challenge quiz
   Copyright Ethan Marshall - 2019

   Licensed under the GPL V.3.0
*/

#include "../Scoring.h"
#include "../Startup.h"
#include "Round.h"

#include <string>

using namespace startup;

#ifndef BASE_ROUND
#define BASE_ROUND

namespace gameround {

class BaseRound {
  public:
	BaseRound();
	BaseRound(PreviousRound *previousRound, startup_information *info);
	virtual ~BaseRound();

	virtual double askQuestion();
	virtual void handleAnswer(double answer);

	virtual bool isRoundOver();
	virtual bool questionsRequired();

	virtual void runIntro();
	virtual void runInterlude();

	virtual void haltPostRound();

	int getPoints();
	double getPercentCorrect();
	virtual bool shouldPassRound();

	virtual int getSize();

	void getRoundInfo(PreviousRound *prevround);
	void updateGameState(scoring::GameStatus *status);

  protected:
	int difficulty;

	int points;

	int amount_questions;
	int current_question_number;

	double currentQuestion[2];

	bool previousSkipRound = false;
	bool invalidRound = false;
	bool showInterlude = true;

	RoundType roundType;

	virtual bool checkRoundValidity();

	virtual inline std::string getRoundName();
	virtual inline std::string getIntroText();

	virtual bool verifyAnswer(double answer);
	virtual void handleFeedback();

	virtual inline std::string getOperator();
	virtual std::string getQuestionString();

	virtual void generateQuestion();

	virtual int getMaxQuestions();
	virtual int getMaxQuestionValue();
}; // class BaseRound

} // namespace gameround

#endif // header baseround.h

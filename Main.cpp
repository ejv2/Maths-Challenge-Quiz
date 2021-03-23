/* Maths challenge quiz
   Copyright Ethan Marshall - 2019

   Licensed under the GPL V.3.0
*/

#include <cmath>
#include <cstring>
#include <iostream>
#include <string>
#include <vector>

#include "include/CommandLine.h"
#include "include/Constants.h"
#include "include/Scoring.h"
#include "include/Startup.h"
#include "include/Util.h"

#include "include/round/BaseRound.h"
#include "include/round/Round.h"
#include "include/round/RoundUtils.h"

using namespace gameround;
using namespace std;

static PreviousRound prevRound;
static scoring::GameStatus game_state;
static cmd::cmd_information command_info;

int main(int argc, char *argv[]) {
	// Setup random behaviour seed based on system time
	util::setupRandomSeed();

	if (cmd::handleCmdLine(argv, argc, &command_info))
		return 0;

	if (DEBUG)
		startup::handleDebugWarning();

	startup::printWelcome();

	startup::startup_information info;
	startup::handleStartQuestions(&info);

	startup::haltPreGame();

	// Main game loop
	while (true) {

		// Construct round
		int roundType = (std::rand() % (MAX_ROUND_TYPES - 1)) + 1;
		BaseRound *currentRound =
			gameround::constructRound(roundType, &prevRound, info);

		// ==================== [START OF ROUND] ====================

		while (!currentRound->isRoundOver()) {

			double ans = currentRound->askQuestion();
			currentRound->handleAnswer(ans);
		}

		// ==================== [END OF ROUND] ====================

		// Fill in the previous round's information
		currentRound->getRoundInfo(&prevRound);
		currentRound->updateGameState(&game_state);

		if (!currentRound->shouldPassRound()) {
			scoring::run_roundFailureCutscene();
			scoring::displayResults(game_state, info.difficulty);
			scoring::resultAcceptance(info.difficulty);
			break;
		}

		currentRound->runInterlude();

		// Free the current round
		delete currentRound;
		std::memset((void *)currentRound, 0, sizeof(currentRound->getSize()));
	}

	// When we reach this point, the game is over
	scoring::gameExiting();

	return 0;
}

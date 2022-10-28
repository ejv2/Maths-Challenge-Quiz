/* Maths challenge quiz
   Copyright Ethan Marshall - 2019

   Licensed under the GPL V.3.0
*/

#include <cmath>
#include <cstring>
#include <iostream>
#include <string>
#include <vector>

#ifdef linux
#include <unistd.h>
#endif

#include "include/CommandLine.hpp"
#include "include/Constants.hpp"
#include "include/Scoring.hpp"
#include "include/Startup.hpp"
#include "include/Util.hpp"

#include "include/round/BaseRound.hpp"
#include "include/round/Round.hpp"
#include "include/round/RoundUtils.hpp"

using namespace gameround;
using namespace std;

static PreviousRound prevRound;
static scoring::GameStatus game_state;
static cmd::cmd_information command_info;

int main(int argc, char *argv[]) {
	// Setup random behaviour seed based on system time
	util::setupRandomSeed();

#ifdef linux
	// Quit attempts at cheating using pipes (only a problem on *Nix)
	if (!isatty(STDIN_FILENO)) {
		std::cout << "Standard input must come from a terminal device\n";
		return -1;
	}
#endif

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
			gameround::constructRound(roundType, &prevRound, &info, game_state);

		// ==================== [START OF ROUND] ====================

		while (!currentRound->isRoundOver()) {

			double ans = currentRound->askQuestion();
			currentRound->handleAnswer(ans);
		}

		// ==================== [END OF ROUND] ====================

		// Fill in the previous round's information
		currentRound->getRoundInfo(&prevRound);
		currentRound->updateGameState(&game_state);

		currentRound->haltPostRound();

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

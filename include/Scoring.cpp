/* Maths challenge quiz
   Copyright Ethan Marshall - 2019

   Licensed under the GPL V.3.0
*/

#include <iostream>
#include <string>
#include <tuple>
#include <math.h>

#include "Scoring.h"
#include "Util.h"
#include "Constants.h"

#define QUICK_PRINT(msg)      \
    std::cout << msg << "\n"; \
    std::cout.flush();

namespace scoring
{

void run_roundFailureCutscene()
{
    util::clearScreen();
    std::cout.flush();

    QUICK_PRINT("Your result that round was...");
    util::sleep(3.5);

    QUICK_PRINT("Unsatisfactory");
    util::sleep(5);

    util::clearScreen();
    QUICK_PRINT("The penalty is...");
    util::sleep(3);

    QUICK_PRINT("Failure");
    util::sleep(5);

    util::clearScreen();
    QUICK_PRINT("Goodbye");
    util::sleep(5);

    util::clearScreen();
    std::cout.flush();
}

void handlePracticeWatermark(int difficulty)
{
    if (difficulty < 1)
    {
        std::cout << "PRACTICE MODE\n\n";
        std::cout << "The game is currently in practice mode, making whatever score was achieved non-genuine\n";
        std::cout << "This score does not affect the user's mathematical ability and should be treated as such\n\n";
    }
}

void displayResults(GameStatus state, int difficulty)
{
    int finalResult = getFinalResult(state.overall_points, state.questions_answered);
    std::string finalResultString = resultMessages[finalResult];

    util::clearScreen();

    std::cout << "Game over\n";
    std::cout << "=========\n\n";

    handlePracticeWatermark(difficulty);

    std::cout << "Rounds you lasted: " << state.rounds_completed << "\n";
    std::cout << "Points earned: " << state.overall_points << "\n";
    std::cout << "Questions answered: " << state.questions_answered << "\n";

    if (std::floor(state.percent_correct) >= 100)
    {
        std::cout << "Percentage of answers correct: 100%\n";
        std::cout << "Percent extra points: " << std::floor(state.percent_correct) - 100 << "%";
    }
    else
    {
        std::cout << "Percentage of answers correct: " << std::floor(state.percent_correct) << "%\n";
    }

    std::cout << "\n";
    std::cout << "Your result: " << finalResultString << "\n\n";
}

std::string getAcceptanceString(int difficulty)
{
    if (difficulty <= TRAINING_DIFFICULTY_THRESHOLD)
    {
        return "I accept my non-genuine, training result";
    }
    else
    {
        return "I accept my result";
    }
}

std::tuple<std::string, std::string> getPromptString(int counter)
{
    std::string beg = "";
    std::string end = "";

    // Beginning of prompt
    if (counter >= 10)
    {
        beg = "I'm bored, enter '";
        end = "' or I might just give up:";
    }
    else if (counter >= 5)
    {
        beg = "Just enter '";
        end = "' already, I won't exit until you do:";
    }
    else
    {
        beg = "Please enter '";
        end = "' to continue:";
    }

    return std::make_tuple(beg, end);
}

void resultAcceptance(int difficulty)
{

    std::string input = " ";
    std::string acceptanceString = "";

    int counter = 0;

    while (input != acceptanceString)
    {

        counter++;

        acceptanceString = getAcceptanceString(difficulty);

        std::tuple<std::string, std::string> promptString = getPromptString(counter);

        std::cout << std::get<0>(promptString) << acceptanceString << std::get<1>(promptString);
        std::getline(std::cin, input);
    }

    util::clearScreen();
}

OverallResult getFinalResult(int points, int questions)
{
#if ENCOURAGING != true
    double dec_points = (double)points;
    double dec_qs = (double)questions;

    double rate_correct = dec_points / dec_qs;

    if (points == 0)
    {
        return OverallResult::awful;
    }

    if (rate_correct >= 1.0)
    {
        return OverallResult::perfect;
    }
    else if (rate_correct >= 0.8)
    {
        return OverallResult::great;
    }
    else if (rate_correct >= 0.6)
    {
        return OverallResult::good;
    }
    else if (rate_correct >= 0.5)
    {
        return OverallResult::ok;
    }
    else if (rate_correct >= 0.25)
    {
        return OverallResult::bad;
    }
    else
    {
        return OverallResult::awful;
    }

#else
    return OverallResult::great;
#endif
}

void pausePriorExit()
{
    std::cout << "Press any key to continue...";
    std::getchar();
}

void gameExiting()
{

    std::cout.clear();

    std::cout << "Thanks for playing!\n";
    std::cout << "Please be sure to share the game for more players:\n https://github.com/OverEngineeredCode/Maths-Challenge-Quiz \n\n";

    pausePriorExit();
}

} // namespace scoring
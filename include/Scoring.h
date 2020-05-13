/* Maths challenge quiz
   Copyright Ethan Marshall - 2019

   Licensed under the GPL V.3.0
*/

#include <string>

#ifndef SCORING_HEADER
#define SCORING_HEADER

namespace scoring
{

    enum OverallResult
    {
        awful = 0,
        bad = 1,
        ok = 2,
        good = 3,
        great = 4,
        perfect = 5

    };

    const std::string resultMessages[6] = {"Awful",
                                           "Bad",
                                           "Ok",
                                           "Good",
                                           "Great",
                                           "Perfect"};

    struct GameStatus
    {
        int rounds_completed = 0;
        int overall_points = 0;
        int questions_answered = 0;

        double percent_correct;
    };

    void run_roundFailureCutscene();

    void handlePracticeWatermark(int difficulty);
    void displayResults(GameStatus state, int difficulty);

    std::string getAcceptanceString(int difficulty);
    std::tuple<std::string, std::string> getPromptString(int counter);

    void resultAcceptance(int difficulty);

    OverallResult getFinalResult(int points, int rounds);

    void gameExiting();

} // namespace scoring

#endif // header scoring.h
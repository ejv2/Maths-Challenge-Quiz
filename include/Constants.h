/* Maths challenge quiz
   Copyright Ethan Marshall - 2019

   Licensed under the GPL V.3.0
*/

// General constants
#define PROGRAM_NAME "Maths Challenge Quiz"
#define PROGRAM_DESCRIPTION                                                    \
	"Maths Challenge Quiz is a multi-stage, multi-ability level gauge of "     \
	"mathematical ability\nIt is open source and free for all, forever.\n"

#define VERSION_MAJOR 1
#define VERSION_MINOR 1
#define BUILD 0

// Build configuration
#define DEBUG false		  // Enables logging of debug information
#define ALWAYS_PASS false // Always pass the round, regardless of score
#define FIX_ROUND false	  // Fix the round type to one type for debugging
#define FIX_ROUND_TYPE                                                         \
	ArithmeticRound // If the above is true, what type of round should we fix to

#define ENCOURAGING                                                            \
	false // Disable random insults, and make the game more encouraging
#define DISABLE_SKIP_ROUNDS                                                    \
	false // Disable skip rounds, making the game faster and more challenging
#define NO_ROUND_WAIT false // Disable the 5 second wait between rounds

// General constants
#define BASE_MAX_QUESTIONS                                                     \
	15 // Suggestion as to how many questions should be in a round
#define MAX_ROUND_TYPES                                                        \
	7 // The number of rounds that should be accounted for in RNG calculations

#define IMPOSSIBLE_DIFFICULTY_THRESHOLD                                        \
	5 // The amount at which impossible difficulty will be applied
#define TRAINING_DIFFICULTY_THRESHOLD                                          \
	0 // The amount at which the training difficulty will be applied

#define INVALID_ANSWER                                                         \
	-1.5 // The answer that will be returned if an invalid answer was given

#define SKIP_ROUND_TIME                                                        \
	10 // The number of seconds that a skip round will last for
#define SPEED_ROUND_COUNTDOWN                                                  \
	5 // The number of seconds countdown before the beginning of a speed round

// Speed round scoring boundaries (the time to nearest whole to get boundary
// along with the associated points)
#define EXCELLENT 0
#define EXCELLENT_POINTS 4

#define GREAT 1
#define GREAT_POINTS 2

#define OK 2
#define OK_POINTS 1

#define POOR 3
#define POOR_POINTS 0

#define BAD
#define BAD_POINTS -1

/* Maths challenge quiz
   Copyright Ethan Marshall - 2019

   Licensed under the GPL V.3.0
*/

// General constants
#define PROGRAM_NAME "Maths Challenge Quiz"
#define PROGRAM_DESCRIPTION "Maths Challenge Quiz is a multi-stage, multi-ability level gague of mathematical ability\nIt is open source and free for all, forever.\n"

#define VERSION_MAJOR 1
#define VERSION_MINOR 0
#define BUILD 0

// Build configuration
#define DEBUG false       // Enables logging of debug information
#define ALWAYS_PASS false // Always pass the round, regardless of score
#define FIX_ROUND false   // Fix the round type to one type for debugging
#define FIX_ROUND_TYPE 0  // If the above is true, what type of round should we fix to

#define ENCOURAGING false         // Disable random insults, and make the game more encouraging
#define DISABLE_SKIP_ROUNDS false // Disable skip rounds, making the game faster and more challenging
#define NO_ROUND_WAIT false       // Disable the 5 second wait between rounds

// General constants
#define MAX_QUESTION_AMOUNT 15 // The maximum amount of questions possible in a round
#define MAX_ROUND_TYPES 4      // The amount of round types that can be selected

#define IMPOSSIBLE_DIFFICULTY_THRESHOLD 5 // The amount at which impossible difficulty will be applied
#define TRAINING_DIFFICULTY_THRESHOLD 0   // The amount at which the training difficulty will be applied

#define INVALID_ANSWER_FLOAT -1.5f // The answer that will be returned if an invalid answer was given

#define QUESTION_FORMAT_BEGINNING "Please enter the answer to " // The format that all questions will be delivered in
#define QUESTION_FORMAT_ENDING ":"                              // The end of the question string

// Speed round scoring boundries (the time to nearest whole to get boundry along with the associated points)
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
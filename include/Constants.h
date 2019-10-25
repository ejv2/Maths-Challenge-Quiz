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
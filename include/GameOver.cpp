/* Maths challenge quiz
   Copyright Ethan Marshall - 2019

   Licensed under the GPL V.3.0
*/

#include "GameOver.h"

#include <iostream>
#include <string>

namespace game_over
{

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

} // namespace game_over
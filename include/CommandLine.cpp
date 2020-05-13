/* Maths challenge quiz
   Copyright Ethan Marshall - 2019

   Licensed under the GPL V.3.0
*/

#include <string>
#include <iostream>

#include "CommandLine.h"
#include "Constants.h"
#include "Util.h"

namespace cmd
{

    void printBanner()
    {
        std::cout << "Maths Challenge Quiz\n";
        std::cout << "====================\n\n";

        std::cout << "A short, command-line game for testing and competing over mathematical ability\n";
        std::cout << "Written by Ethan Marshall\n";
    }

    void printVersion()
    {
        std::string version = util::getSemanticVersion(VERSION_MAJOR, VERSION_MINOR, BUILD);
        std::cout << "Maths Challenge Quiz - Version " << version << "\n";
    }

    void printCopyright()
    {
        std::cout << "Maths challenge Quiz\n";
        std::cout << "Copyright Ethan Marshall - 2010\n";
        std::cout << "Licensed under the GPL V.3\n";
    }

    void printLicence()
    {
        std::cout << "Maths Challenge Quiz - A short, command line maths game\n";
        std::cout << "Copyright (C) 2019  Ethan Marshall\n\n";

        std::cout << "This program is free software: you can redistribute it and/or modify\n \
                it under the terms of the GNU General Public License as published by\n \
                the Free Software Foundation,\n \
                either version 3 of the License, or (at your option) any later version.\n\n";

        std::cout << "This program is distributed in the hope that it will be useful,\n \
                but WITHOUT ANY WARRANTY; without even the implied warranty of\n \
                MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the\n \
                GNU General Public License for more details.\n\n";

        std::cout << "You should have received a copy of the GNU General Public License\n \
                along with this program. If not,\n \
                see <https: //www.gnu.org/licenses/>.\n\n";
    }

    void printWarranty()
    {
        std::cout << "Maths Challenge Quiz - A short, command line maths game\n";
        std::cout << "Copyright (C) 2019  Ethan Marshall\n\n";

        std::cout << "THERE IS NO WARRANTY FOR THE PROGRAM, TO THE EXTENT PERMITTED BY \n \
APPLICABLE LAW. EXCEPT WHEN OTHERWISE STATED IN WRITING THE COPYRIGHT \n \
HOLDERS AND / OR OTHER PARTIES PROVIDE THE PROGRAM 'AS IS' WITHOUT WARRANTY \n \
OF ANY KIND, EITHER EXPRESSED OR IMPLIED, INCLUDING, BUT NOT LIMITED TO, \n \
THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR \n \
PURPOSE.THE ENTIRE RISK AS TO THE QUALITY AND PERFORMANCE OF THE PROGRAM \n \
IS WITH YOU.SHOULD THE PROGRAM PROVE DEFECTIVE, YOU ASSUME THE COST OF \n \
ALL NECESSARY SERVICING, REPAIR OR CORRECTION.\n\n";

        std::cout << "IN NO EVENT UNLESS REQUIRED BY APPLICABLE LAW OR AGREED TO IN WRITING \
WILL ANY COPYRIGHT HOLDER, OR ANY OTHER PARTY WHO MODIFIES AND / OR CONVEYS \n \
THE PROGRAM AS PERMITTED ABOVE, BE LIABLE TO YOU FOR DAMAGES, \n \
INCLUDING ANY GENERAL, SPECIAL, INCIDENTAL OR CONSEQUENTIAL DAMAGES ARISING \n \
OUT OF THE USE OR INABILITY TO USE THE PROGRAM (INCLUDING BUT NOT LIMITED TO \n \
LOSS OF DATA OR DATA BEING RENDERED INACCURATE \n \
OR LOSSES SUSTAINED BY YOU OR THIRD PARTIES OR A FAILURE OF THE PROGRAM TO OPERATE \n \
WITH ANY OTHER PROGRAMS), EVEN IF SUCH HOLDER OR OTHER PARTY HAS BEEN ADVISED \n \
OF THE POSSIBILITY OF SUCH DAMAGES.\n";
    }

    void printHelp()
    {
        std::cout << "Maths Challenge Quiz - Help Menu\n\n";
        std::cout << "The Maths Challenge Quiz is a program designed to test a person's mathematical ability in a fun way\n";
        std::cout << "This game can be quite complicated, so help can be found in the 'readme.md' file included in the install\n\n";
    }

    void handleValueArgument(cmd_information *info, std::string arg)
    {
    }

    bool performStartupAction(std::string arg, cmd_information *info)
    {
        if (arg == "-h" || arg == "--help")
        {
            printHelp();
            return true;
        }
        else if (arg == "-w" || arg == "--warranty")
        {
            printWarranty();
            return true;
        }
        else if (arg == "-l" || arg == "--licence")
        {
            printLicence();
            return true;
        }
        else if (arg == "-c" || arg == "--copyright")
        {
            printCopyright();
            return true;
        }
        else if (arg == "-b" || arg == "--banner")
        {
            printBanner();
            return true;
        }
        else if (arg == "-v" || arg == "--version")
        {
            printVersion();
            return true;
        }

        return false;
    }

    bool handleCmdLine(char *argv[], int count, cmd_information *info)
    {
        bool shouldExit = false;

        for (int i = 1; i < count; i++)
        {
            shouldExit = shouldExit || performStartupAction(argv[i], info);
        }

        return shouldExit;
    }

} // namespace cmd
/* Maths challenge quiz
   Copyright Ethan Marshall - 2019

   Licensed under the GPL V.3.0
*/

#ifndef CMD_HEADER
#define CMD_HEADER

namespace cmd
{

struct cmd_information
{
};

bool handleCmdLine(char *argv[], int count, cmd_information *info);

void printBanner();
void printVersion();
void printCopyright();
void printLicence();
void printWarranty();
void printHelp();

} // namespace cmd

#endif
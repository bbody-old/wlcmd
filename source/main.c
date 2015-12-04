/* This file is part of Wlcmd.

Wlcmd is free software: you can redistribute it and/or modi
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

Wlcmd is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with Wlcmd.  If not, see <http://www.gnu.org/licenses/>.*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "../headers/wlcmd.h"
#include "../headers/error.h"
#include "../headers/help.h"

/* Commands */
Flag parseFlag(int argc, char ** argv, char ** command);
int showCommandInformation(char * command, Flag f);

int main(int argc, char ** argv, char **envp)
{
    Flag f = fError;
    char * command;

    /* Check there is at least one argument */
    if (!(argc > 1)){
        return error(eAttributes);
    }

    /* Check for help argument */
    if (help(argv[1]))
    {
        return showHelp();
    }

    /* Check if can open files */
    if (openFile() == eCommandFile)
    {
        return error(eCommandFile);
    }

    /* Check for correct number of arguments */
    if ((argc > 1) && (argc < 4))
    {
        /* Parse to see if there is a command flag */
        f = parseFlag(argc, argv, &command);

        /* Check that the description flag is valid */
        if (f == fError){
            return error(eFlag);
        }

        /* Print result if it is a valid command */
        if (showCommandInformation(command, f) == FAILURE){
            return error(eCommand);
        }
    } else {
        return error(eAttributes);
    }

    cleanup();

    return SUCCESS;
}

Flag parseFlag(int argc, char ** argv, char ** command){
    Flag f = fError;
    /* If has 2 arguments */
    if (argc == 3){
        /* Determine first is a flag */
        if (argv[1][0] == '-'){
            if (argv[1][1] == 'd'){
                f = fDes;
            } else {
                f = fNoDes;
            }
            *command = malloc(sizeof(char) * strlen(argv[2]));
            strcpy(*command, argv[2]);
        } else if (argv[2][0] == '-') { /* Second is flag */
            if (argv[2][1] == 'd'){
                f = fDes;
            } else {
                f = fNoDes;
            }
            *command = malloc(sizeof(char) * strlen(argv[1]));
            strcpy(*command, argv[1]);
        } else {
             f = fError;
        }
    } else if (argc == 2){ /* If only one */
        *command = malloc(sizeof(char) * strlen(argv[1]));
        strcpy(*command, argv[1]);
    }

    return f;
}

int showCommandInformation(char * command, Flag f){
    /* Get an index of both *nix and Window commands */
    int windowsIndex = getIndex(command, winCommands);
    int nixIndex = getIndex(command, nixCommands);

    if ((windowsIndex != -1) && (nixIndex != -1)){ /* If both have same com*/
        printf("Both: %s", desCommands[windowsIndex]);
        if (f == fDes){
            printf(" - %s", desCommands[windowsIndex]);
        }
    } else if (windowsIndex != -1){ /* If the command is a Windows command */
        printf("*nix: %s", nixCommands[windowsIndex]);
        if (f == fDes){
            printf(" - %s", desCommands[windowsIndex]);
        }
    } else if (nixIndex != -1){ /* If command is a *nix command */
        printf("Windows: %s", winCommands[nixIndex]);
        if (f == fDes){
            printf(" - %s", desCommands[nixIndex]);
        }
    } else { /* Not a recognised command */
        return FAILURE;
    }

    printf("\n");

    return SUCCESS;
}

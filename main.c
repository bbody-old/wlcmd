#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "wlcmd.h"
#include "error.h"

#define SUCCESS 0

/* Commands */
Flag parseFlag(char * flag);
int help(char * str);

int main(int argc, char ** argv, char **envp)
{
    /* Check there is at least one argument */
    if (!(argc > 1)){
        return error(eAttributes);
    }

    /* Check for help argument */
    if (help(argv[1]) == 0)
    {
        printf("Converts some commands between Windows and Linux.\n");
        printf("Usage: wlcmd [-h|-help|--help]\n       wlcmd [-d (Description)] <command>\nE.g. twlcmd ls -> Windows: dir\n     twlcmd -d ls -> Windows: dir - Lists files and directories\n");
        return SUCCESS;
    }

    /* Check if can open files */
    if (openFile() == eCommandFile)
    {
        return error(eCommandFile);
    }

    /* Check for correct number of arguments */
    if ((argc > 1) && (argc < 4))
    {
        int index = 1;
        Flag f = fInvalid;
        char * command;
        int windowsIndex;
        int nixIndex;

        /* If has 2 arguments */
        if (argc == 3){
            /* Determine first is a flag */
            if (argv[1][0] == '-'){
                if (argv[1][1] == 'd'){
                    f = fDes;
                } else {
                    f = fInvalid;
                }
                command = malloc(sizeof(char) * strlen(argv[2]));
                strcpy(command, argv[2]);
            } else if (argv[2][0] == '-') { /* Second is flag */
                if (argv[2][1] == 'd'){
                    f = fDes;
                } else {
                    f = fInvalid;
                }
                command = malloc(sizeof(char) * strlen(argv[1]));
                strcpy(command, argv[1]);
            } else {
                 return error(eAttributes);
            }
        } else if (argc == 2){ /* If only one */
            command = malloc(sizeof(char) * strlen(argv[1]));
            strcpy(command, argv[1]);
        }

        /* Get an index of both *nix and Window commands */
        windowsIndex = getIndex(command, winCommands);
        nixIndex = getIndex(command, nixCommands);

        if ((windowsIndex != -1) && (nixIndex != -1)){ /* If both have same com*/
            printf("Both: %s", argv[index]);
            if (f == fDes){
                printf(" - %s", desCommands[windowsIndex]);
            }
            printf("\n");
        } else if (windowsIndex != -1){ /* If the command is a Windows command */
            printf("*nix: %s", nixCommands[windowsIndex]);
            if (f == fDes){
                printf(" - %s", desCommands[windowsIndex]);
            }
            printf("\n");
        } else if (nixIndex != -1){ /* If command is a *nix command */
            printf("Windows: %s", winCommands[nixIndex]);
            if (f == fDes){
                printf(" - %s", desCommands[nixIndex]);
            }
            printf("\n");
        } else { /* Not a recognised command */
            return error(eCommand);
        }
    }
    else
    {
        return error(eAttributes);
    }
    cleanup();
    return SUCCESS;
}



/* help
 * Checks if a help flag is entered.
 */
int help(char * str){
    int i = 0;
    for (i = 0; str[i] != '\0'; i++){
        str[i] = tolower(str[i]);
    }

    if ((strcmp(str, "help") == 0) || (strcmp(str, "-h") == 0)||
        (strcmp(str, "-help") == 0) || (strcmp(str, "-help") == 0)){
        return 0;
    } else {
        return -1;
    }
}



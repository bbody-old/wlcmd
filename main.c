#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "wlcmd.h"
#include "error.h"

// Commands
Flag parseFlag(char * flag);
int help(char * str);

int main(int argc, char ** argv, char **envp)
{
    // Check there is at least one argument
    if (!(argc > 1)){
        return error(eAttributes);
    }

    // Check for help argument
    if (help(argv[1]) == 0)
    {
        printf("Converts some commands between Windows and Linux.\n");
        printf("Flags:\n\t -h  Help\n\t -n  *Nix\n\t\ -w  Windows\n\t -d Description\n");
        return 0;
    }

    // Check if can open files
    if (openFile() == eCommandFile)
    {
        return error(eCommandFile);
    }

    // Check for correct number of arguments
    if ((argc > 2) && (argc < 5))
    {
        int index = 1;

        // Determine first flag
        Flag flag = parseFlag(argv[index]);
        index = index + 1;

        // Check if there is another flag for description
        if (strcmp(argv[index], DES) == 0)
        {
            index = index + 1;

            if (flag == fNix)
            {
                flag = fNixDes; // Add description tag
            }
            else if (flag == fWindows)
            {
                flag = fWindowsDes; // Add description tag
            }
        }
        if (argv[index] != NULL)
        {
            char * command = argv[index];

            return commandTranslator(command, flag);
        }
        else
        {
            return error(eAttributes);
        }
    }
    else
    {
        return error(eAttributes);
    }
    cleanup();
}

/* parseFlag
 * Checks what flag has been entered.
 */
Flag parseFlag(char * flag)
{
    if (strcmp(flag, NIX) == 0)
    {
        return fNix;
    }
    else if (strcmp(flag, WINDOWS) == 0)
    {
        return fWindows;
    }
    else if (strcmp(flag, NIXDES) == 0)
    {
        return fNixDes;
    }
    else if (strcmp(flag, WINDOWSDES) == 0)
    {
        return fWindowsDes;
    }
    else
    {
        return fInvalid;
    }
}

/* help
 * Checks if a help flag is entered.
 */
int help(char * str){
    int i = 0;
    for (i = 0; str[i] != '\0'; i++){
        str[i] = tolower(str[i]);
    }

    if (strcmp(str, "help") == 0){
        return 0;
    } else if(strcmp(str, "-h") == 0){
        return 0;
    } else {
        return -1;
    }
}



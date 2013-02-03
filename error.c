#include <stdio.h>
#include "error.h"
#include "wlcmd.h"

/* error
 * Prints out a message and returns and error code depending on the error code
 * given.
 */
int error(ErrorCode errorCode)
{
    cleanup();
    if (errorCode == eFlag)
    {
        printf("Error: Invalid flag. Windows -w, *nix -n, Description -d.\n");
        return -1;
    }
    else if (errorCode == eAttributes)
    {
        printf("Error: Incorrect number of arguments, need at least 2-3 arguments\n");
        return -2;
    }
    else if (errorCode == eCommandFile)
    {
        printf("Error: Command file could not formatted correctly.\n");
        return -3;
    }
    else if (errorCode == eCommand)
    {
        printf("Error: Command not found.\n");
        return -4;
    }

    printf("Error: Unknown error.\n");
    return -100;
}

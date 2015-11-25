/*This file is part of Wlcmd.

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
#include "../headers/error.h"
#include "../headers/wlcmd.h"

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

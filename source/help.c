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
#include "../headers/help.h"
#include "../headers/error.h"

/* help
 * Checks if a help flag is entered.
 */
int help(char * str){
    int i = 0;
    for (i = 0; str[i] != '\0'; i++){
        str[i] = (char)tolower(str[i]);
    }

    if ((strcmp(str, "help") == 0) || (strcmp(str, "-h") == 0)||
        (strcmp(str, "-help") == 0) || (strcmp(str, "-help") == 0)){
        return 1;
    } else {
        return 0;
    }
}

/* showHelp
 * Prints out help information.
 */
int showHelp(void){
    printf("Converts some commands between Windows and *nux.\n");
        printf("Usage: wlcmd [-h|-help|--help]\n"
            "\t wlcmd [-d (Description)] <command>\n"
            "E.g. wlcmd ls -> Windows: dir\n"
            "\t wlcmd -d ls -> Windows: dir - Lists files and directories\n");
    return SUCCESS;
}

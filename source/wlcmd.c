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
#include "../headers/wlcmd.h"
#include "../headers/error.h"

#define COMMANDFILENAME "./commands.txt"
#define TOKENIZER ";"
#define DIVIDER ';'
#define LINELENGTH 2048
#define ENTRYLENGTH 256

/* Variables */
char ** nixCommands;
char ** winCommands;
char ** desCommands;
int sizeCommands;

/* Functions */
int getIndex(char * command, char ** list);
void stringToArray(char * str, char ** array);
int openFile(void);
int countEntries(char * str);

/* getIndex
 * Searches through commands until it finds your specific command.
 */
int getIndex(char * command, char ** list)
{
    int i = 0;
    for (i = 0; i < sizeCommands; i++)
    {
        if (strcmp(list[i], command) == 0)
        {
            return i;
        }
    }
    return -1;
}


/* stringToArray
 * Turns a string split by a token into an array.
 */
void stringToArray(char * str, char ** array)
{
    int i = 0;
    char * pch;
    pch = strtok(str, TOKENIZER);

    while (pch != NULL)
    {
        strcpy(array[i], pch);
        i = i + 1;
        if (i >= sizeCommands)
        {
            pch = NULL;
        }
        else
        {
            pch = strtok(NULL, TOKENIZER);
        }
    }
}

/* countEntries
 * Counts how many instances of a token is in a string.
 */
int countEntries(char * str)
{
    int i = 0;
    int count = 0;
    for (i = 0; str[i] != '\0'; i++)
    {
        if (str[i] == DIVIDER)
        {
            count++;
        }
    }
    return count;
}

/* stringToArray
 * Turns a string split by a token into an array.
 */
int openFile(void)
{
    int i = 0;
    char line[LINELENGTH];
    FILE * fp = fopen(COMMANDFILENAME, "r");
    sizeCommands = 0;

    /* Windows Commands */
    if (fgets(line, sizeof(line),fp) != NULL)
    {
        /* Get the size of the array */
        sizeCommands = countEntries(line);

        /* Dynamically allocate array */
        winCommands = (char **)malloc(sizeof(char*) * (unsigned long)sizeCommands);
        for (i = 0; i < sizeCommands; i++)
        {
            winCommands[i] = malloc(sizeof(char) * ENTRYLENGTH);
        }

        /* Assign string to array */
        stringToArray(line, winCommands);
    }
    else
    {
        fclose(fp);
        return eCommandFile;
    }

    /* Linux Commands */
    if (fgets(line, sizeof(line),fp) != NULL)
    {
        /* Dynamically allocate array */
        nixCommands = (char **)malloc(sizeof(char*) * (unsigned long)sizeCommands);
        for (i = 0; i < sizeCommands; i++)
        {
            nixCommands[i] = malloc(sizeof(char) * ENTRYLENGTH);
        }

        /* Assign string to array */
        stringToArray(line, nixCommands);
    }
    else
    {
        fclose(fp);
        return eCommandFile;
    }

    /* Command descriptions */
    if (fgets(line, sizeof(line),fp) != NULL)
    {
        /* Dynamically allocate array */
        desCommands = (char **)malloc(sizeof(char*) * (unsigned long)sizeCommands);
        for (i = 0; i < sizeCommands; i++)
        {
            desCommands[i] = malloc(sizeof(char) * ENTRYLENGTH);
        }

        /* Assign string to array */
        stringToArray(line, desCommands);
    }
    else
    {
        fclose(fp);
        return eCommandFile;
    }

    fclose(fp);
    return eSuccess;
}

/* cleanup
 * Cleans up dynamically allocated variables.
 */
void cleanup(void)
{
    int i = 0;
    if (winCommands != NULL)
    {
        for (i = 0; i < sizeCommands; i++)
        {
            free(winCommands[i]);
        }
        free(winCommands);
    }

    if (nixCommands != NULL)
    {
        for (i = 0; i < sizeCommands; i++)
        {
            free(nixCommands[i]);
        }
        free(nixCommands);
    }

    if (desCommands != NULL)
    {
        for (i = 0; i < sizeCommands; i++)
        {
            free(desCommands[i]);
        }
        free(desCommands);
    }
}

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

#ifndef WLCMD_H_INCLUDED
#define WLCMD_H_INCLUDED
#define NIX "-n"
#define WINDOWS "-w"
#define NIXDES "-nd"
#define WINDOWSDES "-wd"
#define DES "-d"

typedef enum
{
    fDes,
    fInvalid
} Flag;

/* Variables */
char ** nixCommands;
char ** winCommands;
char ** desCommands;
int sizeCommands;

/* Exposed functions */
int commandTranslator(char * command, Flag flag);
int getIndex(char * command, char ** list);
int openFile();
void cleanup();

#endif /* WLCMD_H_INCLUDED */

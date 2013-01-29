#ifndef WLCMD_H_INCLUDED
#define WLCMD_H_INCLUDED
#define NIX "-n"
#define WINDOWS "-w"
#define NIXDES "-nd"
#define WINDOWSDES "-wd"
#define DES "-d"

typedef enum
{
    fNix,
    fWindows,
    fNixDes,
    fWindowsDes,
    fInvalid
} Flag;

// Variables
char ** nixCommands;
char ** winCommands;
char ** desCommands;
int sizeCommands;

// Exposed functions
int commandTranslator(char * command, Flag flag);
int openFile();
void cleanup();

#endif // WLCMD_H_INCLUDED

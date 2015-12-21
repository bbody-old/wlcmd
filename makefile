all:
	gcc -lm -std=c89 -pedantic -O3 -DNDEBUG -funroll-loops \
	source/error.c source/wlcmd.c source/help.c source/main.c -o wlcmd

dev:
	gcc -Wall -Wextra -Wformat=2 -Wswitch-default -Wcast-align -Wpointer-arith \
    -Wbad-function-cast -Wstrict-prototypes -Winline -Wundef -Wnested-externs \
    -Wcast-qual -Wshadow -Wwrite-strings -Wconversion -Wunreachable-code \
    -Wstrict-aliasing=2 -fno-common -fstrict-aliasing \
    -lm -std=c89 -pedantic -O0 -ggdb3 -pg --coverage \
    source/error.c source/wlcmd.c source/help.c source/main.c -o wlcmd

clean:
	$(RM) wlcmd

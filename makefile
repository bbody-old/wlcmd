release_osx:
	mkdir release_osx
	gcc -lm -std=c89 -pedantic -O3 -DNDEBUG -funroll-loops \
	source/error.c source/wlcmd.c source/help.c source/main.c -o release_osx/wlcmd
	cp commands.txt release_osx/commands.txt
	tar -czvf release_osx.tar.gz release_osx/*
release_linux:
	mkdir release_linux
	gcc -lm -std=c89 -pedantic -O3 -DNDEBUG -funroll-loops \
	source/error.c source/wlcmd.c source/help.c source/main.c -o release_linux/wlcmd
	cp commands.txt release_linux/commands.txt
	tar -czvf release_linux.tar.gz release_linux/*
release_windows:
	mkdir release_windows
	dir
	pwd
	gcc -lm -std=c89 -pedantic -O3 -DNDEBUG -funroll-loops \
	source/error.c source/wlcmd.c source/help.c source/main.c -o release_windows/wlcmd.exe
	copy commands.txt release_windows
	Compress-Archive -Path release_windows\*
dev:
	mkdir bin
	gcc -Wall -Wextra -Wformat=2 -Wswitch-default -Wcast-align -Wpointer-arith \
    -Wbad-function-cast -Wstrict-prototypes -Winline -Wundef -Wnested-externs \
    -Wcast-qual -Wshadow -Wwrite-strings -Wconversion -Wunreachable-code \
    -Wstrict-aliasing=2 -fno-common -fstrict-aliasing \
    -lm -std=c89 -pedantic -O0 -ggdb3 -pg --coverage \
    source/error.c source/wlcmd.c source/help.c source/main.c -o bin/wlcmd
clean:
	$(RM) bin/wlcmd
	-rm -f bin/*.out
	-rm -f bin/*.gcno
	-rm -r bin/wlcmd.dSYM
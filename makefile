all:
	gcc -std=c89 source/error.c source/wlcmd.c source/help.c source/main.c -o wlcmd
clean:
	$(RM) wlcmd

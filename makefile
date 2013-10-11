all:
	gcc error.c wlcmd.c main.c -o wlcmd
clean:
	$(RM) wlcmd

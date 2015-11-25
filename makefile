all:
	gcc source/error.c source/wlcmd.c source/main.c -o wlcmd
clean:
	$(RM) wlcmd

# Introduction

wlcmd - Windows/*Nix Commands

A tool I made so I could get equivalent commands of some *Nix and Windows commands. 
Written in C89. Has been tested on Windows 7 (64-bit), Ubuntu and Mac OSX.

## Screenshot

![alt text](https://s3-ap-southeast-2.amazonaws.com/bbody-images/github/wlcmd/screenshot.png "Command line screenshot of wlcmd")

## Executable

A Windows Executable found [here](https://github.com/bbody/wlcmd/releases/latest).

# Usage

Converts some commands between Windows and Linux.

## Help
Usage: wlcmd [-h|-help|--help]

### Example Command
`wlcmd -help`

### Output
```
Converts some commands between Windows and *nux.
Usage: wlcmd [-h|-help|--help]
	 wlcmd [-d (Description)] <command>
E.g. wlcmd ls -> Windows: dir
	 wlcmd -d ls -> Windows: dir - Lists files and directories
```


## Full descriptions
Usage: wlcmd [-d (Description)] command


### Example Command

`wlcmd -d ls`


### Output

`Windows: dir - Lists files and directories`

## Verbose
Usage: wlcmd command

### Example Command

`wlcmd dir`

### Output

`*nix: ls`


# Build


## GCC

`gcc -std=c89 source/error.c source/wlcmd.c source/help.c source/main.c -o wlcmd`


## Clang

`clang -std=c89 source/error.c source/wlcmd.c source/help.c source/main.c -o wlcmd`


## Makefile


### Compile

`make`


### Clean

`make clean`

## Add to command line

### *nix
1. `git clone git@github.com:bbody/wlcmd.git`
2. `cd wlcmd`
3. `make`
4. `mkdir ~/bin`
5. `cp wlcmd ~/bin/`
6. `vim ~/.profile`
7. Add the following line at the bottom
	1. `export PATH="/home/$USER/bin:$PATH"`
	2. `export PATH=.:$PATH`
8. `source ~/.bashrc`
9. `source ~/.profile`

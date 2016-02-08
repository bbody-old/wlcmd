# Introduction

wlcmd - Windows/*Nix Commands

A tool I made so I could get equivalent commands of some *Nix and Windows commands. 
Written in C89. Has been tested on Windows 7 (64-bit), Ubuntu and Mac OSX.

Inspired by my blog article [Windows and *nix command equivalents](http://www.brendonbody.com/2013/01/28/windows-and-nix-command-equivalents/)

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
``` Converts some commands between Windows and *nux.
Usage: wlcmd [-h|-help|--help]
	 wlcmd [-d (Description)] <command>
E.g. twlcmd ls -> Windows: dir
	 twlcmd -d ls -> Windows: dir - Lists files and directories```

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

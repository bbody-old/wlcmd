# Introduction

wlcmd - Windows/*Nix Commands

A tool I made so I could get equivalent commands of some *Nix and Windows commands. 
Written in C89. Has been tested on Windows 7 (64-bit), Ubuntu and Mac OSX.

Inspired by my blog article [Windows and *nix command equivalents](http://www.brendonbody.com/2013/01/28/windows-and-nix-command-equivalents/)

A Windows Executable found [here](https://github.com/bbody/wlcmd/releases/latest).

# Screenshot

![alt text](http://www.brendonbody.com/wp-content/uploads/2013/01/Screen-Shot-2015-11-29-at-7.47.14-am.png "Command line screenshot of wlcmd")

# Manual

Converts some commands between Windows and Linux.

Usage: wlcmd [-h|-help|--help]

<t>wlcmd [-d (Description)] <command><br />
E.g. twlcmd ls -> Windows: dir<br />
<t>twlcmd -d ls -> Windows: dir - Lists files and directories<br />
<h2>Build</h2>
<h3>GCC</h3>
<pre>gcc -std=c89 source/error.c source/wlcmd.c source/help.c source/main.c -o wlcmd</pre>
<h3>Clang</h3>
<pre>clang -std=c89 source/error.c source/wlcmd.c source/help.c source/main.c -o wlcmd</pre>
<h3>Makefile</h3>
<h4>Compile</h4>
<pre>make</pre>
<h4>Clean</h4>
<pre>make clean</pre>


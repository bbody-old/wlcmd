<h2>Introduction</h2>
wlcmd - Windows/*Nix Commands</br>
<p>A tool I made so I could get equivalent commands of some *Nix and Windows commands. 
Written in Windows using Code::Blocks and in C (ANSI Compliant). Has been tested on Windows 7 (64-bit), Ubuntu and Mac OSX.</p>
Inspired by my blog article <a href="http://www.brendonbody.com/2013/01/28/windows-and-nix-command-equivalents/">Windows and *nix command equivalents</a><br/>
A Windows Executable found <a href="http://www.brendonbody.com/releases/wlcmd-win-exe.zip">here</a>.
<h2>Manual</h2>
<p>Converts some commands between Windows and Linux.</p>
Usage: wlcmd [-h|-help|--help]<br />
<t>wlcmd [-d (Description)] <command><br />
E.g. twlcmd ls -> Windows: dir<br />
<t>twlcmd -d ls -> Windows: dir - Lists files and directories<br />
<h2>Build</h2>
<h3>GCC</h3>
<pre>gcc error.c wlcmd.c main.c -o wlcmd</pre>
<h3>Makefile</h3>
<h4>Compile</h4>
<pre>make</pre>
<h4>Clean</h4>
<pre>make clean</pre>
<h3>Codeblocks</h3>
1. Open Codeblocks project file in Codeblocks
2. Build

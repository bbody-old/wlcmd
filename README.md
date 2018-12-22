[![Build Status](https://travis-ci.org/bbody/wlcmd.svg?branch=master)](https://travis-ci.org/bbody/wlcmd)

# wlcmd - Windows/\*Nix Command Dictionary

**Note:** This project has been archived as I don't use it or actively develop.

A tool I made so I could get equivalent commands of some \*Nix and Windows commands. I developed when I was using a Windows computer and I needed to know Windows commands.

Written in C89 with very conservative flags.

Has been tested on:

* Windows 7 (64-bit)
* Ubuntu
* Mac OSX.

![alt text](https://raw.githubusercontent.com/bbody/wlcmd/master/screenshot.png "Command line screenshot of wlcmd")

## Usage

Converts some commands between Windows and Linux.

### Basic
Usage: `wlcmd command`

Flags:

* Description: [-d]
* Help: [-h | -help | --help]

#### Examples
##### Basic
`wlcmd dir`

###### Output

```
*nix: ls
```

##### With Description

`wlcmd -d ls`

###### Output

```
`Windows: dir - Lists files and directories`
```

##### Help

`wlcmd -help`

###### Output

```
Converts some commands between Windows and *nux.
Usage: wlcmd [-h|-help|--help]
	 wlcmd [-d (Description)] <command>
E.g. wlcmd ls -> Windows: dir
	 wlcmd -d ls -> Windows: dir - Lists files and directories
```

## Executables

Executables can be found in [Github releases](https://github.com/bbody/wlcmd/releases/latest).

**Note:** Use of this software is at own as is without any warranty.

## Development

Run the following command

### Build
`make dev`

### Clean

`make clean`

# Maths Challenge Quiz

The Maths Challenge Quiz is a short, hobby command line game for testing a person's mathematical ability. It is open source, free and always will be. Being licensed under a permissive GPL licence, you are free to change, redistribute and build the project wherever and for whatever purpose. Please read the licence text for more information.

It was originally created as a school project, but quickly became a full game.

The game was originally written in Small Basic (http://smallbasic.com), but that version of the game was too slow and limited. This repository is a C++ port of the game.

The game was originally designed as a simple test of mathematical ability.

# General usage

## Installation/Use

The program does not need to be installed, and can be run by executing the executable file generated in the build folder.

## Building the program

To build the program, you must be running on Linux (you can cross compile for windows using the makefile). If you only have access to windows, you should consider installing WSL.

To build:

1. Navigate to the project root
1. Execute ``make`` on Linux or mac, or ``make windows`` to build for windows
1. You will find the appropriate executable under **/build**

## Playing the game

More detailed instructions can be found in ``Instructions.md``

# Contributing

Any contributions are greatly appreciated and will most likely be accepted into the project promptly.

## How to get involved

Please see the contributing guidelines and code of conduct for more information on the specifics of contributing.

If you find an issue that you can't/don't want to fix yourself, please open an issue. Even if it's something small, please make me aware of it.

If you find an issue that you feel like you can fix (and that you are prepared to fix), please open a pull request with the wished changes so that it can be approved and merged.

## Branches

In the project there are two branches you should be aware of:

1. **master:** This branch is similar to a release/stable branch. If you want to install the project, please get the code from here.
1. **dev:** This branch is where changes will be pushed as they happen. Unless a commit is an urgent or small change, changes will be rarely pushed straight to master, so they all end up here. Pull requests will always be merged here.

If you want to make a PR on the repository, please make your changes on the dev branch. If your change is a security fix, it may be merged straight to master. For more info, please see the security policy.

## Support/Maintainence

This project is under active development, meaning that it will not reach end-of-life or end development any time soon. Even if no commits have come in for a while, the project is most likely just waiting to be pushed (or something big is coming).

I will perform regular maintainence on the codebase. For example, the testing framework used may need to be updated, or a new default compiler may be enabled in the makefile. This will be handled *solely by the owner*. No PRs will be merged that change this. Issues that remind about this may also be closed without action.

<hr>

*Maths challenge quiz, By Ethan Marshall* Copyright 2019, Licensed under GNU public license

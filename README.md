# Maths Challenge Quiz

[![Build Status](https://travis-ci.org/OverEngineeredCode/Maths-Challenge-Quiz.svg?branch=master)](https://travis-ci.org/OverEngineeredCode/Maths-Challenge-Quiz)
![GitHub issues](https://img.shields.io/github/issues/OverEngineeredCode/Maths-Challenge-Quiz)
![GitHub pull requests](https://img.shields.io/github/issues-pr/OverEngineeredCode/Maths-Challenge-Quiz)
![GitHub](https://img.shields.io/github/license/OverEngineeredCode/Maths-Challenge-Quiz)

<hr>

The Maths Challenge Quiz is a short, hobby command line game for testing a person's mathematical ability. It is open source, free and always will be. Being licensed under a permissive GPL licence, you are free to change, redistribute and build the project wherever and for whatever purpose. Please read the licence text for more information.

It was originally created as a school project, but quickly became a full game.

The game was originally written in Small Basic (http://smallbasic.com), but that version of the game was too slow and limited. This repository is a C++ port of the game.

The game was originally designed as a simple test of mathematical ability.

# General usage

## Installation/Use

The program does not need to be installed, and can be run by executing the executable file generated in the build folder.

## Building the program

> **Note:** Since version 1.0, the project has transitioned to `cmake` for cross-platform support. If you wish to use the legacy build system or cannot use cmake, please refer to the build guide for further instructions.

The game can be built for whatever build system you have available using `cmake`. Obviously, this means cmake is required to build. Please obtain a copy [here](https://cmake.org/download/).

To generate tools for your native build system, navigate to the root of the project and run `cmake .` This will create tools required to make the project. Then, you'll have either a makefile, editor project or other build system. Use the tools installed to build. For example, on Linux, you will most likely want to run `make` next.

On windows, you will require either Visual Studio 2017 or later - or the windows SDK + build tools installed.

For windows, the executable will be placed in the _build_ directory. However, when using makefiles or Visual Studio, generated files will be placed either in the root or in another directory.

## Playing the game

More detailed instructions can be found in `Instructions.md`

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

I will perform regular maintainence on the codebase. For example, the testing framework used may need to be updated, or a new default compiler may be enabled in the makefile. This will be handled _solely by the owner_. No PRs will be merged that change this. Issues that remind about this may also be closed without action.

<hr>

_Maths challenge quiz, By Ethan Marshall_ Copyright 2019, Licensed under GNU public license

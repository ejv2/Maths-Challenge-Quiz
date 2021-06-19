# Maths Challenge Quiz

[![Build Status](https://travis-ci.org/ethanv2/Maths-Challenge-Quiz.svg?branch=master)](https://travis-ci.org/OverEngineeredCode/Maths-Challenge-Quiz)
![GitHub issues](https://img.shields.io/github/issues/ethanv2/Maths-Challenge-Quiz)
![GitHub pull requests](https://img.shields.io/github/issues-pr/ethanv2/Maths-Challenge-Quiz)
![GitHub](https://img.shields.io/github/license/ethanv2/Maths-Challenge-Quiz)

---

The Maths Challenge Quiz is a short, hobby command line game for testing a person's mathematical ability. It is open source and completely free, being licensed under the GPL

The game was originally written in a programming language designed for schools called *Small Basic*, a somewhat annoying Visual Basic derivative. I liked some of the parts of the game, so I decided to port it to C++. This is the result.

The original version of the game is available in the "historic/" directory, in source code format.

## General usage

### Installation/Use

To get started, you will either want to download or build the program. If you do not intend to change the code of the program and your platform is supported for official builds, you will want to download a copy. However, if you are unable to download a copy, you can download the code by cloning the repository and build using the instructions below.

Your system does not require a GUI to run the game. However, a working terminal/command prompt is required.

### Building the program

> **Note:** To build the program, you will either need to install *cmake* or refer to the legacy build instructions.

For the majority of platforms, you will be able to build the project by simply configuring and building using cmake. To do so, navigate to the project root and run `cmake .`. This will configure the project to be built on your platform.

Having done this, you can either use your native build tools, or let cmake figure it out for you by running `cmake --build .`

After this has completed, you should have an executable generated in the destination that you configured cmake to write build files.

It is important to note that when contributing, *none* of your cmake files or built executable may be included in the index. For this reason, we recommend configuring cmake to write build files to the *build* directory, which is ignored in the gitignore file.

### Playing the game

The game is designed to have easy mechanics for anybody to play with. However, if you require extra assistance, please refer to `Instructions.md` in the root of the project.

## Contributing

Any contributions are greatly appreciated and will most likely be accepted into the project promptly.

### How to get involved

Please see the contributing guidelines and code of conduct for more information on the specifics of contributing.

If you find an issue that you can't/don't want to fix yourself, please open an issue. Even if it's something small, please make me aware of it.

If you find an issue that you feel like you can fix (and that you are prepared to fix), please open a pull request with the wished changes so that it can be approved and merged.

### Branches

In the project there are a few branch types and names you should be aware of:

1. **master:** This branch is similar to a release/stable branch. If you want to install the project, please get the code from here.
1. **dev:** This branch is where changes will be pushed as they happen. Unless a commit is an urgent or small change, changes will be rarely pushed straight to master, so they all end up here. Pull requests will always be merged here, so please request a merge to dev.
1. **\*-code-cleanup:** Occasionally, code will get messy. To perform a cleanup, a new branch will be made. This will only be merged to dev once it is completely ready.
1. **Something else:** Specific features or big changes may be sandboxed in their own branch. In this case, a new branch will be created.

If you want to make a PR on the repository, please make your changes on the dev branch. If your change is a security fix, it may be merged straight to master. For more info, please see the security policy.

### Support/Maintenance

This project is under active development, meaning that it will not reach end-of-life or end development any time soon. Even if no commits have come in for a while, the project is most likely just waiting to be pushed (or something big is coming).

I will perform regular maintenance on the codebase. For example, the testing framework used may need to be updated, or a new default compiler may be enabled in the makefile. This will be handled _solely by the owner_. No PRs will be merged that change this. Issues that remind about this may also be closed without action.

---

_Maths challenge quiz, By Ethan Marshall_ Copyright 2019, Licensed under GNU public license 3.0

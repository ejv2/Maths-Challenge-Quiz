# Welcome to the Project! - Contributing guidelines for Maths Challenge Quiz

Welcome to the MCQ project! Thank you for taking the time to contribute and for showing interest in the project.

Before you get started with making the project better for yourself and the whole community, please take the time to read these guidelines if you haven't done so already. This ensures that you will fit in with the community and be successful in whatever your goal is.

# Contribution guidelines

> **Tip:** Many of the rules set out here are also set out in the code of conduct. Please see that too when you get a chance.

Everyone contributing to the project *in any way*, be it through PRs, issues, forks or comments is expected to have read and understood these guidelines. Although the project is not huge, it is still important that all contributors work together in a unified manor. Following these rules may make your contribution get attention quicker and get added to the project quicker.

## Please help! I contributed before reading!

*Don't panic!* And especially don't withdraw your contribution. Most of the rules set out here are generally followed by users of GitHub, meaning that you probably followed them anyway. However, if you think you may have broken a rule, it may be a good idea for you to edit whatever contribution you made to follow that rule.

That said, there is no penalty for breaking the guidelines set out, just try to stick to them where possible.

## I have a question

> **Important:** Please do not use the issues board to ask questions about contribution. If you do, your question will probably not get answered for a while or by an official maintainer. Please use the advice below.

The project is way to small to facilitate individual questions, but please ask a maintainer or the owner if you have a question.

## Third-party libraries and code

There are certain parts of the project that are sourced from other locations. It is **very important** that you ensure that changes proposed to these parts of the code are sent to the apropriate maintainers of those projects.

> **Tip:** That doesn't mean don't remind us to update something! If our libraries are out of date, please tell us to update them. Security and stability is important!

# Issues, Pull requests and forks

These four elements are the main ways to contribute to the project.

## Issues

If you have found a problem that fits the following criterea, please open an issue:

1. You have found an issue that you cannot fix yourself
1. You have found an issue that you do not want to fix yourself
1. You have found an issue that you don't know how to fix yourself/you do not know the cause of
1. You have a suggestion to improve the project that is not simple enough to fix from some code tweaks
1. You have a suggestion to improve the project that you do not want to perform yourself

Issues are not looked at as frequently as pull requests, meaning that anything you want fixing urgently that you are prepared to fix yourself should probably be a PR. However, please *do not* feel obligated to do anything yourself. Any input is appreciated, and issues are just as valuable as pull requests.

> **Tip:** A descriptive and clear title to an issue may result in it being dealt with faster.

Tags may be added to your issue to aid in development. Please add or remove any as you see fit.

## Pull requests

Pull requests are the backbone of the project. If you have made a change to your copy of the project that you think is universal enough to be shared globally, please open a pull request!

Pull requests are reviewed regularly and we will merge many of them.

> **Tip:** For security and quality control, we must review all changes made in a pull request. So, adding a descriptive and clear title may make your change more likely to be merged quickly. Clear titles *are* important!

Tags will be used in a similar fashion to in issues.

Please make sure your code is up to scratch by looking at the code styling tips!

## Forks

Please, make as many forks as you like!

Forks are important to us, as we can see what kinds of things the community is doing with the project.

Merges with forks may take more time than straight changes to the project in a pull request.

Before requesting a merge, please make sure that your edition of MCQ is up to date and that the changes are universal enough to be merged. If your fork is for a specific purpose (such as changing to a literacy quiz or making the questions about calculus), your may be denied permission to merge.

# Project structure

## Building

All code necessary to build is contained in a makefile in the root. This is where you need to go too improve building.

Build output is, by default, in the build folder. If it is not, that is a bug and should be reported.

> **Important:** You must have access to Linux to build. If you can only use Windows, please consider installing WSL. For more information, see [this](https://docs.microsoft.com/en-us/windows/wsl/install-win10).

## Testing

We test the project by unit tests, meaing that we do have testing scripts. These scripts are written in C++, but compile cleanly as C. All of this infrastructure is contained in the test folder.

We use a 3rd party testing framework to test. The licence for this framework is included with its source. It is contained in a single header in the test folder. Any further information can be found in that file.

## Includes

All project includes (yes, that means headers and implementations) are located in the include folder. Most of the code for the project is located in there.

## The main file

The entry-point for the codebase is located in Main.cpp. This is in the project root. We try to keep this file as minimal as possible, so please try to upkeep that style.

# Quality control

## Code styling

For code styling, we use standard, community agreed standards. However, if you are unsure of how these standards affect your code, we recommend the Prettier VSCode extension, available [here](http://prettier.io). The default settings for this extension should format your code in the correct way.

However, please ensure that you are using four spaces for a tab and that you *are* using tabs not spaces.

## Syntax errors

It is very important that any changes do not include syntax errors, as this will prevent building the project, which is a problem for contributors and active developers (not to mention users building from source).

Please double check your contribution for syntax errors, and if possible, build before committing.

Not PRs with syntax errors will be merged until they are resolved.

## Security flaws

Security is important to us. So, if your contribution has a security flaw that is immidiately threatening, you may be asked to fix it before it can be merged.

## Review process

Generally, only one maintainer will review a pull request at a time. All changes are reviewed before merging and the intent of the contribution will be cross-checked with the changes themselves. This allows us to come to a decision on wether your changes are ready to be merged.

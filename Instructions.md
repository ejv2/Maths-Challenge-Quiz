# Maths Challenge Quiz - _Gameplay Instructions_

Welcome to the Maths Challenge Quiz: a little game I programmed a while ago as a rewrite of a school project.

## Historic note

Maths Challenge Quiz was originally authored in winter 2019 as a school project. But, at the time, it resembled nothing like what we have today. The game was written in a rather limitting language called [Small Basic](https://smallbasic-publicwebsite.azurewebsites.net/), an education-oriented clone of Visual Basic, with all the frustrating syntax, yet not all the features.

For instance, you were limited to subroutine-based programming (technically not even that - you had to use GOTO statements to achieve subroutines) and there was no real type system.

So, the most challenging thing about the original version was, actually, the language itself. The most challenging thing about this version is getting rid of all the fluff and rubbish from the original.

I've kept as true as possible to what the original looked like, but the idea with this version is to add more features that simply were not possible with the original SB copy.

What follows is a modified version of the original *README* file, updated for the modern game. It contains relatively up-to-date instructions on how to play the game.

## General usage

## Installation

To install the game, copy the downloaded executable file to a suitable location and execute it. The game has no dependencies.

## First steps

When opening the program, you will see a command line interface. This is the UI of the program, and is how you will type your results.

To navigate your text, use the arrow keys. To type, press any key on your keyboard. To select text, drag or click with the mouse.

## Choosing a difficulty

In the game, there are 6 difficulty levels. Each of these has special properties and behaviors.

**Practice:** *Select with a negative number* Difficulty 0 will set every calculation to use only the number 1. For example, 1+1 and 1\*1. *This mode is for tests and practice only! It will not give you a legitimate score, and some behaviours may be altered. See "Practice mode"*.

**Easy:** *Select with 1* Easy mode will give you simple to work out calculations, some of which may be members of the multiplication tables learnt at school. This mode is recommended for beginners to new players, but not for experienced ones.

**Normal** *Select with 2* Normal mode will give you average difficulty calculations, which most people should handle. They will not always be learnable "off by heart", but mental strategies should make them manageable for most.

**Hard** *Select with 3* This mode will give you calculations which you may require extra working out to complete. This mode is recommended for most seasoned players.

**Very hard** *Select with 4* This mode will give very hard calculations which most people will struggle with. Some calculations may cause issues such as irrational numbers and recurring decimals.

**Impossible** *Select with any number above 4* This mode, effectively, makes the difficulty for the calculations limitless, and removes certain balancing features such as skip rounds. This mode is not recommended for anybody other than very competetive and/or expecienced players.

## Round types

There are many types of rounds, each with its own challenges and advantages.

For every round, you must answer at least half of the questions correctly (or quickly, see speed round) to pass. Failing to do so will end your game.

Correct answers will result in 1 or more points being added to your total, and 1 on your round total.

**Important note:** Your answer time will not be measured for any round except speed. Take your time and get the question correct.

### Arithmetic round

You will be required to solve addition and subtraction sums based on your difficulty. You will have questions in the format of:

*Enter the answer to 123 - 123:*

**OR**

*Enter the answer to 123 + 123:*

### Multiplication round

You will be required to solve a simple multiplication problem based on your difficulty. This problem will be in the form of:

*Enter the answer to 10 x 10:*

### Division round

The division round has the same mechanics as the multiplication round, but the problems will be division, rather than multiplication. The problem will be in the form of:

*Enter the answer to 10 x 10:*

The game will accept either:

1. The exact answer, in the case of rational, non-recurring answers
1. A two decimal place **truncated** version of the same number. **Example:** 0.66666666  -->  0.66

This system is in place to avoid crashes and/or unanswerable questions in the case of very long answers (try typing out 1/7 by hand).

### Speed round

You will be required to answer a question in under a set amount of time to gain points. Incorrect or slow answers may result in point deduction. You time will be measured in seconds. The time boundaries in the round are as follows:

* **Excellent** *Less than 1 second* 3 points will be awarded

* **Great** *Between 1-2 seconds* 2 points **awarded**

* **OK** *Between 2-3 seconds* 1 points **awarded**

* **Bad** *Between 3-4 seconds* 0 points **awarded**

* **Too slow** *More than 4 seconds* 1-2 points **subtracted**

The specific time at which you answered will only be recorded in whole seconds, meaning that sub-second times will end up being rounded down at all times. Essentially, 0.5 seconds will always be treated as < 5 - as will 0.95. This is by design.

### Skip round

In this round, you will not be required to answer any questions at all. Yes, that's right: I said *no questions at all*. This round is designed to provide some downtime in the pacing of the game, especially at higher difficulties. However, some difficulties (such as impossible mode) completely disable this round type, removing the downtime you would otherwise recieve.

When this round is activated, a counter will appear on the screen denoting the time remaining until the end of the round. There will be no inter-round delay for skip rounds.

### Dilemma round

Too straight-forward so far? Good, because the dilemma round is hear to ruin your day.

The dilemma round will simply ask you one question, and it has nothing to do with math. Instead, it will ask you what you would prefer between two sets of outcomes:

1. **Double your current points, but increase the difficulty by one level** Trade more points for more difficulty
1. **Loose 25% of your current points, but keep the current difficulty** No change to the overall game will be made, but it will cost you!

Failing to provide a correct response to the question asked will result in instant failure - of the entire game.

## Special difficulties

### Extreme difficulty

The extreme difficulty makes the limit on the maximum values of the calculations effectively limitless. This mode is not recommended for entertaining gameplay.

The behaviour in this mode is subtly modified, making the chance for a skip round less, and the chance for speed rounds increased. In speed rounds, the time penalties are not modified, meaning that you may need to multiply 4 digit numbers in under 3 seconds.

### Training difficulty

**Important note:** In training difficulty, the same amount of points are awarded as in normal difficulties. This means that the score is *ingenuine*. You should never use the outcome of practice mode as a gague of mathematical ability.

Training difficulty causes the random number generator to only return the number 1, meaning that you will only have to answer questions involving the number 1.

All the permutations of questions you will be asked are:

1. 1+1
2. 1-1
3. 1x1
4. 1?1

This mode is intended for you to get a feel for the mechanics of the game, and not to gague your ability. In order to be a true training experience, no other behaviour is modified in the game (such as frequency of skip rounds and time boundries for speed rounds), unlike other difficulties.

#### Forfeits in this mode

In this mode:

1. **You score in ingenuine** Your score will not give a genuine result, and will be treated as an ingenuine result by the game
2. **You will obtain no real points** Your overall points for the game will not be calculated or recorded
3. **Watermarking** The results screen will have a watermark applied, showing that training mode was enabled. Also, the exit command will be modified.

## Succeeding

To pass a round, you must gain at least half as many points as questions answered that round. You many need more dependant on difficulty. This means that you must answer at least half the questions correctly (or answer half the questions at a passable speed in a speed round) to pass. If you do not, the game will instantly end at the end of the round.

If you fail, you will be greeted with a failure message, and an angry computer.

On the failure message, you will be required to enter the text "I accept my result" to exit the program.

In practice mode, a watermark will be applied to the game over screen to mark a practice mode game. To exit the program, you will also need to type different text to the regular exit command.

## Exiting the game

To exit the game, press *"Ctrl-C"* on your keyboard, or exit the terminal window.

The game will automatically terminate on an error, or if you fail a round.

**Important note:** Terminating the game before accepting your score will make the score non-genuine, and it should be treated as such.

## Final words

Thanks for reading!

After ~~nine~~ two years in development (one of which I forgot about the game through), hopefully it was worth the wait. Thanks, and have fun.

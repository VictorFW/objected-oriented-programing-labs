CSE 332 Lab 3  Name: Wei Fan   ID:439311 email: weifan@wustl.edu

========================================================================
    CONSOLE APPLICATION : lab3 Project Overview
========================================================================

AppWizard has created this lab3 application for you.

This file contains a summary of what you will find in each of the files that
make up your lab3 application.


lab3.vcxproj
    This is the main project file for VC++ projects generated using an Application Wizard.
    It contains information about the version of Visual C++ that generated the file, and
    information about the platforms, configurations, and project features selected with the
    Application Wizard.

lab3.vcxproj.filters
    This is the filters file for VC++ projects generated using an Application Wizard. 
    It contains information about the association between the files in your project 
    and the filters. This association is used in the IDE to show grouping of files with
    similar extensions under a specific node (for e.g. ".cpp" files are associated with the
    "Source Files" filter).

lab3.cpp
    This is the main application source file.

/////////////////////////////////////////////////////////////////////////////
Other standard files:

StdAfx.h, StdAfx.cpp
    These files are used to build a precompiled header (PCH) file
    named lab3.pch and a precompiled types file named StdAfx.obj.

/////////////////////////////////////////////////////////////////////////////
Other notes:

AppWizard uses "TODO:" comments to indicate parts of the source code you
should add to or customize.

/////////////////////////////////////////////////////////////////////////////

The basic class is GameBase, TicTacToeGame and GomokuGame are public inheritance from GameBase.
The constructor of TicTacToeGame are inherited from the base class. The ComokuGame overwrite the constructor.







For the part of extra credit, I overload the constructor of the ComokuGame, like:

GomokuGame();
GomokuGame(int h);
GomokuGame(int h, int c);

in this case, users can choose input the board size, or input both board size and connecting number.
 thus, we only change the constructor, other parts of code do not need any change.







I didn't meet much problems during the whole lab.
I wrote each function step by step and test it before moving to next. Thus I nearly met no error when compile the final version of lab3 project.









The compiling messages as follows:

1>------ Build started: Project: lab3, Configuration: Debug Win32 ------
1>  lab3.vcxproj -> H:\My Documents\Visual Studio 2013\Projects\lab3\Debug\lab3.exe
========== Build: 1 succeeded, 0 failed, 0 up-to-date, 0 skipped ==========

The command line showing in terminal as follows:








H:\My Documents\Visual Studio 2013\Projects\lab3\Debug>lab3.exe
Please input the game's name after lab3.exe

H:\My Documents\Visual Studio 2013\Projects\lab3\Debug>lab3.exe TicTacToe

3
2
1
 123
Player X's turn:
Please input valid coordinate of a square on the board as a comma-separated pair
 of unsigned decimal integers. Or input "quit" to quit the game.
test
invalid input!
Please input valid coordinate of a square on the board as a comma-separated pair
 of unsigned decimal integers. Or input "quit" to quit the game.
1,4
out of range!
Please input valid coordinate of a square on the board as a comma-separated pair
 of unsigned decimal integers. Or input "quit" to quit the game.
1,1

3
2
1X
 123

Player X: 1,1
Player O's turn:
Please input valid coordinate of a square on the board as a comma-separated pair
 of unsigned decimal integers. Or input "quit" to quit the game.
1,2

3
2O
1X
 123

Player O: 1,2
Player X's turn:
Please input valid coordinate of a square on the board as a comma-separated pair
 of unsigned decimal integers. Or input "quit" to quit the game.
2,1

3
2O
1XX
 123

Player X: 1,1; 2,1
Player O's turn:
Please input valid coordinate of a square on the board as a comma-separated pair
 of unsigned decimal integers. Or input "quit" to quit the game.
2,2

3
2OO
1XX
 123

Player O: 1,2; 2,2
Player X's turn:
Please input valid coordinate of a square on the board as a comma-separated pair
 of unsigned decimal integers. Or input "quit" to quit the game.
3,1

3
2OO
1XXX
 123

Player X: 1,1; 2,1; 3,1
Player X wins!
5 turns were played

H:\My Documents\Visual Studio 2013\Projects\lab3\Debug>

H:\My Documents\Visual Studio 2013\Projects\lab3\Debug>lab3.exe Gomoku

 19

 18

 17

 16

 15

 14

 13

 12

 11

 10

  9

  8

  7

  6

  5

  4

  3

  2

  1

  X  1  2  3  4  5  6  7  8  9 10 11 12 13 14 15 16 17 18 19
Player B's turn:
Please input valid coordinate of a square on the board as a comma-separated pair
 of unsigned decimal integers. Or input "quit" to quit the game.
quit
A player force to quit the game

H:\My Documents\Visual Studio 2013\Projects\lab3\Debug>



H:\My Documents\Visual Studio 2013\Projects\lab3\Debug>lab3.exe Gomoku

 19

 18

 17

 16

 15

 14

 13

 12

 11

 10

  9

  8

  7

  6

  5

  4

  3

  2

  1

  X  1  2  3  4  5  6  7  8  9 10 11 12 13 14 15 16 17 18 19
Player B's turn:
Please input valid coordinate of a square on the board as a comma-separated pair
 of unsigned decimal integers. Or input "quit" to quit the game.

......
......
......

Player B's turn:
Please input valid coordinate of a square on the board as a comma-separated pair
 of unsigned decimal integers. Or input "quit" to quit the game.
5,5

 19

 18

 17

 16

 15

 14

 13

 12

 11

 10

  9

  8

  7

  6

  5              B  W

  4           B

  3        B

  2     B  W

  1  B  W  W

  X  1  2  3  4  5  6  7  8  9 10 11 12 13 14 15 16 17 18 19

Player B: 1,1; 2,2; 3,3; 4,4; 5,5
The Black Stone wins!
9 turns were played






--------------------------------------EXTRA CREDIT:-----------------------------------------------


----------------------input:lab3.exe Gomoku 10 -------------------------



H:\My Documents\Visual Studio 2013\Projects\lab3\Debug>lab3.exe Gomoku 10

 10

  9

  8

  7

  6

  5

  4

  3

  2

  1

  X  1  2  3  4  5  6  7  8  9 10
Player B's turn:
Please input valid coordinate of a square on the board as a comma-separated pair
 of unsigned decimal integers. Or input "quit" to quit the game.
quit
A player force to quit the game

H:\My Documents\Visual Studio 2013\Projects\lab3\Debug>








------------------------input:lab3.exe Gomoku 10 4----------------------------------


H:\My Documents\Visual Studio 2013\Projects\lab3\Debug>lab3.exe Gomoku 10 4

 10

  9

  8

  7

  6

  5

  4

  3

  2

  1

  X  1  2  3  4  5  6  7  8  9 10
Player B's turn:
Please input valid coordinate of a square on the board as a comma-separated pair
 of unsigned decimal integers. Or input "quit" to quit the game.
3,3

 10

  9

  8

  7

  6

  5

  4

  3        B

  2

  1

  X  1  2  3  4  5  6  7  8  9 10

Player B: 3,3
Player W's turn:
Please input valid coordinate of a square on the board as a comma-separated pair
 of unsigned decimal integers. Or input "quit" to quit the game.

......
......
......

Player W's turn:
Please input valid coordinate of a square on the board as a comma-separated pair
 of unsigned decimal integers. Or input "quit" to quit the game.
10,3

 10

  9

  8

  7              W

  6

  5

  4

  3        B  B  B              W

  2                             W

  1

  X  1  2  3  4  5  6  7  8  9 10

Player W: 5,7; 10,2; 10,3
Player B's turn:
Please input valid coordinate of a square on the board as a comma-separated pair
 of unsigned decimal integers. Or input "quit" to quit the game.
6,3

 10

  9

  8

  7              W

  6

  5

  4

  3        B  B  B  B           W

  2                             W

  1

  X  1  2  3  4  5  6  7  8  9 10

Player B: 3,3; 4,3; 5,3; 6,3
The Black Stone wins!
7 turns were played









-----------input: lab3.exe Gomoku 3 --------------------------------





H:\My Documents\Visual Studio 2013\Projects\lab3\Debug>lab3.exe Gomoku 3

  3

  2

  1

  X  1  2  3
Player B's turn:
Please input valid coordinate of a square on the board as a comma-separated pair
 of unsigned decimal integers. Or input "quit" to quit the game.
quit
A player force to quit the game





-----------input: lab3.exe Gomoku 3 --------------------------------








H:\My Documents\Visual Studio 2013\Projects\lab3\Debug>lab3.exe Gomoku 3

  3

  2

  1

  X  1  2  3
Player B's turn:
Please input valid coordinate of a square on the board as a comma-separated pair
 of unsigned decimal integers. Or input "quit" to quit the game.
1,1

  3

  2

  1  B

  X  1  2  3

Player B: 1,1
Player W's turn:
Please input valid coordinate of a square on the board as a comma-separated pair
 of unsigned decimal integers. Or input "quit" to quit the game.
2,1

  3

  2

  1  B  W

  X  1  2  3

Player W: 2,1
Player B's turn:
Please input valid coordinate of a square on the board as a comma-separated pair
 of unsigned decimal integers. Or input "quit" to quit the game.
1,2

  3

  2  B

  1  B  W

  X  1  2  3

Player B: 1,1; 1,2
Player W's turn:
Please input valid coordinate of a square on the board as a comma-separated pair
 of unsigned decimal integers. Or input "quit" to quit the game.
2,2

  3

  2  B  W

  1  B  W

  X  1  2  3

Player W: 2,1; 2,2
Player B's turn:
Please input valid coordinate of a square on the board as a comma-separated pair
 of unsigned decimal integers. Or input "quit" to quit the game.
1,3

  3  B

  2  B  W

  1  B  W

  X  1  2  3

Player B: 1,1; 1,2; 1,3
The Black Stone wins!
5 turns were played

H:\My Documents\Visual Studio 2013\Projects\lab3\Debug>






----------------------input: lab3.exe Gomoku 3  3-------------------------------------







H:\My Documents\Visual Studio 2013\Projects\lab3\Debug>lab3.exe Gomoku 3  3

  3

  2

  1

  X  1  2  3
Player B's turn:
Please input valid coordinate of a square on the board as a comma-separated pair
 of unsigned decimal integers. Or input "quit" to quit the game.
3,1

  3

  2

  1        B

  X  1  2  3

Player B: 3,1
Player W's turn:
Please input valid coordinate of a square on the board as a comma-separated pair
 of unsigned decimal integers. Or input "quit" to quit the game.
1,3

  3  W

  2

  1        B

  X  1  2  3

Player W: 1,3
Player B's turn:
Please input valid coordinate of a square on the board as a comma-separated pair
 of unsigned decimal integers. Or input "quit" to quit the game.
2,2

  3  W

  2     B

  1        B

  X  1  2  3

Player B: 3,1; 2,2
Player W's turn:
Please input valid coordinate of a square on the board as a comma-separated pair
 of unsigned decimal integers. Or input "quit" to quit the game.
2,1

  3  W

  2     B

  1     W  B

  X  1  2  3

Player W: 1,3; 2,1
Player B's turn:
Please input valid coordinate of a square on the board as a comma-separated pair
 of unsigned decimal integers. Or input "quit" to quit the game.
1,1

  3  W

  2     B

  1  B  W  B

  X  1  2  3

Player B: 3,1; 2,2; 1,1
Player W's turn:
Please input valid coordinate of a square on the board as a comma-separated pair
 of unsigned decimal integers. Or input "quit" to quit the game.
3,2

  3  W

  2     B  W

  1  B  W  B

  X  1  2  3

Player W: 1,3; 2,1; 3,2
Player B's turn:
Please input valid coordinate of a square on the board as a comma-separated pair
 of unsigned decimal integers. Or input "quit" to quit the game.
3,3

  3  W     B

  2     B  W

  1  B  W  B

  X  1  2  3

Player B: 3,1; 2,2; 1,1; 3,3
The Black Stone wins!
7 turns were played

H:\My Documents\Visual Studio 2013\Projects\lab3\Debug>

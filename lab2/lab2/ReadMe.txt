CSE 332 Lab 2    Name: Wei Fan Student ID: 439311
========================================================================
    CONSOLE APPLICATION : lab2 Project Overview
========================================================================

AppWizard has created this lab2 application for you.

This file contains a summary of what you will find in each of the files that
make up your lab2 application.


lab2.vcxproj
    This is the main project file for VC++ projects generated using an Application Wizard.
    It contains information about the version of Visual C++ that generated the file, and
    information about the platforms, configurations, and project features selected with the
    Application Wizard.

lab2.vcxproj.filters
    This is the filters file for VC++ projects generated using an Application Wizard. 
    It contains information about the association between the files in your project 
    and the filters. This association is used in the IDE to show grouping of files with
    similar extensions under a specific node (for e.g. ".cpp" files are associated with the
    "Source Files" filter).

lab2.cpp
    This is the main application source file. Besides the main function, I also define a usage_message function to print out the message when the number of input arguments is wrong.

lab2.h
	This is the head file for lab2. In this file I define three enum type, for input arguments, function results and pieces type. Also, the class of TicTacToeGame is define in this file.

TicTacToeGame.cpp
	This file contains several functions' definations that declare in lab2.h.

/////////////////////////////////////////////////////////////////////////////
Other standard files:

StdAfx.h, StdAfx.cpp
    These files are used to build a precompiled header (PCH) file
    named lab2.pch and a precompiled types file named StdAfx.obj.

/////////////////////////////////////////////////////////////////////////////
Other notes:

AppWizard uses "TODO:" comments to indicate parts of the source code you
should add to or customize.

/////////////////////////////////////////////////////////////////////////////



I didn't meet much problems during the whole lab.
I wrote each function step by step and test it before moving to next. Thus I nearly met no error when compile the lab2 project.



The compiling messages as follows:

1>------ Build started: Project: lab2, Configuration: Debug Win32 ------
1>  TicTacToeGame.cpp
1>  Generating Code...
1>  Compiling...
1>  lab2.cpp
1>  Generating Code...
1>  lab2.vcxproj -> H:\My Documents\Visual Studio 2013\Projects\lab2\Debug\lab2.exe
========== Build: 1 succeeded, 0 failed, 0 up-to-date, 0 skipped ==========


The command line showing in terminal as follows:


Following cases: the command to run this program is wrong:

H:\My Documents\Visual Studio 2013\Projects\lab2\Debug>lab2.exe
Wrong Number of Argument for lab2.exe
Please input and only input 1 parameter(s) other than program's name, which shou
ld be the game's name.

H:\My Documents\Visual Studio 2013\Projects\lab2\Debug>lab2.exe TicTacToe test
Wrong Number of Argument for lab2.exe
Please input and only input 1 parameter(s) other than program's name, which shou
ld be the game's name.

H:\My Documents\Visual Studio 2013\Projects\lab2\Debug>lab2.exe otherGame
You entered a wrong game name!

Following cases: invalid input coordinate


H:\My Documents\Visual Studio 2013\Projects\lab2\Debug>lab2.exe TicTacToe

4
3
2
1
0
 01234
Player X's turn:
Please input valid coordinate of a square on the board as a comma-separated pair
 of unsigned decimal integers. Or input "quit" to quit the game.
not coordinate
invalid input!
Please input valid coordinate of a square on the board as a comma-separated pair
 of unsigned decimal integers. Or input "quit" to quit the game.
4,1
input value should between 1 to 3
Please input valid coordinate of a square on the board as a comma-separated pair
 of unsigned decimal integers. Or input "quit" to quit the game.
2 2
please separate with comma
Player X's turn:
Please input valid coordinate of a square on the board as a comma-separated pair
 of unsigned decimal integers. Or input "quit" to quit the game.

Following case: a draw game:

H:\My Documents\Visual Studio 2013\Projects\lab2\Debug>lab2.exe TicTacToe

4
3
2
1
0
 01234
Player X's turn:
Please input valid coordinate of a square on the board as a comma-separated pair
 of unsigned decimal integers. Or input "quit" to quit the game.
2,2

4
3
2  X
1
0
 01234

Player X: 2,2
Player O's turn:
Please input valid coordinate of a square on the board as a comma-separated pair
 of unsigned decimal integers. Or input "quit" to quit the game.
1,1

4
3
2  X
1 O
0
 01234

Player O: 1,1
Player X's turn:
Please input valid coordinate of a square on the board as a comma-separated pair
 of unsigned decimal integers. Or input "quit" to quit the game.
1,3

4
3
2  X
1 O X
0
 01234

Player X: 2,2; 1,3
Player O's turn:
Please input valid coordinate of a square on the board as a comma-separated pair
 of unsigned decimal integers. Or input "quit" to quit the game.
3,1

4
3 O
2  X
1 O X
0
 01234

Player O: 1,1; 3,1
Player X's turn:
Please input valid coordinate of a square on the board as a comma-separated pair
 of unsigned decimal integers. Or input "quit" to quit the game.
3,3

4
3 O X
2  X
1 O X
0
 01234

Player X: 2,2; 1,3; 3,3
Player O's turn:
Please input valid coordinate of a square on the board as a comma-separated pair
 of unsigned decimal integers. Or input "quit" to quit the game.
2,3

4
3 O X
2  XO
1 O X
0
 01234

Player O: 1,1; 3,1; 2,3
Player X's turn:
Please input valid coordinate of a square on the board as a comma-separated pair
 of unsigned decimal integers. Or input "quit" to quit the game.
2,1

4
3 O X
2 XXO
1 O X
0
 01234

Player X: 2,2; 1,3; 3,3; 2,1
Player O's turn:
Please input valid coordinate of a square on the board as a comma-separated pair
 of unsigned decimal integers. Or input "quit" to quit the game.
1,2

4
3 O X
2 XXO
1 OOX
0
 01234

Player O: 1,1; 3,1; 2,3; 1,2
Player X's turn:
Please input valid coordinate of a square on the board as a comma-separated pair
 of unsigned decimal integers. Or input "quit" to quit the game.
3,2

4
3 OXX
2 XXO
1 OOX
0
 01234

Player X: 2,2; 1,3; 3,3; 2,1; 3,2
Draw! No valid move available!
9turns were played

H:\My Documents\Visual Studio 2013\Projects\lab2\Debug>



Following case: Player X wins:



H:\My Documents\Visual Studio 2013\Projects\lab2\Debug>lab2.exe TicTacToe

4
3
2
1
0
 01234
Player X's turn:
Please input valid coordinate of a square on the board as a comma-separated pair
 of unsigned decimal integers. Or input "quit" to quit the game.
1,1

4
3
2
1 X
0
 01234

Player X: 1,1
Player O's turn:
Please input valid coordinate of a square on the board as a comma-separated pair
 of unsigned decimal integers. Or input "quit" to quit the game.
1,3

4
3
2
1 X O
0
 01234

Player O: 1,3
Player X's turn:
Please input valid coordinate of a square on the board as a comma-separated pair
 of unsigned decimal integers. Or input "quit" to quit the game.
2,1

4
3
2 X
1 X O
0
 01234

Player X: 1,1; 2,1
Player O's turn:
Please input valid coordinate of a square on the board as a comma-separated pair
 of unsigned decimal integers. Or input "quit" to quit the game.
2,3

4
3
2 X O
1 X O
0
 01234

Player O: 1,3; 2,3
Player X's turn:
Please input valid coordinate of a square on the board as a comma-separated pair
 of unsigned decimal integers. Or input "quit" to quit the game.
3,1

4
3 X
2 X O
1 X O
0
 01234

Player X: 1,1; 2,1; 3,1
Player X wins!
5 turn(s) was(were) played

H:\My Documents\Visual Studio 2013\Projects\lab2\Debug>



Following case: Player X quits:



H:\My Documents\Visual Studio 2013\Projects\lab2\Debug>lab2.exe TicTacToe

4
3
2
1
0
 01234
Player X's turn:
Please input valid coordinate of a square on the board as a comma-separated pair
 of unsigned decimal integers. Or input "quit" to quit the game.
2,2

4
3
2  X
1
0
 01234

Player X: 2,2
Player O's turn:
Please input valid coordinate of a square on the board as a comma-separated pair
 of unsigned decimal integers. Or input "quit" to quit the game.
3,2

4
3  O
2  X
1
0
 01234

Player O: 3,2
Player X's turn:
Please input valid coordinate of a square on the board as a comma-separated pair
 of unsigned decimal integers. Or input "quit" to quit the game.
quit
Player X quit the game
2 turn(s) was(were) played

H:\My Documents\Visual Studio 2013\Projects\lab2\Debug>



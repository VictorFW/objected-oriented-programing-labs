CSE 332 Lab 1    Name: Wei Fan Student ID: 439311
========================================================================
    CONSOLE APPLICATION : lab1 Project Overview
========================================================================

AppWizard has created this lab1 application for you.

This file contains a summary of what you will find in each of the files that
make up your lab1 application.


lab1.vcxproj
    This is the main project file for VC++ projects generated using an Application Wizard.
    It contains information about the version of Visual C++ that generated the file, and
    information about the platforms, configurations, and project features selected with the
    Application Wizard.

lab1.vcxproj.filters
    This is the filters file for VC++ projects generated using an Application Wizard. 
    It contains information about the association between the files in your project 
    and the filters. This association is used in the IDE to show grouping of files with
    similar extensions under a specific node (for e.g. ".cpp" files are associated with the
    "Source Files" filter).

lab1.cpp
    This is the main application source file.

lab 1.h
	This is the header file I write for this program. It contains the delaration of
	three functions, and an enmu declares.

board.cpp
	This is the source file, which defines several functions.
	
board.h
	 This is the head file of game board, which declare several functions and define two enumerates for game board.

pieces.cpp
	This is the source file, which defines several functions for game pieces. 
pieces.h
	This This is the head file of game board, which declare several functions.It also defines two enumerates.


/////////////////////////////////////////////////////////////////////////////
Other standard files:

StdAfx.h, StdAfx.cpp
    These files are used to build a precompiled header (PCH) file
    named lab1.pch and a precompiled types file named StdAfx.obj.

/////////////////////////////////////////////////////////////////////////////
Other notes:

AppWizard uses "TODO:" comments to indicate parts of the source code you
should add to or customize.

/////////////////////////////////////////////////////////////////////////////
The compiling messages as follows:

1>------ Build started: Project: lab1, Configuration: Debug Win32 ------
1>  lab1.cpp
1>  lab1.vcxproj -> H:\My Documents\Visual Studio 2013\Projects\lab1\Debug\lab1.exe
========== Build: 1 succeeded, 0 failed, 0 up-to-date, 0 skipped ==========

When we use the file of tic-tac-toe.txt as follows:

3 3
red Xs X 0 0
red Xs X 0 2
red Xs X 1 1
red Xs X 1 2
red Xs X 2 2
blue Os O 0 1 
blue Os O 1 0 
blue Os O 2 0 
blue Os O 2 2 

The output from command line as follows:

H:\My Documents\Visual Studio 2013\Projects\lab1\Debug>lab1.exe tic-tac-toe.txt
XXX
 X
X



That is because the blue is a invalid color for this lab.
If we change blue to black as follows:

3 3
red Xs X 0 0
red Xs X 0 2
red Xs X 1 1
red Xs X 1 2
red Xs X 2 2
black Os O 0 1 
BLACK Os O 1 0 
blAck Os O 2 0 
BLaCK Os O 2 1

The output from command line as follows:

H:\My Documents\Visual Studio 2013\Projects\lab1\Debug>lab1.exe test.txt
XXX
OXO
XOO

We can see the input is not case sensitive.





Then we use the file of gomoku.txt:
8 8
black stone X 0 0
black stone X 0 2
black stone X 1 1
black stone X 2 0
black stone X 2 2
black stone X 3 1
black stone X 4 0
black stone X 4 2
black stone X 5 1
black stone X 6 0
black stone X 6 2
black stone X 7 1
white stone O 0 6
white stone O 1 5
white stone O 1 7
white stone O 2 6
white stone O 3 5
white stone O 3 7
white stone O 4 6
white stone O 5 5
white stone O 5 7
white stone O 6 6
white stone O 7 5
white stone O 7 7

The output from command line as follows:

H:\My Documents\Visual Studio 2013\Projects\lab1\Debug>lab1.exe gomoku.txt
 O O O O
O O O O
 O O O O


X X X X
 X X X X
X X X X

If the number of input arguments is not right, the output from command line as follows:

H:\My Documents\Visual Studio 2013\Projects\lab1\Debug>lab1.exe gomoku.txt test
Wrong Number of Argument for lab1.exe
Please only input 1 parameter(s) other than program's name!

If we put some invalid characters in the input file as follows:


invalid test

3 3
red Xs X 0 0
red Xs X 0 2
red Xs X 1 1

red Xs X 1 2
red Xs X 2 2


black Os O 0 1 
BLACK Os O 1 0 
invalid test
invalid test
blAck Os O 2 0 
BLaCK Os O 2 1


The output from command line as follows:

H:\My Documents\Visual Studio 2013\Projects\lab1\Debug>lab1.exe test.txt
XXX
OXO
XOO

We can see this program can tolerate some invalid input.
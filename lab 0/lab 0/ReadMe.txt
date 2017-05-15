cse 332 lab 0  Name: Wei Fan
========================================================================
    CONSOLE APPLICATION : lab 0 Project Overview
========================================================================

AppWizard has created this lab 0 application for you.

This file contains a summary of what you will find in each of the files that
make up your lab 0 application.


lab 0.vcxproj
    This is the main project file for VC++ projects generated using an Application Wizard.
    It contains information about the version of Visual C++ that generated the file, and
    information about the platforms, configurations, and project features selected with the
    Application Wizard.

lab 0.vcxproj.filters
    This is the filters file for VC++ projects generated using an Application Wizard. 
    It contains information about the association between the files in your project 
    and the filters. This association is used in the IDE to show grouping of files with
    similar extensions under a specific node (for e.g. ".cpp" files are associated with the
    "Source Files" filter).

lab 0.cpp
    This is the main application source file.

lab 0.h
	This is the header file I write for this program. It contains the delaration of
	three functions, and an enmu declares, which is enmu result. This enmu enumerates four 
	possible results of functions. They will be used as the return value of functions.

usage_message.cpp
	This is the source file, which defines the function of usage_message. This function 
	be called when the number of input arguments is error.

Parsing.cpp
	This is the source file, which defines the function of Parsing. This function will find
	those strings that contains only numeric digit characters, convert them to integers, 
	and push them into a vector of integers.

digit_print.cpp
	This is the source file, which defines the function of digit_print. This function will 
	print out strings that contains not only numeric digit characters, and then print out
	integers in vector.


/////////////////////////////////////////////////////////////////////////////
Other standard files:

StdAfx.h, StdAfx.cpp
    These files are used to build a precompiled header (PCH) file
    named lab 0.pch and a precompiled types file named StdAfx.obj.

/////////////////////////////////////////////////////////////////////////////
Other notes:

AppWizard uses "TODO:" comments to indicate parts of the source code you
should add to or customize.

/////////////////////////////////////////////////////////////////////////////
The compiling messages as follows:
1>------ Build started: Project: lab 0, Configuration: Debug Win32 ------
1>  usage_message.cpp
1>  lab 0.vcxproj -> \\warehouse2.seasad.wustl.edu\home\weifan\my documents\visual studio 2013\Projects\lab 0\Debug\lab 0.exe
========== Build: 1 succeeded, 0 failed, 0 up-to-date, 0 skipped ==========



The output from command line as follows:
H:\My Documents\Visual Studio 2013\Projects\lab 0\Debug>"lab 0.exe"
Please input exact one argument in addition to lab 0.exe

H:\My Documents\Visual Studio 2013\Projects\lab 0\Debug>"lab 0.exe" test.txt
Parsing is completed.
these
all
are
strings
7string
str4ing
string2
more
strings
0
1
2
3
5
7
11
13
17
19

H:\My Documents\Visual Studio 2013\Projects\lab 0\Debug>


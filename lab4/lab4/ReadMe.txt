CSE 332 Lab4        Wei Fan     weifan@wustl.edu

========================================================================
    CONSOLE APPLICATION : lab4 Project Overview
========================================================================

AppWizard has created this lab4 application for you.

This file contains a summary of what you will find in each of the files that
make up your lab4 application.


lab4.vcxproj
    This is the main project file for VC++ projects generated using an Application Wizard.
    It contains information about the version of Visual C++ that generated the file, and
    information about the platforms, configurations, and project features selected with the
    Application Wizard.

lab4.vcxproj.filters
    This is the filters file for VC++ projects generated using an Application Wizard. 
    It contains information about the association between the files in your project 
    and the filters. This association is used in the IDE to show grouping of files with
    similar extensions under a specific node (for e.g. ".cpp" files are associated with the
    "Source Files" filter).

lab4.cpp
    This is the main application source file.

/////////////////////////////////////////////////////////////////////////////
Other standard files:

StdAfx.h, StdAfx.cpp
    These files are used to build a precompiled header (PCH) file
    named lab4.pch and a precompiled types file named StdAfx.obj.

/////////////////////////////////////////////////////////////////////////////
Other notes:

AppWizard uses "TODO:" comments to indicate parts of the source code you
should add to or customize.

/////////////////////////////////////////////////////////////////////////////



For problem 18:
Actually we define none of those five functions.
The key point is: we use the smart pointer    shared_ptr<GameBase> game   
thus, we do not need explicitly define the destructor. And accroding to the C++ rule of three/five/zero, we do not need to explicitly define the copy constructor,move constructor, copy-assignment operator,move-assignment operator either. So if we explicitly define one of those five functions, we may need to explicitly define other four. But here we use the smart pointer, so we do not need to explicitly define them.







Most part of GameBase, TicTacToeGame, GomokuGame are same as previous lab.
We add a protected variable "static shared_ptr<GameBase> game_p" in GameBase class. This variable can store the pointer of current game object.


In GameBase, we modified the prompt function. After user input "quit", it will ask if the user want to save the current game. If the answer is "N"(stands for no, do not want to save), it will open a file which has the same name with game, and fout a line that the same as game's name. Then, it will fout a "0", indicate no game saved, as follow:

tictactoe
0


Otherwise, the user chooses save the game, it will write the current game status in to the file. An example of the file as follows:

tictactoe
3
 3 3 1 1
-2
 2 2
3,3; 1,1
2,2


the first line is the game's name;
the second line is current turns;
the 3rd line stores X's move, by each move's coordinates;
the 4th line stores now is who's turn, -1 means X's turn, and - 2 means O's turn
the 5th line stores O's move, similar as 3rd line;
the 6th line stores X's move to print out on screen;
the 7th line stores O's move to print out on screen

the command line to generate this file as follow:



H:\My Documents\Visual Studio 2013\Projects\lab4\Debug>lab4.exe tictactoe

3
2
1
 123
Player X's turn:
Please input valid coordinate of a square on the board as a comma-separated pair
 of unsigned decimal integers. Or input "quit" to quit the game.
3,3

3  X
2
1
 123

Player X: 3,3
Player O's turn:
Please input valid coordinate of a square on the board as a comma-separated pair
 of unsigned decimal integers. Or input "quit" to quit the game.
2,2

3  X
2 O
1
 123

Player O: 2,2
Player X's turn:
Please input valid coordinate of a square on the board as a comma-separated pair
 of unsigned decimal integers. Or input "quit" to quit the game.
1,1

3  X
2 O
1X
 123

Player X: 3,3; 1,1
Player O's turn:
Please input valid coordinate of a square on the board as a comma-separated pair
 of unsigned decimal integers. Or input "quit" to quit the game.
quit

Do you want to save the game?
input Y for YES or N for NO
Y
A player force to quit the game

H:\My Documents\Visual Studio 2013\Projects\lab4\Debug>




Since the GomokuGame and TicTacToeGame share the same prompt function, so the GomokuGame has the same way to store game status.















As for SudokuGame, it's also a public inheritance from the GameBase class.
when initialize the game object, the constructBoard_sudoku(int width, int height) function, which is in constructor, will open the sudoku0 file and mark those given numbers by original_board[i][j] = true; thus those numbers cannot be changed during the game process.If there is no previous game saved,the sudoku file shoule be 


sudoku
0

if the constructor read the value 0, it will close the current file, sudoku, and open the sudoku0, then read from that file to initilize the board.

While playing this game, each step, the player will enter the coordinate whis to put digit in, like x,y ,then play needs enter a number between 1 and 9. The player can always change a digit that input before. If the player enter "quit",the program will ask the player if wish to save. If the play choose Y, for wish to save, then the program will write the file as follows:


sudoku
30
4 0 8
7 0 7
8 0 9
3 1 4
4 1 1
5 1 9
8 1 5
1 2 6
6 2 2
7 2 8
0 3 7
4 3 2
8 3 6
0 4 4
3 4 8
5 4 3
8 4 1
0 5 8
4 5 6
8 5 3
1 6 9
2 6 8
7 6 6
0 7 6
3 7 1
4 7 9
5 7 5
0 8 5
1 8 3
4 8 7

the 1st line is the name of game
the 2nd line is how many square has number
from the 3re line, each line store a number. the first two numbers are the coordinate square, the 3rd number are the digit in this square.


the command line to generate this file as follow:


H:\My Documents\Visual Studio 2013\Projects\lab4\Debug>lab4.exe sudoku

8||5|3| || |7| || | | ||
-||-|-|-||-|-|-||-|-|-||
7||6| | ||1|9|5|| | | ||
-||-|-|-||-|-|-||-|-|-||
6|| |9|8|| | | || |6| ||
=||=|=|=||=|=|=||=|=|=||
5||8| | || |6| || | |3||
-||-|-|-||-|-|-||-|-|-||
4||4| | ||8| |3|| | |1||
-||-|-|-||-|-|-||-|-|-||
3||7| | || |2| || | |6||
=||=|=|=||=|=|=||=|=|=||
2|| |6| || | | ||2|8| ||
-||-|-|-||-|-|-||-|-|-||
1|| | | ||4|1|9|| | |5||
-||-|-|-||-|-|-||-|-|-||
0|| | | || |8| || |7|9||
=||=|=|=||=|=|=||=|=|=||
#||0|1|2||3|4|5||6|7|8||
Please input valid coordinate you want to put digit in as a comma-separated pair
 of unsigned decimal integers. Or input "quit" to quit the game.
quit

Do you want to save the game?
input Y for YES or N for NO
Y
A player force to quit the game

H:\My Documents\Visual Studio 2013\Projects\lab4\Debug>



if all squares are filled correctly, it will print a message:



H:\My Documents\Visual Studio 2013\Projects\lab4\Debug>lab4.exe sudoku

8||5|3|4||6|7|8||9|1|2||
-||-|-|-||-|-|-||-|-|-||
7||6|7|2||1|9|5||3|4|8||
-||-|-|-||-|-|-||-|-|-||
6||1|9|8||3|4|2||5|6|7||
=||=|=|=||=|=|=||=|=|=||
5||8|5|9||7|6|1||4|2|3||
-||-|-|-||-|-|-||-|-|-||
4||4|2|6||8|5|3||7|9|1||
-||-|-|-||-|-|-||-|-|-||
3||7|1|3||9|2|4||8|5|6||
=||=|=|=||=|=|=||=|=|=||
2||9|6|1||5|3|7||2|8| ||
-||-|-|-||-|-|-||-|-|-||
1||2|8|7||4|1|9||6|3|5||
-||-|-|-||-|-|-||-|-|-||
0||3|4|5||2|8|6||1|7|9||
=||=|=|=||=|=|=||=|=|=||
#||0|1|2||3|4|5||6|7|8||
Please input valid coordinate you want to put digit in as a comma-separated pair
 of unsigned decimal integers. Or input "quit" to quit the game.
8,2
Please input the digit you want put in the coordinate of (8,2)
4

8||5|3|4||6|7|8||9|1|2||
-||-|-|-||-|-|-||-|-|-||
7||6|7|2||1|9|5||3|4|8||
-||-|-|-||-|-|-||-|-|-||
6||1|9|8||3|4|2||5|6|7||
=||=|=|=||=|=|=||=|=|=||
5||8|5|9||7|6|1||4|2|3||
-||-|-|-||-|-|-||-|-|-||
4||4|2|6||8|5|3||7|9|1||
-||-|-|-||-|-|-||-|-|-||
3||7|1|3||9|2|4||8|5|6||
=||=|=|=||=|=|=||=|=|=||
2||9|6|1||5|3|7||2|8|4||
-||-|-|-||-|-|-||-|-|-||
1||2|8|7||4|1|9||6|3|5||
-||-|-|-||-|-|-||-|-|-||
0||3|4|5||2|8|6||1|7|9||
=||=|=|=||=|=|=||=|=|=||
#||0|1|2||3|4|5||6|7|8||

You have done! awesome!

H:\My Documents\Visual Studio 2013\Projects\lab4\Debug>




The way to judge if the game is done is interesting. In each column and row and 3*3 squares, calculate the sum of 2^n, n refers the nine digit. If the nine digit is exactly right, the sum should be 1022, which can get by 2^1+2^2+2^3+2^4+2^5+2^6+2^7+2^8+2^9

if the board is full but not done, it will print a message as follow:


H:\My Documents\Visual Studio 2013\Projects\lab4\Debug>lab4.exe sudoku

8||5|3|4||6|7|8||9|1|2||
-||-|-|-||-|-|-||-|-|-||
7||6|7|2||1|9|5||3|4|8||
-||-|-|-||-|-|-||-|-|-||
6||1|9|8||3|4|2||5|6|7||
=||=|=|=||=|=|=||=|=|=||
5||8|5|9||7|6|1||4|2|3||
-||-|-|-||-|-|-||-|-|-||
4||4|2|6||8|5|3||7|9|1||
-||-|-|-||-|-|-||-|-|-||
3||7|1|3||9|2|4||8|5|6||
=||=|=|=||=|=|=||=|=|=||
2||9|6|1||5|3|7||2|8| ||
-||-|-|-||-|-|-||-|-|-||
1||2|8|7||4|1|9||6|3|5||
-||-|-|-||-|-|-||-|-|-||
0||3|4|5||2|8|6||1|7|9||
=||=|=|=||=|=|=||=|=|=||
#||0|1|2||3|4|5||6|7|8||
Please input valid coordinate you want to put digit in as a comma-separated pair
 of unsigned decimal integers. Or input "quit" to quit the game.
8,2
Please input the digit you want put in the coordinate of (8,2)
3

8||5|3|4||6|7|8||9|1|2||
-||-|-|-||-|-|-||-|-|-||
7||6|7|2||1|9|5||3|4|8||
-||-|-|-||-|-|-||-|-|-||
6||1|9|8||3|4|2||5|6|7||
=||=|=|=||=|=|=||=|=|=||
5||8|5|9||7|6|1||4|2|3||
-||-|-|-||-|-|-||-|-|-||
4||4|2|6||8|5|3||7|9|1||
-||-|-|-||-|-|-||-|-|-||
3||7|1|3||9|2|4||8|5|6||
=||=|=|=||=|=|=||=|=|=||
2||9|6|1||5|3|7||2|8|3||
-||-|-|-||-|-|-||-|-|-||
1||2|8|7||4|1|9||6|3|5||
-||-|-|-||-|-|-||-|-|-||
0||3|4|5||2|8|6||1|7|9||
=||=|=|=||=|=|=||=|=|=||
#||0|1|2||3|4|5||6|7|8||

you might input somethings wrong, try to change some digits!
Please input valid coordinate you want to put digit in as a comma-separated pair
 of unsigned decimal integers. Or input "quit" to quit the game.













##########################################################################################################




********************************************** extra credit *****************************************************




#############################################################################################################














We add a class UltimateTicTacToeGame,it's also a public inheritance from the GameBase class.

In UltimateTicTacToeGame,use int prev_x;int prev_y to store previous move's coordinate.
And vector<vector<big_squre>> big_board; to store a 3*3 big board.


H:\My Documents\Visual Studio 2013\Projects\lab4\Debug>lab4.exe ultimatetictacto
e

2|2|| | | || | | || | | ||
-|-||-|-|-||-|-|-||-|-|-||
2|1|| | | || | | || | | ||
-|-||-|-|-||-|-|-||-|-|-||
2|0|| | | || | | || | | ||
=|=||=|=|=||=|=|=||=|=|=||
1|2|| | | || | | || | | ||
-|-||-|-|-||-|-|-||-|-|-||
1|1|| | | || | | || | | ||
-|-||-|-|-||-|-|-||-|-|-||
1|0|| | | || | | || | | ||
=|=||=|=|=||=|=|=||=|=|=||
0|2|| | | || | | || | | ||
-|-||-|-|-||-|-|-||-|-|-||
0|1|| | | || | | || | | ||
-|-||-|-|-||-|-|-||-|-|-||
0|0|| | | || | | || | | ||
=|=||=|=|=||=|=|=||=|=|=||
  #||0|1|2||0|1|2||0|1|2||
   ||-|-|-||-|-|-||-|-|-||
   ||0|0|0||1|1|1||2|2|2||
Player X's turn:
Please choose which board you want to put your piece. Input valid coordinate of
board as a comma-separated pair of unsigned decimal integers. Or input "quit" to
 quit the game.
quit

Do you want to save the game?
input Y for YES or N for NO
N
A player force to quit the game












We can see the outer border is the index of big_board, the inner border is the index of board.


each turn, player first choose which big board want to put piece in, if he/she can choose, then chose the inner index for which square to put pieces, as follow:














H:\My Documents\Visual Studio 2013\Projects\lab4\Debug>lab4.exe ultimatetictacto
e

2|2|| | | || | | || | | ||
-|-||-|-|-||-|-|-||-|-|-||
2|1|| | | || | | || | | ||
-|-||-|-|-||-|-|-||-|-|-||
2|0|| | | || | | || | | ||
=|=||=|=|=||=|=|=||=|=|=||
1|2|| | | || | | || | | ||
-|-||-|-|-||-|-|-||-|-|-||
1|1|| | | || | | || | | ||
-|-||-|-|-||-|-|-||-|-|-||
1|0|| | | || | | || | | ||
=|=||=|=|=||=|=|=||=|=|=||
0|2|| | | || | | || | | ||
-|-||-|-|-||-|-|-||-|-|-||
0|1|| | | || | | || | | ||
-|-||-|-|-||-|-|-||-|-|-||
0|0|| | | || | | || | | ||
=|=||=|=|=||=|=|=||=|=|=||
  #||0|1|2||0|1|2||0|1|2||
   ||-|-|-||-|-|-||-|-|-||
   ||0|0|0||1|1|1||2|2|2||
Player X's turn:
Please choose which board you want to put your piece. Input valid coordinate of
board as a comma-separated pair of unsigned decimal integers. Or input "quit" to
 quit the game.
1,1
Please input the coordinates of the piece you want to put in the board you chose
 as a comma-separated pair of unsigned decimal integers. Or input "quit" to quit
 the game.
0,0

2|2|| | | || | | || | | ||
-|-||-|-|-||-|-|-||-|-|-||
2|1|| | | || | | || | | ||
-|-||-|-|-||-|-|-||-|-|-||
2|0|| | | || | | || | | ||
=|=||=|=|=||=|=|=||=|=|=||
1|2|| | | || | | || | | ||
-|-||-|-|-||-|-|-||-|-|-||
1|1|| | | || | | || | | ||
-|-||-|-|-||-|-|-||-|-|-||
1|0|| | | ||X| | || | | ||
=|=||=|=|=||=|=|=||=|=|=||
0|2|| | | || | | || | | ||
-|-||-|-|-||-|-|-||-|-|-||
0|1|| | | || | | || | | ||
-|-||-|-|-||-|-|-||-|-|-||
0|0|| | | || | | || | | ||
=|=||=|=|=||=|=|=||=|=|=||
  #||0|1|2||0|1|2||0|1|2||
   ||-|-|-||-|-|-||-|-|-||
   ||0|0|0||1|1|1||2|2|2||

Player O's turn:
Now, you have to put your piece in the (0,0) board.
Please input the coordinates of the piece you want to put in the board as a comm
a-separated pair of unsigned decimal integers. Or input "quit" to quit the game.

0,1

2|2|| | | || | | || | | ||
-|-||-|-|-||-|-|-||-|-|-||
2|1|| | | || | | || | | ||
-|-||-|-|-||-|-|-||-|-|-||
2|0|| | | || | | || | | ||
=|=||=|=|=||=|=|=||=|=|=||
1|2|| | | || | | || | | ||
-|-||-|-|-||-|-|-||-|-|-||
1|1|| | | || | | || | | ||
-|-||-|-|-||-|-|-||-|-|-||
1|0|| | | ||X| | || | | ||
=|=||=|=|=||=|=|=||=|=|=||
0|2|| | | || | | || | | ||
-|-||-|-|-||-|-|-||-|-|-||
0|1||O| | || | | || | | ||
-|-||-|-|-||-|-|-||-|-|-||
0|0|| | | || | | || | | ||
=|=||=|=|=||=|=|=||=|=|=||
  #||0|1|2||0|1|2||0|1|2||
   ||-|-|-||-|-|-||-|-|-||
   ||0|0|0||1|1|1||2|2|2||

Player X's turn:
Now, you have to put your piece in the (0,1) board.
Please input the coordinates of the piece you want to put in the board as a comm
a-separated pair of unsigned decimal integers. Or input "quit" to quit the game.

2,1

2|2|| | | || | | || | | ||
-|-||-|-|-||-|-|-||-|-|-||
2|1|| | | || | | || | | ||
-|-||-|-|-||-|-|-||-|-|-||
2|0|| | | || | | || | | ||
=|=||=|=|=||=|=|=||=|=|=||
1|2|| | | || | | || | | ||
-|-||-|-|-||-|-|-||-|-|-||
1|1|| | |X|| | | || | | ||
-|-||-|-|-||-|-|-||-|-|-||
1|0|| | | ||X| | || | | ||
=|=||=|=|=||=|=|=||=|=|=||
0|2|| | | || | | || | | ||
-|-||-|-|-||-|-|-||-|-|-||
0|1||O| | || | | || | | ||
-|-||-|-|-||-|-|-||-|-|-||
0|0|| | | || | | || | | ||
=|=||=|=|=||=|=|=||=|=|=||
  #||0|1|2||0|1|2||0|1|2||
   ||-|-|-||-|-|-||-|-|-||
   ||0|0|0||1|1|1||2|2|2||

Player O's turn:
Now, you have to put your piece in the (2,1) board.
Please input the coordinates of the piece you want to put in the board as a comm
a-separated pair of unsigned decimal integers. Or input "quit" to quit the game.






if a big board ends, it will print message:






Player X's turn:
Now, you have to put your piece in the (0,1) board.
Please input the coordinates of the piece you want to put in the board as a comm
a-separated pair of unsigned decimal integers. Or input "quit" to quit the game.

2,1
X wins in board (0, 1)

2|2|| | | || | | || |X| ||
-|-||-|-|-||-|-|-||-|-|-||
2|1|| | | ||O| | || | | ||
-|-||-|-|-||-|-|-||-|-|-||
2|0|| | | || | | || | | ||
=|=||=|=|=||=|=|=||=|=|=||
1|2|| | |O|| | | || | | ||
-|-||-|-|-||-|-|-||-|-|-||
1|1||X|X|X||O| | || | | ||
-|-||-|-|-||-|-|-||-|-|-||
1|0|| | | || | | || | | ||
=|=||=|=|=||=|=|=||=|=|=||
0|2|| | | || | | || | | ||
-|-||-|-|-||-|-|-||-|-|-||
0|1|| | | || | | || | | ||
-|-||-|-|-||-|-|-||-|-|-||
0|0|| | | || | | || | | ||
=|=||=|=|=||=|=|=||=|=|=||
  #||0|1|2||0|1|2||0|1|2||
   ||-|-|-||-|-|-||-|-|-||
   ||0|0|0||1|1|1||2|2|2||

Player O's turn:
Now, you have to put your piece in the (2,1) board.
Please input the coordinates of the piece you want to put in the board as a comm
a-separated pair of unsigned decimal integers. Or input "quit" to quit the game.

....
....
....
....

if a play wins:


Player X's turn:
Now, you have to put your piece in the (1,1) board.
Please input the coordinates of the piece you want to put in the board as a comm
a-separated pair of unsigned decimal integers. Or input "quit" to quit the game.

0,2
X wins in board (1, 1)

2|2|| | | || | | || |X| ||
-|-||-|-|-||-|-|-||-|-|-||
2|1|| | | ||O|O| || | |X||
-|-||-|-|-||-|-|-||-|-|-||
2|0||X| | || | | || | | ||
=|=||=|=|=||=|=|=||=|=|=||
1|2|| | |O||X| |O|| |X| ||
-|-||-|-|-||-|-|-||-|-|-||
1|1||X|X|X||O|X|O|| |X|O||
-|-||-|-|-||-|-|-||-|-|-||
1|0|| | | || | |X|| |X|O||
=|=||=|=|=||=|=|=||=|=|=||
0|2|| | | || | | ||O| | ||
-|-||-|-|-||-|-|-||-|-|-||
0|1|| |O| || |O|O|| | | ||
-|-||-|-|-||-|-|-||-|-|-||
0|0|| | | || | | || |X| ||
=|=||=|=|=||=|=|=||=|=|=||
  #||0|1|2||0|1|2||0|1|2||
   ||-|-|-||-|-|-||-|-|-||
   ||0|0|0||1|1|1||2|2|2||

Player X wins!
25 turns were played

H:\My Documents\Visual Studio 2013\Projects\lab4\Debug>










Also, user can choose to quit by typing "quit" any time and choose whether save the game




the previous operations will generate the file as follow:

ultimatetictactoe
3
-2
2 1
 0 0 0 0 0 0 0 0 0
 2 0 0 0 0 0 0 0 0
 0 0 0 0 0 0 0 0 0
 0 0 0 1 0 0 0 0 0
 0 0 1 0 0 0 0 0 0
 0 0 0 0 0 0 0 0 0
 0 0 0 0 0 0 0 0 0
 0 0 0 0 0 0 0 0 0
 0 0 0 0 0 0 0 0 0
 0 0 0
 0 0 0
 0 0 0


the first line is game's name
the 2nd line is current number of turns;
the 3rd line indicate who's turn, -1 for X and -2 for O;
the 4th line stores the previous step's coordinate;
the following 9*9 matrix indicate the current board,0 for no piece,1 for X,2 for 0
the following 3*3 matrix indicate the current board,0 for not end, 1 for X wins, 2 for O wins,3 for tie

Attention: if a big board ends in tie, it will counts neither X or O.

















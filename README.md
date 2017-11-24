Reversi

Instructions

Reversi is a two-player game where players take turns placing a piece of their colour in a cell. Black plays first The goal of Reversi is to have the most cells holding pieces of your colour at the end of the game. If a new piece A would form a line segment with an existing piece B of the same colour, such that all of the cells in between are occupied and of the opposite colour, those in-between pieces are flipped to the same colour as A and B. There is one slight difference from standard Reversi: whereas a legal move in standard Reversi must cause at least one flip, my reversi is not required to enforce this rule. This means that on any turn players can play a piece on any cell, so long as that cell is within the grid and not currently occupied by another piece.



Getting Started

Install all .h, .cc, and Makefile. Enter $make to compile and then enter $./reversi to play the game on terminal.
The following are the commands to play the game:
1. $new n to create a new n * n grid with middle 4 squares following the Black-White-Black-White pattern, where n >= 4 and 
n % 2 = 0. If there was already an active grid, that grid is destroyed and replaced with the new one.
2. $play r c within a game where r and c are two integers, plays a piece at row r, column c of the colour corresponding to 
the player who's move it is. The row and the column both start with number 0. If the row and column entered correspond to a cell that already has a piece, or a position outside the grid, then the input is ignored and nothing is done. 
  
  
  
Examples

commands: new 10, play 3 4, play 3 3, play 0 0, play 6 6.
Due to the syntax displayed for this document, the produced output after running the above commands is very different from what is actually produces. Therefore, I will describe the produced output in words. 
Position (0,0) and (3,4) are letter 'B' and Position (3,3), (4,4), (4,5), (5,4), (5,5) and (6,6) are letter 'W' and all the other positions are letter '-'



Service

If you have any further questions please do not hesitate to contact me by my email, jamesi1998.js@gmail.com, available 24 hours 7 days a week.



© 2017 Enze Si.  All rights reserved.


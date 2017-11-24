Reversi

Reversi is a two-player game where players take turns placing a piece of their colour in a cell. Black plays first The goal of Reversi is to have the most cells holding pieces of your colour at the end of the game. If a new piece A would form a line segment with an existing piece B of the same colour, such that all of the cells in between are occupied and of the opposite colour, those in-between pieces are flipped to the same colour as A and B. There is one slight difference from standard Reversi: whereas a legal move in standard Reversi must cause at least one flip, my reversi is not required to enforce this rule. This means that on any turn players can play a piece on any cell, so long as that cell is within the grid and not currently occupied by another piece.



Prerequisites

Install all .h, .cc, and Makefile. Enter command $make and then enter $./reversi to play the game on terminal.




Examples

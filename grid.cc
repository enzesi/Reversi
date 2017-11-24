//
//  grid.cpp
//  a4q4
//
//  Created by Enze Si on 2017-11-18.
//  Copyright © 2017 Enze Si. All rights reserved.
//

#include "grid.h"
#include <iostream>
#include <string>
#include <vector>

using namespace std;


Grid::~Grid() {
    delete td;
}


bool Grid::isFull() const { // Is the game over, i.e., is the grid full?
    if (current_plays >= max_plays) {
        return true;
    }
    else {
        return false;
    }
}

Colour Grid::whoWon() const { // Who has more pieces when the board is full?
    int black = 0;
    int white = 0;
    for (int i = 0; i < theGrid.size(); i++) {
        for (int j = 0; j < theGrid.size(); j++) {
            if (theGrid[i][j].getInfo().colour == Colour::Black) {
                black++;
            }
            else {
                white++;
            }
        }
    }
    if (black > white) {
        return Colour::Black;
    }
    else if (black == white) {
        return Colour::None;
    }
    else {
        return Colour::White;
    }
}

void Grid::init(size_t n) { // Sets up an n x n grid.  Clears old grid, if necessary.
    (this->theGrid).clear();
    delete td;
    this->current_plays = 4;
    int size = n;
    max_plays = size * size;
    this->td = new TextDisplay(n);
    for (int i = 0; i < size; i++) { //initialize cell vector
        vector<Cell> v;
        for (int j = 0; j < size; j++) {
            v.emplace_back(Cell(i ,j));
        }
        theGrid.emplace_back(v);
    }
    for (int i = 0; i < size; i++) { //attach cell vector to the textdisplay observer
        for (int j = 0; j < size; j++) {
            theGrid[i][j].attach(td);
        }
    }
    
    //initialize middle four
    int mid = size / 2 - 1;
    theGrid[mid][mid].setPiece(Colour::Black);
    theGrid[mid][mid + 1].setPiece(Colour::White);
    theGrid[mid + 1][mid].setPiece(Colour::White);
    theGrid[mid + 1][mid + 1].setPiece(Colour::Black);
    
    for(int i = 0; i < size; i++){ //attach eight neighbours
        for(int j = 0; j < size; j++){
            //attach upper left cell
            if(i - 1 >= 0 && j + 1 <= size - 1){
                theGrid[i][j].attach(&theGrid[i-1][j+1]);
            }
            //attach upper cell
            if(j - 1 >= 0){
                theGrid[i][j].attach(&theGrid[i][j-1]);
            }
            //attach upper right cell
            if(i + 1 <= size - 1 && j - 1 >= 0){
                theGrid[i][j].attach(&theGrid[i+1][j-1]);
            }
            //attach left cell
            if(i - 1 >= 0){
                theGrid[i][j].attach(&theGrid[i-1][j]);
            }
            //attach right cell
            if(i + 1 < size){
                theGrid[i][j].attach(&theGrid[i+1][j]);
            }
            //attach lower left cell
            if(i - 1 >= 0 && j - 1 >= 0){
                theGrid[i][j].attach(&theGrid[i-1][j-1]);
            }
            //attach lower cell
            if(j + 1 < n){
                theGrid[i][j].attach(&theGrid[i][j+1]);
            }
            //attach lower right cell
            if(i + 1 <= size - 1 && j + 1 <= size - 1){
                theGrid[i][j].attach(&theGrid[i+1][j+1]);
            }
        }
    }
}
 
void Grid::setPiece(size_t r, size_t c, Colour colour) { // Plays piece at row r, col c.
    theGrid[r][c].setPiece(colour);
    this->current_plays++;
}

void Grid::toggle(size_t r, size_t c) {  // Flips piece at row r, col c.
    theGrid[r][c].toggle();
}

ostream &operator<<(ostream &out, const Grid &g) {
    out << *(g.td);
    return out;
}

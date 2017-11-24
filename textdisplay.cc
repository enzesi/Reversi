//
//  txtdisplay.cpp
//  a4q4
//
//  Created by Enze Si on 2017-11-19.
//  Copyright © 2017 Enze Si. All rights reserved.
//

#include "textdisplay.h"
#include <vector>
using namespace std;

TextDisplay::TextDisplay(int n):gridSize(n){ //ctor
    for (int i = 0; i < n; i++) {
        vector<char> v;
        for (int j = 0; j < n; j++) {
            v.emplace_back('-');
        }
        theDisplay.emplace_back(v);
    }
}


void TextDisplay::notify(Subject<Info, State> &whoNotified) { //change the char in terms of rows and cols
    Info f = whoNotified.getInfo();
    size_t r = f.row;
    size_t c = f.col;
    Colour cl = f.colour;
    if (cl == Colour::White) {
        theDisplay[r][c] = 'W';
    }
    if (cl == Colour::Black) {
        theDisplay[r][c] = 'B';
    }
}

ostream &operator<<(ostream &out, const TextDisplay &td) {
    for (int i = 0; i < td.gridSize; i++) {
        for (int j = 0; j < td.gridSize; j++) {
            out << td.theDisplay[i][j];
        }
        out << endl;
    }
    return out;
}

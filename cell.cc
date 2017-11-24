//
//  cell.cpp
//  a4q4
//
//  Created by Enze Si on 2017-11-18.
//  Copyright © 2017 Enze Si. All rights reserved.
//

#include "cell.h"
#include "subject.h"

Cell::Cell(size_t r, size_t c) : r{r}, c{c}, colour{Colour::None} {}

void Cell::setPiece(Colour colour) { // Place a piece of given colour here.
    if (this->colour != Colour::None) { //input the same piece
        bool error = true;
        throw error;
    }
    else {
        this->colour = colour;
        State s{StateType::NewPiece, colour, Direction::NW};
        this->setState(s);
        this->notifyObservers();
    }
}

void Cell::toggle() { // Toggles my colour.
    if (colour == Colour::White) {
        colour = Colour::Black;
    }
    else if (colour == Colour::Black) {
        colour = Colour::White;
    }
    this->notifyObservers();
}

void Cell::notify(Subject<Info, State> &whoFrom) {// My neighbours will call this
    size_t row = whoFrom.getInfo().row;
    size_t col = whoFrom.getInfo().col;
    Direction d;
    Direction backwards_d;
    if (this->colour == Colour::None) {
        return;
    }
    if ((this->r == row - 1) && (this->c == col - 1)) { //top left cell
        d = Direction::NW;
        backwards_d = Direction::SE;
    }
    else if ((this->r == row - 1) && (this->c == col)) { //top cell
        d = Direction::N;
        backwards_d = Direction::S;
    }
    else if ((this->r == row - 1) && (this->c == col + 1)) { //top right cell
        d = Direction::NE;
        backwards_d = Direction::SW;
    }
    else if ((this->r == row) && (this->c == col - 1)) { //left cell
        d = Direction::W;
        backwards_d = Direction::E;
    }
    else if ((this->r == row) && (this->c == col + 1)) { //right cell
        d = Direction::E;
        backwards_d = Direction::W;
    }
    else if ((this->r == row + 1) && (this->c == col - 1)) { //bottom left cell
        d = Direction::SW;
        backwards_d = Direction::NE;
    }
    else if ((this->r == row + 1) && (this->c == col)) { //bottom cell
        d = Direction::S;
        backwards_d = Direction::N;
    }
    else if ((this->r == row + 1) && (this->c == col + 1)) { //bottom right cell
        d = Direction::SE;
        backwards_d = Direction::NW;
    }
    if (whoFrom.getState().type == StateType::NewPiece) { //state is new piece
        if (this->colour == whoFrom.getState().colour) { // same colour
            return;
        }
        else { //different colour
            setState({StateType::Relay, whoFrom.getState().colour, d});
            notifyObservers();
        }
    }
    else if (whoFrom.getState().type == StateType::Relay) { //state is relay
        if (whoFrom.getState().direction != d) { //different direction
            return;
        }
        if (whoFrom.getState().colour != colour) { //different colour
            setState({StateType::Relay, whoFrom.getState().colour, d});
            notifyObservers();
        }
        else { //same colour
            setState({StateType::Reply, whoFrom.getState().colour, backwards_d});
            notifyObservers();
        }
    }
    else if (whoFrom.getState().type == StateType::Reply) { //state is reply
        if (whoFrom.getState().direction != d) { //different direction
            return;
        }
        if (getState().type == StateType::Relay) { //same statetype
            State s{StateType::Reply, whoFrom.getState().colour, whoFrom.getState().direction};
            setState(s);
            toggle();
            notifyObservers();
        }
    }
}

// when they've changed state
Info Cell::getInfo() const {
    Info i{r, c, colour};
    return i;
}

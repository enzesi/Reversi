#include <iostream>
#include <string>
#include "grid.h"
#include "state.h"
using namespace std;


int main(int argc, char *argv[]) {
    cin.exceptions(ios::eofbit|ios::failbit);
    string cmd;
    Grid g;

    int size = 0;
    Colour nowplaying = Colour::Black;
    try {
        while (true) {
            cin >> cmd;
            if (cmd == "new") {
                int n;
                cin >> n;
                size = n;
                g.init(n);
                cout << g;
            }
            else if (cmd == "play") {
                int r = 0, c = 0;
                cin >> r >> c;
                if (r >= size || c >= size) {
                    continue;
                }
                try {
                    g.setPiece(r, c, nowplaying);
                }
                catch (bool error) {
                    continue;
                }
                if (nowplaying == Colour::Black) {
                    nowplaying = Colour::White;
                }
                else {
                    nowplaying = Colour::Black;
                }
                cout << g;
            }
            if (g.isFull()) {
                if (g.whoWon() == Colour::Black) {
                    cout << "Black Wins!" << endl;
                }
                else if (g.whoWon() == Colour::White) {
                    cout << "White Wins!" << endl;
                }
                else {
                    cout << "Tie!" << endl;
                }
            }
        }
  }
  catch (ios::failure &) {}
}

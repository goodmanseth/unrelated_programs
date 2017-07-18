#include <iostream>
#include <iomanip>
#include <sstream>
#include "gameState.h"

using namespace std;

Game::Game() {
    for(int i=0; i<3; i++) {
        for(int j=0; j<3; j++) {
            board[i][j] = (i+1)*(j+1) + '0';
        }
    }
}



void Game::startGame() {
    printBoard();
}

void Game::printBoard() {
    cout << flush;
    cout << "\n\nTic Tac Toe\n\n";
    cout << "Human (X) - Computer (O)" << endl << endl;
    cout << endl;

    cout << "     |     |     " << endl;
    cout << "  " << "1" << "  |  " << "2" << "  |  " << "3" << endl;
    
    cout << "_____|_____|_____" << endl;
    cout << "     |     |     " << endl;
    
    cout << "  " << "4" << "  |  " << "5" << "  |  " << "6" << endl;
    
    cout << "_____|_____|_____" << endl;
    cout << "     |     |     " << endl;

    cout << "  " << "7" << "  |  " << "8" << "  |  " << "9" << endl;
    cout << "     |     |     " << endl << endl;
}

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

void Game::getMove() {
    bool valid = false;
    cout << "Please enter the number corresponding to a location on the board." << endl;
    char move;
    while(!valid) {
        cout << "Your move: ";
        cin >> move;
        for(int i=0; i<3 && !valid; i++) {
            for(int j=0; j<3; j++) {
                if (board[i][j] == move) {
                    valid = true;
                    board[i][j] = 'X';
                    break;
                }
            }
        }
        if (!valid) {
            cout << "Invalid move. Please try again." << endl;
        }
    }
}

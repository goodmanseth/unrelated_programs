#include <iostream>
#include <iomanip>
#include <sstream>
#include "gameState.h"

using namespace std;

Game::Game() {
    for(int i=0; i<3; i++) {
        for(int j=0; j<3; j++) {
            board[i][j] = 3*i + (j+1) + '0';
        }
    }
}

void Game::startGame() {
    printBoard();
    while(!checkWinner(HUMAN) && !checkWinner(AI)) {
        getMove();
        printBoard();
    }
}

void Game::printBoard() {
    cout << flush;
    cout << "\n\nTic Tac Toe\n\n";
    cout << "Human (X) - Computer (O)" << endl << endl;
    cout << endl;

    cout << "     |     |     " << endl;
    cout << "  " << board[0][0] << "  |  " << board[0][1] << "  |  " << board[0][2] << endl;
    
    cout << "_____|_____|_____" << endl;
    cout << "     |     |     " << endl;
    
    cout << "  " << board[1][0] << "  |  " << board[1][1] << "  |  " << board[1][2] << endl;
    
    cout << "_____|_____|_____" << endl;
    cout << "     |     |     " << endl;

    cout << "  " << board[2][0] << "  |  " << board[2][1] << "  |  " << board[2][2] << endl;
    cout << "     |     |     " << endl << endl;
}

void Game::getMove() {
    bool valid = false;
    cout << "Please enter the number corresponding to a location on the board." << endl;
    string move;
    while(!valid) {
        cout << "Your move: ";
        cin >> move;
        if (move.length() != 1) {
            cout << "Invalid move. Please try again." << endl;
            continue;
        }
        for(int i=0; i<3 && !valid; i++) {
            for(int j=0; j<3; j++) {
                if (board[i][j] == move[0]) {
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

int Game::score() {
    if (checkWinner(HUMAN)) return 10;
    else if (checkWinner(AI)) return -10;
    else return 0;
}

void Game::gameOver() {
    if (checkWinner(HUMAN)) return true;
    else if (checkWinner(AI)) return true;

    for(int i=0; i<3; i++) {
        for(int j=0; j<3; j++) {
            if (board[i][j] == 'X' || board[i][j] == 'O') continue;
            else return false;
        }
    }
    return true;
}

bool Game::checkWinner(Player player) {
    char XO;
    if (player == HUMAN) XO = 'X';
    else XO = 'O';

    // checking across and vertical
    for(int i=0; i<3; i++) {
        if (board[i][0] == XO && board[i][1] == XO && board[i][2] == XO)
            return true;
        else if (board[0][i] == XO && board[1][i] == XO && board[2][i] == XO)
            return true;
    }

    // diagonals
    if (board[0][0] == XO && board[1][1] == XO && board[2][2] == XO)
        return true;
    else if (board[0][2] == XO && board[1][1] == XO && board[2][0] == XO)
        return true;

        return false;
}

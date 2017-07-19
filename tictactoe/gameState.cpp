#include <iostream>
#include <iomanip>
#include <sstream>
#include <chrono>
#include <thread>
#include "gameState.h"

using namespace std;

Game::Game() {
    for(int i=0; i<3; i++) {
        for(int j=0; j<3; j++) {
            board[i][j] = 3*i + (j+1) + '0';
        }
    }
}

void Game::playGame() {
    int turn = 0;
    chrono::milliseconds timespan(1000); // 1 second
    printBoard();
    while(!checkWinner(PLAYER1) && !checkWinner(PLAYER2) && !gameOver()) {
        if (turn%2 == 0) {
            getMove(PLAYER1);
            printBoard();
            if (checkWinner(PLAYER1)) cout << "You Win!" << endl << endl;
            turn++;
        } else {
            minimax(board);
            cout << "Computer's turn:" << endl;
            this_thread::sleep_for(timespan);
            printBoard();
            if (checkWinner(PLAYER2)) cout << "Computer Wins!" << endl << endl;
            turn++;
        }
    }
    if (gameOver() && !checkWinner(PLAYER2) && !checkWinner(PLAYER1))
        cout << "It's a Draw!" << endl << endl;
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

void Game::getMove(Player player) {
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
                    board[i][j] = xOrO(player, true);
                    break;
                }
            }
        }
        if (!valid) {
            cout << "Invalid move. Please try again." << endl;
        }
    }
}

char Game::xOrO(Player player, bool trueFalse) {
    if (!trueFalse)
        return ((player == PLAYER1) ? 'O' : 'X');
    return ((player == PLAYER1) ? 'X' : 'O');
}

void Game::minimax(char aiBoard[3][3]) {
    int bestScore = 100;
    Move aiMove;

    for(int i=0; i<3; i++) {
        for(int j=0; j<3; j++) {
            if(aiBoard[i][j] != 'X' && aiBoard[i][j] != 'O') {
                char temp = aiBoard[i][j];      // need to keep track of what the place was
                aiBoard[i][j] = 'O';
                int tempScore = maxScore(aiBoard);
                if (tempScore <= bestScore) {
                    bestScore = tempScore;
                    aiMove.a = i;
                    aiMove.b = j;
                }
                aiBoard[i][j] = temp;           // returning to original state
            }
        }
    }
    board[aiMove.a][aiMove.b] = 'O';
}

int Game::maxScore(char aiBoard[3][3]) {
    if (gameOver()) return score();
    int bestScore = -1000; // arbitrary so the first move will change it
    Move bestMove;

    for(int i=0; i<3; i++) {
        for(int j=0; j<3; j++) {
            if (aiBoard[i][j] != 'X' && aiBoard[i][j] != 'O') {
                char temp = aiBoard[i][j];      // keeping track of original value
                aiBoard[i][j] = 'X';
                int tempScore = minScore(aiBoard);
                if (tempScore >= bestScore) {
                    bestScore = tempScore;
                    bestMove.a = i;
                    bestMove.b = j;
                }
                aiBoard[i][j] = temp;           // returning to original value
            }

        }
    }
    return bestScore;
}


int Game::minScore(char aiBoard[3][3]) {
    if (gameOver()) return score();
    int bestScore = 1000; // arbitrary so the first move will change it
    Move bestMove;

    for(int i=0; i<3; i++) {
        for(int j=0; j<3; j++) {
            if (aiBoard[i][j] != 'X' && aiBoard[i][j] != 'O') {
                char temp = aiBoard[i][j];      // keeping track of original value
                aiBoard[i][j] = 'O';
                int tempScore = maxScore(aiBoard);
                if (tempScore <= bestScore) {
                    bestScore = tempScore;
                    bestMove.a = i;
                    bestMove.b = j;
                }
                aiBoard[i][j] = temp;           // returning to original value
            }

        }
    }
    return bestScore;
}

int Game::score() {
    if (checkWinner(PLAYER1)) return 10;
    else if (checkWinner(PLAYER2)) return -10;
    else return 0;
}

bool Game::gameOver() {
    if (checkWinner(PLAYER1)) return true;
    else if (checkWinner(PLAYER2)) return true;

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
    if (player == PLAYER1) XO = 'X';
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

#include <iostream>
#include <iomanip>
#include <sstream>
#include <"gameState.h">

using namespace std;

Game::Game() {
    for(int i=0; i<3; i++) {
        for(int j=0; j<3; j++) {
            board[i][j] = (i+1)(j+1) + '0';
        }
}



void Game::startGame() {

}

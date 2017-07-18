#include <iostream>

using namespace std;

enum Player {HUMAN,AI};

struct Move {
    int x;
    int y;
};

class Game {
    char board[3][3];

    public:
        Game();

        void startGame();
        
//        void printBoard();

//        void getHumanMove();

//        Move minimax(char aiBoard[3][3]);

//        int minSearch(char aiBoard[3][3]);
        
//        int score();

//        bool gameOver();

//        bool checkWinner(Player player);




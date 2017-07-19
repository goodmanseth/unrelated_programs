#include <iostream>

using namespace std;
enum Player {HUMAN,AI};


class Game {
    char board[3][3];

    public:
        Game();

        void startGame();
        
        void printBoard();

        void getMove();

//        int minimax(char aiBoard[3][3]);

//        int maxSearch(char aiBoard[3][3]));

//        int minSearch(char aiBoard[3][3]);
        
        int score();

        bool gameOver();

        bool checkWinner(Player player);

};

#include <iostream>

using namespace std;
enum Player {PLAYER1,PLAYER2};

class Move {
    public:
        int a;
        int b;
};


class Game {
    char board[3][3];

    public:
        Game();

        void playGame();

        void printBoard();

        void getMove(Player player);

        char xOrO(Player player, bool trueFalse);

        void minimax(char aiBoard[3][3]);

        int maxScore(char aiBoard[3][3]);

        int minScore(char aiBoard[3][3]);

        int score();

        bool gameOver();

        bool checkWinner(Player player);

};

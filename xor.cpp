#include "xor.h"

void setupBoard(char gameBoard[][MAX_Y_SIZE]){
    for (int j = 0; j < MAX_Y_SIZE; j++) {
        for (int i = 0; i < MAX_X_SIZE_MED; i++)
        {
            gameBoard[i][j] = '~';
        }
    }
    int randInt = rand() % 9;
    gameBoard[randInt][0] = 'X';
    gameBoard[4][11] = '^';
} 

void playGame() {
    //cin >> MAX_X_SIZE;
    int score = 0;
    int highScore = 50;
    char gameBoard[MAX_X_SIZE_MED][MAX_Y_SIZE]; //Gameboard
    setupBoard(gameBoard);
    displayBoard(gameBoard, score, highScore);

}

void printMenu() {


}


void displayBoard(char gameBoard[][MAX_Y_SIZE], int score, int highScore) {
    cout << "Score: " << score << " High Score: " << highScore << endl; 
    cout << "-------------------" << endl;
    for (int j = 0; j < MAX_Y_SIZE; j++) {
        cout << " ";
        for (int i = 0; i < MAX_X_SIZE_MED; i++)
        {
            cout << gameBoard[i][j] << " ";
        }
        cout << endl;
    }
    cout << "-------------------" << endl;
}


void runTurn() {

}

bool validateMove(char choice) {

}
#include "xor.h"

void setupBoard(char gameBoard[][MAX_Y_SIZE], int xSize){
    for (int j = 0; j < MAX_Y_SIZE; j++) {
        for (int i = 0; i < xSize; i++)
        {
            gameBoard[i][j] = '~';
        }
    }
    int randInt = rand() % xSize;
    gameBoard[randInt][0] = 'X';
    gameBoard[xSize / 2][11] = '^';
} 

void playGame() {
    int xSize = 13;
    int score = 0;
    int highScore = 50;
    char gameBoard[xSize][MAX_Y_SIZE]; //Gameboard
    setupBoard(gameBoard, xSize);
    displayBoard(gameBoard, score, highScore, xSize);

}

void printMenu() {


}


void displayBoard(char gameBoard[][MAX_Y_SIZE], int score, int highScore, int xSize) {
    cout << "Score: " << score << " High Score: " << highScore << endl; 
    for (int i = 0; i < xSize; i++)
        cout << "--";
    cout  << "-"<< endl;
    for (int j = 0; j < MAX_Y_SIZE; j++) {
        cout << " ";
        for (int i = 0; i < xSize; i++)
        {
            cout << gameBoard[i][j] << " ";
        }
        cout << endl;
    }
    for (int i = 0; i < xSize; i++)
        cout << "--";
    cout  << "-"<< endl;
}


void runTurn() {

}

bool validateMove(char choice) {

}
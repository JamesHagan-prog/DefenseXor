#include "xor.h"

<<<<<<< HEAD
void playGame() {
  int xVal = 9;
  printMenu(xVal);
}

void printMenu(int &xVal) {
  std::string userInput = ".";
  std::cout
      << "\n\n\n\n\n\n\n\n____________________________________________\n       "
         "   Welcome to XOR\n_____________________________________________\n"
      << "The name of the game is to prevent the enemeis (shown as "
         "\"X's)\nfrom getting to the bottom of the board\nYour ship (shown as "
         "\"^\" can move side to side and also has the ability to shoot and "
         "destroyed enemies in its column\nEvery move or fire action takes a "
         "turn, and beware the enemies move one row closer to the bottom after "
         "every turn!\n if they reach the bottom you lose!)\n";

  while (userInput == ".") {
    std::cout << "Press Any Key To Start!";
    std::cin >> userInput;
  }

  std::cout << "Difficulty | Easy - Medium - Hard |";
}

void displayBoard() {}

void runTurn() {}

// bool validateMove(char choice) {

// }
=======
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
>>>>>>> origin/main

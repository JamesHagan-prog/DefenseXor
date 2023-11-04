#include "xor.h"

void printMenu(int &xVal) {
  std::string userInput = ".";
  std::cout
      << "\n\n\n\n\n\n\n\n____________________________________________\n       "
         "   Welcome to XOR\n_____________________________________________\n"
      << "The name of the game is to prevent the enemies (shown as "
         "\"X's)\nfrom getting to the bottom of the board\nYour ship (shown as "
         "\"^\" can move side to side and also has the ability to shoot and "
         "destroyed enemies in its column\nEvery move or fire action takes a "
         "turn, and beware the enemies move one row closer to the bottom after "
         "every turn!\n if they reach the bottom you lose!)\n";

  while (userInput == ".") {
    std::cout << "Press Any Key To Start!";
    std::cin >> userInput;
  }

  std::cout << "Difficulty | Easy - Medium - Hard |" << endl;
}

void displayBoard() {}

void runTurn() {}

// bool validateMove(char choice) {

// }
void setupBoard(char gameBoard[][MAX_Y_SIZE], int xSize) {
  for (int j = 0; j < MAX_Y_SIZE; j++) {
    for (int i = 0; i < xSize; i++) {
      gameBoard[i][j] = '~';
    }
  }
  int randInt = rand() % xSize;
  gameBoard[randInt][0] = 'X';
  gameBoard[xSize / 2][11] = '^';
}

void playGame() {
    char choice = '\n';
    int xSize = 9;
    printMenu(xSize);
    int score = 0;
    int highScore = 50;
    char gameBoard[xSize][MAX_Y_SIZE]; // Gameboard
    setupBoard(gameBoard, xSize);
    int playPos = 0;
    while (choice != 'q' || choice != 'Q') {
        //playPos = findPlayerPosition(gameBoard, xSize);
        displayBoard(gameBoard, score, highScore, xSize);
        cout << "Enter your move: ";
        cin >> choice;
        if (choice == 'q' || choice == 'Q') 
            return;
    }
    cout << "Thanks for playing!" << endl;
}

void printMenu() {}

void displayBoard(char gameBoard[][MAX_Y_SIZE], int score, int highScore, int xSize) {
  cout << "Score: " << score << " High Score: " << highScore << endl;
  for (int i = 0; i < xSize; i++)
    cout << "--";
  cout << "-" << endl;
  for (int j = 0; j < MAX_Y_SIZE; j++) {
    cout << " ";
    for (int i = 0; i < xSize; i++) {
      cout << gameBoard[i][j] << " ";
    }
    cout << endl;
  }
  for (int i = 0; i < xSize; i++)
    cout << "--";
  cout << "-" << endl;
}

bool validateMove(char choice) {}

void fire(int playerPos, char gameBoard[][MAX_Y_SIZE], int score) {
    for(int i = 11; i >= 0; i--) {
        if (gameBoard[playerPos][i] == 'X') {
            gameBoard[playerPos][i] = '~';
            score += 5;
            return;
        }
    }
}

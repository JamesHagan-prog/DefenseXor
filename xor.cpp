#include "xor.h"

void playGame() {
  int xSize = 9;
  printMenu(xSize);
  int score = 0;
  int highScore = 50;
  char gameBoard[xSize][MAX_Y_SIZE]; // Gameboard
  setupBoard(gameBoard, xSize);
  displayBoard(gameBoard, score, highScore, xSize);
}

void printMenu(int &xSize) {
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

  while (userInput != "Enter") {
    std::cout << "Type Enter To Start: ";
    std::cin >> userInput;
  }

  std::cout << "\n\nDifficulty (Easy - Medium - Hard): ";
  std::cin >> userInput;

  if (userInput == "Easy") {
    xSize = 5;
  } else if (userInput == "Medium") {
    xSize = 9;

  } else if (userInput == "Hard") {
    xSize = 15;
  }

  cout << "\n\n\n______STARTING XOR______\n\n\n";
}

void runTurn() {}

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

void displayBoard(char gameBoard[][MAX_Y_SIZE], int score, int highScore,
                  int xSize) {
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

bool validateMove(char choice, int playerPos, int xSize) {

  switch (choice) {
  case 'F':
  case 'f':
    return true;
    break;
  case 'A':
  case 'a':
    if (playerPos == 0) {
      return false;
    } else {
      return true;
    }
    break;
  case 'D':
  case 'd':

    if (playerPos == xSize) {
      return false;
    } else {
      return true;
    }
    break;
  default:
    std::cout << "\nINVALID MOVE\n";
    return false;
  }
}

int findPlayerPosition(char gameBoard[][MAX_Y_SIZE], int xSize) {
  for (int i; i < xSize; i++) {
    if (gameBoard[i][MAX_Y_SIZE - 1] == '^') {
      return i;
    }
  }
  return 0;
}

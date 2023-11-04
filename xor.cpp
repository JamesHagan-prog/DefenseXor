#include "xor.h"

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

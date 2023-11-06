#include "xor.h"

void playGame() {
  string fileName = "scores.txt";
  ifstream infile;
  ofstream outfile;
  char scoreChoi = '\n';
  string highName = "STR";
  cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
  char choice = '\n';
  int mult = 1;
  int xSize = 5;
  printMenu(xSize, mult);
  int score = 0;
  int highScore = 50;
  char gameBoard[xSize][MAX_Y_SIZE]; // Gameboard
  setupBoard(gameBoard, xSize, score);
  int playPos = 0;
  cout << "Would you like to load high scores? (y or n) ";
  cin >> scoreChoi;
  if (scoreChoi == 'y'){
    infile.open(fileName);
    infile >> highScore;
    infile >> highName;
  }
  infile.close();
  outfile.open(fileName);
  while (choice != 'q' || choice != 'Q') {
    cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
    if (score > highScore) {
      highScore = score;
    }
    playPos = findPlayerPosition(gameBoard, xSize);
    displayBoard(gameBoard, score, highScore, xSize, highName);
    cout << "Enter your move: ";
    cin >> choice;

    if (choice == 'q' || choice == 'Q') {
      cout << "Your Score: " << score << endl;
      if (score >= highScore){
        cout << "NEW HIGH SCORE!" << endl;
        cout << "ENTER NEW NAME (3 CHARACTERS)" << endl;
        cin >> highName;
      }
      outfile << highScore << endl;
      outfile << highName;
      outfile.close();
      break;
    }

    if (validateMove(choice, playPos, xSize)) {
      if (choice == 'F' || choice == 'f') {
        fire(playPos, gameBoard, score, mult, highScore);
      } else {
        movePlayer(choice, gameBoard, playPos);
      }
      runTurn(xSize, gameBoard, score, mult, highScore, outfile, highName);
    }
  }
  cout << "Thanks for playing!" << endl;
  return;
}

void printMenu(int &xSize, int &mult) {
  std::string userInput = ".";
  std::cout
      << "\n\n\n\n\n\n\n\n_________________________________________________\n       "
         "   Welcome to XOR\n_________________________________________________\n"
      << "The name of the game is to prevent the enemies (shown as "
         "\"X's)\nfrom getting to the bottom of the board\nYour ship (shown as "
         "\"A\" can move side to side and \nalso has the ability to shoot and "
         "destroy enemies in its column\nEvery move or fire action takes a "
         "turn, and beware the \nenemies move one row closer to the bottom after "
         "every turn! \nif they reach the bottom you lose!)\n";

  while (userInput != "Enter" && userInput != "enter") {
    std::cout << "Type Enter To Start: ";
    std::cin >> userInput;
  }
  userInput = ".";
  while (userInput != "Enter" && userInput != "enter") {
    std::cout << "\n\n\n\nControls:\n\"D or d\": move to the right " << endl;
    std::cout << "\"A or a\": move to the left " << endl;
    std::cout << "\"F or f\": fire (destroys enemies)\nCommands can be chained (ex. fddfaf) " << endl;
    std::cout << "Chaining commands after game-over forces \nquit (Its a feature not a bug)" << endl;
    std::cout << "Type Enter To Start: ";
    std::cin >> userInput;
  }
  std::cout << "\n\n\n\n\nDifficulty (Normal - Hard - Impossible): ";
  std::cin >> userInput;

  if (userInput == "Normal") {
    xSize = 5;
    mult = 1;
  } else if (userInput == "Hard") {
    xSize = 9;
    mult = 2;

  } else if (userInput == "Impossible") {
    xSize = 15;
    mult = 3;
  }

  cout << "\n\n______STARTING XOR______\n\n";
}

void runTurn(int xSize, char gameBoard[][MAX_Y_SIZE], int &score, int mult, int highScore, ofstream& outfile, string &highName){
  char cont = '\n';
  int ran = rand() % 2;
  for (int j = 11; j >= 0; j--) {
    for (int i = 0; i < xSize; i++) {
      if (gameBoard[i][j] == 'X') {
        if (j + 1 == 11 || gameBoard[i][j + 1] == 'A') {
          cout << "GAME OVER" << endl << "Your Score: " << score << endl;
          if (score >= highScore){
            cout << "NEW HIGH SCORE!" << endl;
            cout << "ENTER NEW NAME (3 CHARACTERS)" << endl;
            cin >> highName;
          }
          cout << "Would you like to Continue? (y or n) ";
          cin >> cont;
          if (cont == 'y' || cont == 'Y') {
            setupBoard(gameBoard, xSize, score);
            return;
          }
          else {
            outfile << highScore << endl;
            outfile << highName;
            outfile.close();
            exit(0);
          }
        }
        else {
          gameBoard[i][j] = '~';
          gameBoard[i][j + 1] = 'X';
        }
      }
    }
  }
  if (mult != 3) {
    if (ran == 1) {
      gameBoard[rand() % xSize][0] = 'X';
    }
  }
  else {
    gameBoard[rand() % xSize][0] = 'X';
  }
}

void setupBoard(char gameBoard[][MAX_Y_SIZE], int xSize,int &score) {
  for (int j = 0; j < MAX_Y_SIZE; j++) {
    for (int i = 0; i < xSize; i++) {
      gameBoard[i][j] = '~';
    }
  }
  int randInt = rand() % xSize;
  gameBoard[randInt][0] = 'X';
  gameBoard[xSize / 2][11] = 'A';
  score = 0;
}

void printMenu() {}

void displayBoard(char gameBoard[][MAX_Y_SIZE], int score, int highScore,
                  int xSize, string highName) {
  cout << "Score: " << score << " High Score: " << highScore << " " << highName << endl;
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
      std::cout << "\nINVALID MOVE\n";
      return false;
    } else {
      return true;
    }
    break;
  case 'D':
  case 'd':

    if (playerPos == (xSize - 1)) {
      std::cout << "\nINVALID MOVE\n";
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
  for (int i = 0; i < xSize; i++) {
    if (gameBoard[i][MAX_Y_SIZE - 1] == 'A') {
      return i;
    }
  }
  return 0;
}

void fire(int playerPos, char gameBoard[][MAX_Y_SIZE], int &score, int mult, int &highScore) {
  for (int i = 11; i >= 0; i--) {
    if (gameBoard[playerPos][i] == 'X') {
      gameBoard[playerPos][i] = '~';
      score += 10 * mult;
      if (score > highScore) {
      highScore = score;
      }
      return;
    }
  }
}

void movePlayer(char direction, char gameBoard[][MAX_Y_SIZE], int playPos) {
  switch (direction) {
  case 'A':
  case 'a':
    gameBoard[playPos][MAX_Y_SIZE - 1] = '~';
    gameBoard[playPos - 1][MAX_Y_SIZE - 1] = 'A';
    break;
  case 'D':
  case 'd':
    gameBoard[playPos][MAX_Y_SIZE - 1] = '~';
    gameBoard[playPos + 1][MAX_Y_SIZE - 1] = 'A';
    break;
  default:
    break;
  }
}

#ifndef XOR_H
#define XOR_H

<<<<<<< HEAD
=======
using namespace std;

>>>>>>> origin/main
#include <cstdlib>
#include <iostream>
#include <ctime>

<<<<<<< HEAD
using namespace std;

const int Y_SIZE = 12;

void playGame();
void printMenu(int &xVal);
void displayBoard();
void runTurn();
bool validateMove(char choice);
=======
const int MAX_Y_SIZE = 12; //Default

void setupBoard(char gameBoard[][MAX_Y_SIZE], int xSize);
void playGame();
void printMenu();
void displayBoard(char gameBoard[][MAX_Y_SIZE], int score, int highScore, int xSize);
void runTurn();
bool validateMove(char choice);      
>>>>>>> origin/main


#endif
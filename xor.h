#ifndef XOR_H
#define XOR_H

using namespace std;

#include <cstdlib>
#include <iostream>
#include <ctime>

const int MAX_X_SIZE_MED = 9; //Default
const int MAX_X_SIZE_ESY = 5; //Default
const int MAX_X_SIZE_HRD = 15; //Default
const int MAX_Y_SIZE = 12; //Default

void setupBoard(char gameBoard[][MAX_Y_SIZE]);
void playGame();
void printMenu();
void displayBoard(char gameBoard[][MAX_Y_SIZE], int score, int highScore);
void runTurn();
bool validateMove(char choice);      


#endif
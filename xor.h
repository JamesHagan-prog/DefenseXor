#ifndef XOR_H
#define XOR_H

using namespace std;

#include <cstdlib>
#include <ctime>
#include <iostream>

const int MAX_Y_SIZE = 12; // Default

void setupBoard(char gameBoard[][MAX_Y_SIZE], int xSize, int &score);
void printMenu(int &xVal);
void playGame();
void displayBoard(char gameBoard[][MAX_Y_SIZE], int score, int highScore,
                  int xSize);
void runTurn(int xSize, char gameBoard[][MAX_Y_SIZE], int &score);
bool validateMove(char choice, int, int);
void fire(int playerPos, char gameBoard[][MAX_Y_SIZE], int &score);
int findPlayerPosition(char gameBoard[][MAX_Y_SIZE], int);
void movePlayer(char, char[][MAX_Y_SIZE], int);

#endif

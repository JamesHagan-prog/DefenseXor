#ifndef XOR_H
#define XOR_H

#include <cstdlib>
#include <iostream>
#include <ctime>

using namespace std;

const int Y_SIZE = 12;

void playGame();
void printMenu(int &xVal);
void displayBoard();
void runTurn();
bool validateMove(char choice);


#endif
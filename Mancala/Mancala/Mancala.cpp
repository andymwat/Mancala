// Mancala.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include "Board.h"
using namespace  std;
int main()
{
    cout << "Hello World! This is Mancala!\n";
	Board* newBoard = new Board();

	newBoard->PrintBoard();
	delete newBoard;

	cin;
	return 0;

}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

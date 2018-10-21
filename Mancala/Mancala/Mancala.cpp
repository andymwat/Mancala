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
	int choice = 0;
	int player = 1;
	while (choice != -1)
	{
		cout << "What to move? ";
		cin >> choice;
		if (choice == -1)
		{
			break;
		}
		cout << "Which player? ";
		cin >> player;
		int result = newBoard->MovePile(choice, player);
		if (result == -1)
		{
			cout << "Error: invalid choice." << endl;
		}
		if (result == 0)
		{
			newBoard->PrintBoard();
		}
		if (result == 1)
		{
			cout << "Go again!" << endl;
			newBoard->PrintBoard();
		}
		if (result == 2)
		{
			cout << "Game over." << endl;
			newBoard->PrintBoard();
			choice = -1;
		}
	}

	delete newBoard;

	return 0;

}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

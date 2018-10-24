// Mancala.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include "Board.h"
#include "AI.h"
using namespace  std;
int main()
{
	int mode = 0;
    cout << "Singleplayer(1) or multiplayer(2)?";
	cin >> mode;
	if (mode != 1 && mode != 2)
	{
		cout << endl << "Please input a valid choice.";
		
		return 1;
	}
	Board newBoard = Board();
	newBoard.PrintBoard();
	
	//multiplayer
	if (mode == 2)
	{
		int choice = 0;
		int player = 1;
		while (choice != -1)
		{
			cout << "Player " << player << "'s turn." << endl;
			cout << "What to move? ";
			cin >> choice;
			if (choice == -1)
			{
				cout << "Exiting game..." << endl;
				break;
			}
			int result = newBoard.MovePile(choice, player);
			if (result == -1)
			{
				cout << "Error: invalid choice." << endl;
			}
			if (result == 0)
			{
				newBoard.PrintBoard();
				if (player == 1)
				{
					player = 2;
				}
				else if (player == 2)
				{
					player = 1;
				}
			}
			if (result == 1)
			{
				cout << "Go again!" << endl;
				newBoard.PrintBoard();
			}
			if (result == 2)
			{
				newBoard.PrintBoard();
				int winner = 0;
				if (newBoard.holes[0] < newBoard.holes[7])
				{
					winner = 1;
				}
				if (newBoard.holes[0] > newBoard.holes[7])
				{
					winner = 2;
				}
				cout << endl << "Game is over." << endl;
				if (winner != 0)
				{
					cout << "Winner is Player " << winner << "!" << endl;
				}
				else
				{
					cout << "The game ended in a tie!" << endl;
				}
				choice = -1;
			}
		}
	}
	//singleplayer
	else if (mode == 1)
	{
		AI opponent = AI();
		int choice = 0;
		while (choice != -1)
		{
			cout << "What to move? ";
			cin >> choice;
			if (choice == -1)
			{
				cout << "Exiting game..." << endl;
				break;
			}
			int result = newBoard.MovePile(choice, 1);
			if (result == -1)
			{
				cout << "Error: invalid choice." << endl;
			}
			if (result == 0)
			{
				newBoard.PrintBoard();

				//calculate AI's best move and perform it
				newBoard.MovePile(opponent.FindBestMove(newBoard, 2), 2);

			}
			if (result == 1)
			{
				cout << "Go again!" << endl;
				newBoard.PrintBoard();
			}
			if (result == 2)
			{
				newBoard.PrintBoard();
				int winner = 0;
				if (newBoard.holes[0] < newBoard.holes[7])
				{
					winner = 1;
				}
				if (newBoard.holes[0] > newBoard.holes[7])
				{
					winner = 2;
				}
				cout << endl << "Game is over." << endl;
				if (winner != 0)
				{
					cout << "Winner is Player " << winner << "!" << endl;
				}
				else
				{
					cout << "The game ended in a tie!" << endl;
				}
				choice = -1;
			}
		}
	}

	return 0;

}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

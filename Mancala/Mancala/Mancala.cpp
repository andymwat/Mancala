// Mancala.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include "Board.h"
#include "MoveTree.h"
#include "AI.h"
using namespace  std;
//the search depth of the AI
int depth = 8;
int main()
{
	int mode = 0;
	cout << "Singleplayer(1), multiplayer(2), or AI vs AI(3)?";
	cin >> mode;
	if (mode != 1 && mode != 2&& mode != 3)
	{
		cout << endl << "Please input a valid choice.";

		return 1;
	}
	Board newBoard = Board();
	

	//multiplayer
	if (mode == 2)
	{
		newBoard.PrintBoard();
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
		cout << "Depth of AI? ";
		cin >> depth;
		cout << endl;
		newBoard.PrintBoard();
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
				int aiMove = opponent.SearchMoveTree(newBoard, 2, depth);
				cout << "AI is moving " << aiMove << endl;
				int move = newBoard.MovePile(aiMove, 2);
				while (move == 1)
				{
					cout << "AI gets another turn!" << endl;
					aiMove = opponent.SearchMoveTree(newBoard, 2, depth);
					cout << "AI is moving " << aiMove << endl;
					move = newBoard.MovePile(aiMove, 2);
				}
				newBoard.PrintBoard();

			}
			if (result == 1)
			{
				cout << "Go again!" << endl;
				newBoard.PrintBoard();
			}
			if (result == 2 || newBoard.GameIsOver())
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

	//AI vs AI
	else if (mode == 3)
	{
	int depth1, depth2;
	cout << "Depth for AI 1? ";
	cin >> depth1;
	cout << endl << "Depth for AI 2? ";
	cin >> depth2;
	cout << endl;
		AI ai1 = AI();
		AI ai2 = AI();
		int whichAI = 1;
		int choice = 0;
		while (choice != -1)
		{
			if (whichAI == 1)
			{
				int aiMove = ai1.SearchMoveTree(newBoard, 1, depth1);
				cout << "AI 1 is moving " << aiMove << endl;
				int move = newBoard.MovePile(aiMove, 1);
				newBoard.PrintBoard();
				while (move == 1)
				{
					cout << "AI 1 gets another turn!" << endl;
					aiMove = ai1.SearchMoveTree(newBoard, 1, depth1);
					cout << "AI 1 is moving " << aiMove << endl;
					move = newBoard.MovePile(aiMove, 1);
					newBoard.PrintBoard();
				}
				
				whichAI = 2;
			}
			else
			{
				int aiMove = ai2.SearchMoveTree(newBoard, 2, depth2);
				cout << "AI 2 is moving " << aiMove << endl;
				int move = newBoard.MovePile(aiMove, 2);
				newBoard.PrintBoard();
				while (move == 1)
				{
					cout << "AI 2 gets another turn!" << endl;
					aiMove = ai2.SearchMoveTree(newBoard, 2, depth2);
					cout << "AI 2 is moving " << aiMove << endl;
					move = newBoard.MovePile(aiMove, 2);
					newBoard.PrintBoard();
				}
				whichAI = 1;
			}
			

			if (newBoard.GameIsOver())
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
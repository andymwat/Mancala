#include "pch.h"
#include "AI.h"
#include <iostream>
using namespace std;

AI::AI()
{
}


AI::~AI()
{
}
int AI::FindBestMove(Board& board, int player)
{
	//goes through each pile and determines which move will give the AI the best board
	
	int bestPile = -1;
	double bestOutcome = 0.0;
	if (player == 1)
	{
		for (int slot = 1; slot < 7; slot++)
		{
			
			Board nextBoard = board;
			if (nextBoard.MovePile(slot, player) != -1) {
				if (nextBoard.GetBoardValue(player) > bestOutcome)
				{
					bestPile = slot;
					bestOutcome = nextBoard.GetBoardValue(player);
				}
			}
		}
		if (bestPile == -1)
		{
			cout << "Error, no valid moves to take.";
			return -1;
		}
		cout << "Best move is " << bestPile << endl;
		return bestPile;
	}
	else if (player == 2)
	{
		for (int slot = 8; slot < 14; slot++)
		{
			Board nextBoard = board;
			if (nextBoard.MovePile(slot, player) != -1) {
				if (nextBoard.GetBoardValue(player) > bestOutcome)
				{
					bestPile = slot;
					bestOutcome = nextBoard.GetBoardValue(player);
				}
			}
		}
		if (bestPile == -1)
		{
			cout << "Error, no valid moves to take.";
			return -1;
		}
		return bestPile;
	}



	//std::cout << endl << endl << "NOT YET IMPLEMENTED" << endl << endl;
	//return -1;

	cout << "Error, invalid player" << endl;
	return -1;

}


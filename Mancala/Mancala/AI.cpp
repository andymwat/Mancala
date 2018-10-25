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
//calculates a 1-level move tree from a given board and puts the resulting tree into result
void AI::CalculateMoveTree(Board board, BoardNode* result, int player) {
	result = new BoardNode(board, player);
	//loop through possible moves on board
	for (unsigned int i = (player*7)-6; i< (player*7); i++)
	{
		//create a copy of the current board
		Board nextBoard = Board(board);
		//see if the move is valid
		int nextMove = nextBoard.MovePile(i,player);
		if ( nextMove== -1)
		{
			//if move is invalid
			continue;
		}
		if (nextMove == 0)
		{
			//if move is valid, add subBoard to tree
			result->AddNode(new BoardNode(nextBoard, player));
		}
		if (nextMove == 1)
		{
			//TODO
			//If move results in another turn
			throw "Got another turn. Not yet implemented.";
		}
		if (nextMove == 2)
		{
			//TODO
			//If move results in game over
			throw "Game over. Not yet implemented.";
		}
	}



}


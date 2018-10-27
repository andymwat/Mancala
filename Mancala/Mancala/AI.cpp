#include "pch.h"
#include "AI.h"
#include "MoveTree.h"
#include <iostream>
using namespace std;

AI::AI()
{
}


AI::~AI()
{
}
//DEPRECATED
//DO NOT USE
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
			cout << "Error, no valid moves to take."<<endl;
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
			cout << "Error, no valid moves to take."<<endl;
			return -1;
		}
		return bestPile;
	}



	//std::cout << endl << endl << "NOT YET IMPLEMENTED" << endl << endl;
	//return -1;

	cout << "Error, invalid player" << endl;
	return -1;

}
//returns the best move given the current board, what player the AI is, and a search depth
int AI::SearchMoveTree(Board& currentBoard, int player, int depth)
{
	int bestPile = -1;
	double bestOutcome = -100000;
	BoardNode * moveTree = new BoardNode(currentBoard, player);
	moveTree->GenerateTree(depth, player, player);
	//cout << "Tree's total value is currently: " << moveTree->CalculateValue() << endl;
	for (unsigned int i = 0; i < moveTree->numberOfNodes; i++)
	{
		
		double outcome = moveTree->subNodes[i]->CalculateValue();
		cout << "Spot " << moveTree->subNodes[i]->tileToGetHere << "'s value is " << outcome << endl;
		//if move option is best so far
		if (outcome > bestOutcome)
		{
			bestOutcome = outcome;
			bestPile = moveTree->subNodes[i]->tileToGetHere;
		}
	}
	if (bestPile == -1)
	{
		//choose the only remaining move and take it
		if (!(currentBoard.GameIsOver()))
		{
			for (int i = (player*7) -6; i< (player * 7); i++)
			{
				if (currentBoard.holes[i] != 0)
				{
					return i;
				}
			}
		}

		cout << "Error, no valid moves to take.";
		return -1;
	}
	cout << "Best move is " << bestPile << endl;
	

	//this will print out the move tree if uncommented
	/*
	 *cout << "Current tree: " << endl;
	for (unsigned int i = 0; i < moveTree->numberOfNodes; i++)
	{
		moveTree->subNodes[i]->PrintTree(1);
		
	}
	*/
	delete moveTree;
	return bestPile;
}




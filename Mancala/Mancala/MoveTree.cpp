//
// Created by andrew on 10/25/18.
//
#include "pch.h"
#include "Board.h"
#include "MoveTree.h"
#include <iostream>

using namespace std;

BoardNode::BoardNode(Board board, int p) {
    numberOfNodes = 0;
    currentBoard = board;
    subNodes = vector<BoardNode*>();
    player = p;
}
BoardNode::~BoardNode() {
    //if this node has subnodes, delete those
	for (unsigned int i = 0; i <numberOfNodes; i++)
	{
		delete (subNodes[i]);
	}
}
double BoardNode::CalculateValue() {
    //if this is the last node, simply return the board value
    if (numberOfNodes == 0)
    {
        return currentBoard.GetBoardValue(player);
    }
    //otherwise, return the average value of the subnodes
    else
    {
        double total = 0.0;
        for (unsigned int i = 0; i<numberOfNodes; i++)
        {
            total += subNodes[i]->CalculateValue();
        }
        return (total / numberOfNodes);
    }
}
void BoardNode::AddNode(BoardNode * boardToAdd) {
    subNodes.push_back(boardToAdd);
    numberOfNodes++;
}
//generates a tree for a node. InitialPlayer is only used for calculating the value of a game ending board
void BoardNode::GenerateTree(int depth, int player, int initialPlayer)
{
	//if end of tree
	if (depth == 0)
	{
		return;
	}
	//loop through all pieces on your side
	for (int i = (player * 7) - 6; i < (player * 7); i++)
	{
		Board nextBoard = Board(currentBoard);
		int nextMove = nextBoard.MovePile(i, player);
		//if proposed move is succesful
		if (nextMove == 0)
		{
			int newPlayer = 0;
			if (player == 1)
			{
				newPlayer = 2;
			}
			else
			{
				newPlayer = 1;
			}
			
			BoardNode* newNode = new BoardNode(nextBoard, newPlayer);

			//generate a tree based on all of possible opponent's moves
			newNode->GenerateTree(depth - 1, newPlayer, initialPlayer);
			newNode->tileToGetHere = i;
			this->AddNode(newNode);
		}
		//Same as above, but player doesn't switch (it's your turn again)
		else if (nextMove == 1)
		{
			
			BoardNode* newNode = new BoardNode(nextBoard, player);

			//generate a tree based on all of possible next moves
			newNode->GenerateTree(depth - 1, player, initialPlayer);
			newNode->tileToGetHere = i;
			this->AddNode(newNode);
		}
		//if game would be over, add next node, but don't generate more subnodes.
		else if (nextMove == 2)
		{
			BoardNode* newNode = new BoardNode(nextBoard, initialPlayer);
			newNode->tileToGetHere = i;
			this->AddNode(newNode);
			return;
		}
	}
}

void BoardNode::PrintTree(int numTabs)
{
	cout << "If player " << player << " chose " << tileToGetHere << ", then value is " << CalculateValue() << endl;
	
	for (unsigned int i = 0; i < numberOfNodes; i++)
	{
		for (int j = 0; j < numTabs; j++)
		{
			cout << " \t";
		}
		subNodes[i]->PrintTree(numTabs+1);
	}
}


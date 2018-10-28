//
// Created by andrew on 10/25/18.
//
#pragma once
#include "Board.h"
#include <vector>

using namespace std;

struct BoardNode
{

    //the player for this tree of boards.
    //will almost always be 2
    int player;
    //the board that this node represents
    Board currentBoard;
    //a list of pointers to other nodes
    //will be nullptr if this is the final node in the tree
    vector<BoardNode*> subNodes;
    //the number of nodes that come off of this one
    //will be between 0 (last node in tree) and 6 (can move every pile)
    unsigned int numberOfNodes;
    //calculates the value of this node, averaging together all of its subnodes
    double CalculateValue();
    //Add a node to the list
    void AddNode(BoardNode *);
	//Generates a tree with a defined depth
	void GenerateTree(int, int, int);
    BoardNode(Board, int, int);
    ~BoardNode();
	//What tile had to be moved to get to this state
	int tileToGetHere = -1;
	//Prints out the current game tree
	void PrintTree(int);

	int initialPlayer;

};



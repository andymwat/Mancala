//
// Created by andrew on 10/25/18.
//
#include "Board.h"
#include "MoveTree.h"
#include <memory.h>
#include <cstdlib>

BoardNode::BoardNode(Board board, int p) {
    numberOfNodes = 0;
    currentBoard = board;
    subNodes = vector<BoardNode*>();
    player = p;
}
BoardNode::~BoardNode() {
    //if this node has children, delete those

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
            total += subNodes[i].CalculateValue();
        }
        return (total / numberOfNodes);
    }
}
void BoardNode::AddNode(BoardNode * boardToAdd) {
    subNodes.push_back(boardToAdd);
    numberOfNodes++;
}
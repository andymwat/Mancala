#pragma once
#include "Board.h"
#include "MoveTree.h"
class AI
{
public:
	AI();
	~AI();
	int FindBestMove(Board&, int);

	void CalculateMoveTree(Board, BoardNode*, int);
};


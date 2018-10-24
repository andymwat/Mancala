#pragma once
#include "Board.h"
class AI
{
public:
	AI();
	~AI();
	int FindBestMove(Board&, int);
};


#pragma once
class Board
{
public:
	Board();
	~Board();
	int holes[14];
	void PrintBoard();
	int MovePile(int, int);
	double GetBoardValue(int);
	bool GameIsOver();
	double GetBoardValueOld(int);
};


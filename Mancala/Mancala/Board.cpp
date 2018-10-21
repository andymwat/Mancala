#include "pch.h"
#include "Board.h"
#include <iostream>
using namespace std;

Board::Board()
{
	//Fill the board with initial stones
	for (int i = 1; i<7; i++)
	{
		holes[i] = 4;
	}
	for (int i = 8; i < 14; i++)
	{
		holes[i] = 4;
	}
	holes[0] = 0;
	holes[7] = 0;
}


Board::~Board()
{
}

void Board::PrintBoard()
{
	cout << "-------------------" << endl;
	cout << "|X|" << holes[13] << "|" << holes[12] << "|" << holes[11] << "|" << holes[10] << "|" << holes[9] << "|" << holes[8] << "|X|"<< endl;
	cout << "|" <<holes[0] <<"|           |"<<holes[7]<<"|" << endl;
	cout << "|X|"<<holes[1]<<"|" << holes[2] << "|" << holes[3] << "|" << holes[4] << "|" << holes[5] << "|" << holes[6] << "|X|" << endl;
	cout << "-------------------" << endl;
}

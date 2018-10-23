#include "pch.h"
#include "Board.h"
#include <iostream>
using namespace std;

//Fill the board with initial stones
Board::Board()
{
	
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

//Prints out the current board to the screen
void Board::PrintBoard()
{
	cout << "-------------------" << endl;
	cout << "|X|" << holes[13] << "|" << holes[12] << "|" << holes[11] << "|" << holes[10] << "|" << holes[9] << "|" << holes[8] << "|X|"<< endl;
	cout << "|" <<holes[0] <<"|           |"<<holes[7]<<"|" << endl;
	cout << "|X|"<<holes[1]<<"|" << holes[2] << "|" << holes[3] << "|" << holes[4] << "|" << holes[5] << "|" << holes[6] << "|X|" << endl;
	cout << "-------------------" << endl;
}


//Returns: -1 for invalid move, 0 for success, 1 for success and another turn, 2 for game finished
int Board::MovePile(int slot, int player)
{
	if ((player!= 1 && player !=2) || slot <1 || slot > 13)
	{
		return -1;
	}
	//if you try to move a mancala or an empty hole, it returns false
	if (slot == 0 || slot == 7 || holes[slot] == 0)
	{
		return -1;
	}
	//test to see if you move an opponent's piece
	if (player ==1)
	{
		if (slot >7)
		{
			return -1;
		}
	}
	if (player ==2)
	{
		if (slot < 7)
		{
			return -1;
		}
	}

	int piecesInHand = holes[slot];
	holes[slot] = 0;
	int currentSlot = slot;
	while (piecesInHand != 0)
	{
		currentSlot++;
		if (currentSlot > 13)
		{
			currentSlot = 0;
		}
		//if the slot that is going to be placed in is not the opponent's mancala
		if (!(currentSlot == 0 && player==1) && !(currentSlot == 7 && player ==2) )
		{
			//place a stone in the hole
			holes[currentSlot]++;
			piecesInHand--;
		}
		//if trying to place in the opponent's mancala, just move on to the next one
		else
		{
			currentSlot++;
		}
		
	}
	//if final slot didnt have anything before you put your tile there
	if (holes[currentSlot] ==1)
	{
		if (player == 1)
		{
			if (currentSlot < 7 && currentSlot > 0)
			{
				holes[7] += holes[14 - currentSlot];
				holes[14 - currentSlot] = 0;
			}
		}
		else if (player == 2)
		{
			if (currentSlot > 7 && currentSlot < 14)
			{
				holes[0] += holes[-(currentSlot - 14)];
				holes[-(currentSlot - 14)] = 0;
			}
		}
	}

	//if no pieces left on one side, return 2 (game is over)
	if (GameIsOver())
	{
		return 2;
	}

	//if you finish in your mancala, you get another turn
	if ((currentSlot == 0 && player ==2) || (currentSlot  == 7 && player ==1) )
	{
		return 1;
	}
	
	return 0;
}

//Returns the value of the current board from the perspective of a specified player.
//Returns between 1.0 and 0.0, with higher values corresponding to a more valuable board.
//1.0 means the game is won or is guaranteed to be won, while 0.0 means that the game is guaranteed to be lost.
double Board::GetBoardValue(int player)
{
	//TODO
	throw "Not yet implemented";
}

//Returns whether or not the game is over.
//If it is, it finishes up, moving the remaining pieces into the mancala.
bool Board::GameIsOver()
{
	//Ugly, will need to refactor. 
	//Checks to see if one side of the board is empty
	if ((holes[1] == 0 && holes[2] == 0 && holes[3] == 0 && holes[4] == 0 && holes[5] == 0 && holes[6] == 0))
	{
		holes[0] += holes[13] + holes[12] + holes[11] + holes[10] + holes[9] + holes[8];
		holes[13] = holes[12] = holes[11] = holes[10] = holes[9] = holes[8] = 0;
		return true;
	}
	else if (holes[13] == 0 && holes[12] == 0 && holes[11] == 0 && holes[10] == 0 && holes[9] == 0 && holes[8] == 0)
	{
		holes[7] += holes[1] + holes[2] + holes[3] + holes[4] + holes[5] + holes[6];
		holes[1] = holes[2] = holes[3] = holes[4] = holes[5] = holes[6] = 0;
		return true;
	}
	return false;
}



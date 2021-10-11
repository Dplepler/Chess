#include <iostream>
#include "board.h"


int main(void)
{
	unsigned int i = 0;
	unsigned int i2 = 0;


	Board* board = new Board();

	for (i = 0; i < BOARD_HEIGHT; i++)
	{
		for (i2 = 0; i2 < BOARD_WIDTH; i2++)
		{
			if (board->board[i][i2])
				std::cout << Piece::idToString(board->board[i][i2]->id) << "\n";
			else
				std::cout << "Empty\n";
		}
	}


}
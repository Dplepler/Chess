#include <iostream>
#include "board.h"


int main(void)
{
	unsigned int i = 0;

	Board* board = new Board();
	size_t size = board->board.size();

	for (i = 0; i < size; i++)
	{
		if (board->board[i])
			std::cout << Piece::idToString(board->board[i]->id) << "\n";
		else
			std::cout << "Empty\n";
	}


}
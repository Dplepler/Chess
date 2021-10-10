#include "board.h"

Board::Board()
{
	unsigned int i = 0;
	unsigned int i2 = 0;

	size_t boardSize = BOARD_HEIGHT * BOARD_WIDTH;

	const char board[BOARD_HEIGHT][BOARD_WIDTH] = { {'r', 'n', 'b', 'q', 'k', 'b', 'n', 'r'}
												,	{'p', 'p', 'p', 'p', 'p', 'p', 'p', 'p'}
												,	{'#', '#', '#', '#', '#', '#', '#', '#'}
												,	{'#', '#', '#', '#', '#', '#', '#', '#'}
												,	{'#', '#', '#', '#', '#', '#', '#', '#'}
												,	{'#', '#', '#', '#', '#', '#', '#', '#'}
												,	{'p', 'p', 'p', 'p', 'p', 'p', 'p', 'p'}
												,	{'r', 'n', 'b', 'k', 'q', 'b', 'n', 'r'} };


	for (i = 0; i < BOARD_HEIGHT; i++)
	{
		for (i2 = 0; i2 < BOARD_WIDTH; i2++)
		{
			switch (board[i][i2])
			{
			
			//case 'r': Piece * rook = new Rook(Line::LINE_1, Column::COL_A);



			}


		}
	}



	Piece* rook = new Rook(Line::LINE_1, Column::COL_A);
	Piece* rook = new Rook(Line::LINE_1, Column::COL_H);
	Piece* rook = new Rook(Line::LINE_8, Column::COL_A);
	Piece* rook = new Rook(Line::LINE_8, Column::COL_H);



}

void Board::updateBoard(Piece* srcPiece, Piece* dstPiece)
{



}
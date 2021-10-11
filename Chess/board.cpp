#include "board.h"

Board::Board()
{
	unsigned int i = 0;
	unsigned int i2 = 0;

	size_t boardSize = BOARD_HEIGHT * BOARD_WIDTH;

	// Template for a chess board
	const char board[BOARD_HEIGHT][BOARD_WIDTH] = { {'r', 'n', 'b', 'q', 'k', 'b', 'n', 'r'}
												,	{'p', 'p', 'p', 'p', 'p', 'p', 'p', 'p'}
												,	{'#', '#', '#', '#', '#', '#', '#', '#'}
												,	{'#', '#', '#', '#', '#', '#', '#', '#'}
												,	{'#', '#', '#', '#', '#', '#', '#', '#'}
												,	{'#', '#', '#', '#', '#', '#', '#', '#'}
												,	{'p', 'p', 'p', 'p', 'p', 'p', 'p', 'p'}
												,	{'r', 'n', 'b', 'q', 'k', 'b', 'n', 'r'} };


	for (i = 0; i < BOARD_HEIGHT; i++)
	{
		for (i2 = 0; i2 < BOARD_WIDTH; i2++)
		{
			// Push all pieces onto the board, for places with no piece, push a null pointer
			switch (board[i][i2])
			{
			
			case 'r': this->board.push_back(new Rook(Piece::intToLine(i), Piece::intToColumn(i2))); break;
			case 'n': this->board.push_back(new Knight(Piece::intToLine(i), Piece::intToColumn(i2))); break;
			case 'b': this->board.push_back(new Bishop(Piece::intToLine(i), Piece::intToColumn(i2))); break;
			case 'k': this->board.push_back(new King(Piece::intToLine(i), Piece::intToColumn(i2))); break;
			case 'q': this->board.push_back(new Queen(Piece::intToLine(i), Piece::intToColumn(i2))); break;
			case 'p': this->board.push_back(new Pawn(Piece::intToLine(i), Piece::intToColumn(i2))); break;
			default:  this->board.push_back(nullptr);

			}
		}
	}

}

void Board::updateBoard(Piece* srcPiece, Piece* dstPiece)
{



}
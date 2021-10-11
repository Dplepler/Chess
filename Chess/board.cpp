#include "board.h"

Board::Board()
{
	unsigned int i = 0;
	unsigned int i2 = 0;

	bool color = false;

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

		if (!color && i > TWICE)
			color = true;

		for (i2 = 0; i2 < BOARD_WIDTH; i2++)
		{
			

			// Push all pieces onto the board, for places with no piece, push a null pointer
			switch (board[i][i2])
			{
			
			case 'r': this->board[i].push_back(new Rook(i, i2, color)); break;
			case 'n': this->board[i].push_back(new Knight(i, i2, color)); break;
			case 'b': this->board[i].push_back(new Bishop(i, i2, color)); break;
			case 'k': this->board[i].push_back(new King(i, i2, color)); break;
			case 'q': this->board[i].push_back(new Queen(i, i2, color)); break;
			case 'p': this->board[i].push_back(new Pawn(i, i2, color)); break;
			default:  this->board[i].push_back(nullptr);

			}
		}
	}

}

void Board::updateBoard(Piece* srcPiece, Piece* dstPiece)
{



}

Piece* Board::getPiece(unsigned int line, unsigned int col)
{

	if (line > BOARD_HEIGHT || col > BOARD_WIDTH)
	{
		std::cout << "One or more parameters are too high\n";
		exit(1);
	}

	return this->board[line][col];



}
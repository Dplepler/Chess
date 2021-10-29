#include "board.h"

#include "pawn.h"
#include "rook.h"
#include "knight.h"
#include "bishop.h"
#include "queen.h"
#include "king.h"

Board::Board()
{
	unsigned int i = 0;
	unsigned int i2 = 0;

	bool color = false;

	wxImage* img;
	wxBitmap image;
	std::string file;

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

	img = new wxImage(100, 100);
	

	for (i = 0; i < BOARD_HEIGHT; i++)
	{
		image = wxBitmap(*img);

		// After two lines, switch to the black pieces
		if (color == WHITE && i > TWICE)
			color = BLACK;

		this->board.push_back(std::vector<Piece*>());

		for (i2 = 0; i2 < BOARD_WIDTH; i2++)
		{
			
			// Push all pieces onto the board, for places with no piece, push a null pointer
			switch (board[i][i2])
			{
			
			case 'r':
				
				color == WHITE ? img->LoadFile("Images/7.png", wxBITMAP_TYPE_PNG) : img->LoadFile("Images/0.png", wxBITMAP_TYPE_PNG);

				image = wxBitmap(*img);
				this->board[i].push_back(new Rook(i, i2, color, image));
				break;

			case 'n': 
				color == WHITE ? img->LoadFile("Images/8.png", wxBITMAP_TYPE_PNG) : img->LoadFile("Images/1.png", wxBITMAP_TYPE_PNG);
				
				image = wxBitmap(*img);
				this->board[i].push_back(new Knight(i, i2, color, image));
				break;

			case 'b':
				color == WHITE ? img->LoadFile("Images/11.png", wxBITMAP_TYPE_PNG) : img->LoadFile("Images/2.png", wxBITMAP_TYPE_PNG);

				image = wxBitmap(*img);
				this->board[i].push_back(new Bishop(i, i2, color, image));
				break;

			case 'k':
				color == WHITE ? img->LoadFile("Images/10.png", wxBITMAP_TYPE_PNG) : img->LoadFile("Images/3.png", wxBITMAP_TYPE_PNG);

				image = wxBitmap(*img);
				this->board[i].push_back(new King(i, i2, color, image));
				break;

			case 'q':
				color == WHITE ? img->LoadFile("Images/9.png", wxBITMAP_TYPE_PNG) : img->LoadFile("Images/4.png", wxBITMAP_TYPE_PNG);

				image = wxBitmap(*img);
				this->board[i].push_back(new Queen(i, i2, color, image));
				break;

			case 'p':
				color == WHITE ? img->LoadFile("Images/6.png", wxBITMAP_TYPE_PNG) : img->LoadFile("Images/5.png", wxBITMAP_TYPE_PNG);

				image = wxBitmap(*img);
				this->board[i].push_back(new Pawn(i, i2, color, image));
				break;

			default: this->board[i].push_back(nullptr);

			}
		}
	}



}

void Board::updateBoard(int line, unsigned int col, Piece* piece)
{
	this->board[piece->line][piece->column] = nullptr;
	this->board[line][col] = piece;
}

Piece* Board::getPiece(int line, unsigned int col)
{
	Piece* piece = nullptr;

	if (line > BOARD_HEIGHT - 1 || col > BOARD_WIDTH - 1)
	{
		std::cout << "One or more parameters are too high\n";
	}

	else if (board[line][col])
	{
		piece = this->board[line][col];
	}
	else
	{
		std::cout << "Empty slot\n";
	}


	return piece;
}

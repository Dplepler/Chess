#include "board.h"

#include "pawn.h"
#include "rook.h"
#include "knight.h"
#include "bishop.h"
#include "queen.h"
#include "king.h"

#include "play.h"

Board::Board(Play* play)
{
	unsigned int i = 0;
	unsigned int i2 = 0;

	bool color = false;

	wxImage* img = nullptr;
	wxBitmap* image = nullptr;
	std::string file;

	King* king = nullptr;

	size_t boardSize = BOARD_HEIGHT * BOARD_WIDTH;

	this->play = play;

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
		image = new wxBitmap(*img);

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

				image = new wxBitmap(*img);
				this->board[i].push_back(new Rook(i, i2, color, image));
				break;

			case 'n':
				color == WHITE ? img->LoadFile("Images/8.png", wxBITMAP_TYPE_PNG) : img->LoadFile("Images/1.png", wxBITMAP_TYPE_PNG);

				image = new wxBitmap(*img);
				this->board[i].push_back(new Knight(i, i2, color, image));
				break;

			case 'b':
				color == WHITE ? img->LoadFile("Images/11.png", wxBITMAP_TYPE_PNG) : img->LoadFile("Images/2.png", wxBITMAP_TYPE_PNG);

				image = new wxBitmap(*img);
				this->board[i].push_back(new Bishop(i, i2, color, image));
				break;

			case 'k':

				color == WHITE ? img->LoadFile("Images/10.png", wxBITMAP_TYPE_PNG) : img->LoadFile("Images/3.png", wxBITMAP_TYPE_PNG);
				
				image = new wxBitmap(*img);
				king = new King(i, i2, color, image);
				this->board[i].push_back(king);
				this->kings.push_back(king);
				
				break;

			case 'q':
				color == WHITE ? img->LoadFile("Images/9.png", wxBITMAP_TYPE_PNG) : img->LoadFile("Images/4.png", wxBITMAP_TYPE_PNG);

				image = new wxBitmap(*img);
				this->board[i].push_back(new Queen(i, i2, color, image));
				break;

			case 'p':
				color == WHITE ? img->LoadFile("Images/6.png", wxBITMAP_TYPE_PNG) : img->LoadFile("Images/5.png", wxBITMAP_TYPE_PNG);

				image = new wxBitmap(*img);
				this->board[i].push_back(new Pawn(i, i2, color, image));
				break;

			default: this->board[i].push_back(nullptr);

			}
		}
	}
}

Board::~Board() {}

std::vector<std::vector<Piece*>> Board::getBoard()
{
	return this->board;
}

void Board::updateBoard(int line, int col, Piece* piece)
{
	this->board[piece->getLine()][piece->getColumn()] = nullptr;
	this->board[line][col] = piece;
}

Piece* Board::getPiece(int line, int col) const
{
	Piece* piece = nullptr;

	if (line < BOARD_HEIGHT && line >= 0 && col < BOARD_WIDTH && col >= 0)
	{
		if (board[line][col])
		{
			piece = this->board[line][col];
		}
	}

	return piece;
}

bool Board::checkCheck(bool color)
{
	Piece* piece = nullptr;

	bool flag = false;

	unsigned int i = 0;
	unsigned int i2 = 0;

	// If all the possible checks aren't happening, then the king is not in checl
	if (!this->checkLine(this->kings[color]->getLine() + 1, BOARD_HEIGHT - this->kings[color]->getLine() - 1, this->kings[color]->getColumn(), color)  // Check right line
		&& !this->checkLine(this->kings[color]->getColumn() + 1, BOARD_HEIGHT - this->kings[color]->getColumn() - 1, this->kings[color]->getLine(), color)	// Check right column)
		&& !this->checkLine(0, this->kings[color]->getLine(), this->kings[color]->getColumn(), color)									// Check left line
		&& !this->checkLine(0, this->kings[color]->getColumn(), this->kings[color]->getLine(), color)									// Check left column
		&& !this->checkDiagonal(wxPoint(0, 0), color)												// Left lower corner
		&& !this->checkDiagonal(wxPoint(0, BOARD_HEIGHT), color)									// left upper corner
		&& !this->checkDiagonal(wxPoint(BOARD_WIDTH, BOARD_HEIGHT), color)							// Right upper corner
		&& !this->checkDiagonal(wxPoint(BOARD_WIDTH, 0), color)										// Right lower corner
		&& !this->checkHorse(color))
	{
		this->kings[color]->setCheck(false);
	}

	if (this->kings[color]->isCheck())
		flag = true;

	return flag;
}

bool Board::checkMate(bool color)
{
	bool flag = true;

	int originalLine = this->kings[color]->getLine();
	int originalCol = this->kings[color]->getColumn();

	unsigned int i = 0;
	unsigned int i2 = 0;

	for (i = originalLine - 1; i < KING_RANGE && flag; i++)
	{
		for (i2 = originalCol - 1; i2 < KING_RANGE && flag; i2++)
		{
			this->play->makeMove(this, this->kings[color], wxPoint(i, i2));
			if (!checkCheck(color))
				flag = false;
		}
	}

	this->play->makeMove(this, this->kings[color], wxPoint(originalLine, originalCol));		// Return king to previous position
	
	
	
	
	
	
	
	
	
	return flag;
}

// TODO: this function should check which pieces (of a certain color) can go to a certain location
std::vector<Piece*> Board::validDestPieces(wxPoint dst, bool color)
{
	std::vector<Piece*> pieces;
	return pieces;
	
}

bool Board::checkLine(unsigned int startPos, unsigned int endPos, bool lineOrCol, bool color)
{
	Piece* piece = nullptr;
	unsigned int i = 0;
	bool flag = false;

	for (i = startPos; i <= endPos; i++)
	{
		lineOrCol ? piece = this->getPiece(this->kings[color]->getLine(), i) : this->getPiece(i, this->kings[color]->getColumn());

		if (piece && piece->getColor() != color && (piece->id == ID::ID_ROOK || piece->id == ID::ID_QUEEN || piece->id == ID::ID_KING))
		{
			this->kings[color]->setCheck(true);
			flag = true;

			// If the other king is in the line, check that it's 1 block away, otherwise it's not a check
			if (piece->id == ID::ID_KING && i != 1)
			{
				flag = false;
			}

			break;
		}
		// If we are colliding with any other piece, we can stop checking because it blocks the king from being checked
		else if (piece)
		{
			break;
		}
	}

	return flag;
}

bool Board::checkDiagonal(wxPoint dst, bool color)
{
	Piece* piece = nullptr;
	bool flag = false;

	unsigned int i = 0;
	unsigned int i2 = 0;

	YDIR yDir;
	XDIR xDir;

	dst.y > this->kings[color]->getLine() ? yDir = YDIR::DOWN : yDir = YDIR::UP;
	dst.x > this->kings[color]->getColumn() ? xDir = XDIR::RIGHT : xDir = XDIR::LEFT;

	yDir == YDIR::DOWN ? i = this->kings[color]->getLine() + 1 : i = this->kings[color]->getLine() - 1;
	xDir == XDIR::RIGHT ? i2 = this->kings[color]->getColumn() + 1 : i2 = this->kings[color]->getColumn() - 1;

	do
	{
		piece = this->getPiece(i, i2);

		if (piece && piece->getColor() != color && (piece->id == ID::ID_BISHOP || piece->id == ID::ID_QUEEN || piece->id == ID::ID_KING))
		{
			// If piece is not a king, then it for sure threatens our king, otherwise if it is a king, check that he is 1 block close to
			// our king
			if (piece->id != ID::ID_KING || 
				((yDir == YDIR::DOWN ? i == this->kings[color]->getLine() + 1 : i == this->kings[color]->getLine() - 1)
					&& (xDir == XDIR::RIGHT ? i2 == this->kings[color]->getColumn() + 1 : i2 == this->kings[color]->getColumn() - 1)))
			{
				this->kings[color]->setCheck(true);
				flag = true;
			}
			else
			{
				flag = false;
			}

			break;
		}
		// For pawns check if they are 1 block away diagonally depending on their color
		else if (piece && piece->getColor() != color && piece->id == ID::ID_PAWN)
		{
			if (!(piece->getColor() ? i == this->kings[color]->getLine() - 1 : i == this->kings[color]->getLine() + 1))
				flag = false;
		}
		// If we are colliding with any other piece, we can stop checking because it blocks the king from being checked
		else if (piece)
		{
			break;
		}

		yDir == YDIR::DOWN ? i++ : i--;
		xDir == XDIR::RIGHT ? i2++ : i2--;

	} while ((yDir == YDIR::DOWN ? i < dst.y : i > dst.y) && (xDir == XDIR::RIGHT ? i2 < dst.x : i2 > dst.x));

	return flag;
}

bool Board::checkHorse(bool color)
{
	Piece* piece = nullptr;
	bool flag = false;

	/* Check all options for a horse threatening the king */

	if ((piece = this->getPiece(this->kings[color]->getLine() + TWO, this->kings[color]->getColumn() + ONE)) && piece->getColor() != color && piece->id == ID::ID_KNIGHT)
		flag = true;

	if ((piece = this->getPiece(this->kings[color]->getLine() - TWO, this->kings[color]->getColumn() - ONE)) && piece->getColor() != color && piece->id == ID::ID_KNIGHT)
		flag = true;

	if ((piece = this->getPiece(this->kings[color]->getLine() - TWO, this->kings[color]->getColumn() + ONE)) && piece->getColor() != color && piece->id == ID::ID_KNIGHT)
		flag = true;

	if ((piece = this->getPiece(this->kings[color]->getLine() + TWO, this->kings[color]->getColumn() - ONE)) && piece->getColor() != color && piece->id == ID::ID_KNIGHT)
		flag = true;

	if ((piece = this->getPiece(this->kings[color]->getLine() + ONE, this->kings[color]->getColumn() + TWO)) && piece->getColor() != color && piece->id == ID::ID_KNIGHT)
		flag = true;

	if ((piece = this->getPiece(this->kings[color]->getLine() - ONE, this->kings[color]->getColumn() - TWO)) && piece->getColor() != color && piece->id == ID::ID_KNIGHT)
		flag = true;

	if ((piece = this->getPiece(this->kings[color]->getLine() - ONE, this->kings[color]->getColumn() + TWO)) && piece->getColor() != color && piece->id == ID::ID_KNIGHT)
		flag = true;

	if ((piece = this->getPiece(this->kings[color]->getLine() + ONE, this->kings[color]->getColumn() - TWO)) && piece->getColor() != color && piece->id == ID::ID_KNIGHT)
		flag = true;

	// If there's at least 1 horse that is threatening the king, it's a check
	if (flag)
		this->kings[color]->setCheck(true);

	return flag;
}


bool Board::kingCheck(bool color) const
{
	return this->kings[color]->isCheck();
}

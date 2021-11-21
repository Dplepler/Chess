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
	return line < BOARD_HEIGHT && line >= 0 && col < BOARD_WIDTH&& col >= 0 ? this->board[line][col] : nullptr;
}

std::vector<Piece*> Board::checkCheck(bool color)
{
	Piece* piece = nullptr;
	std::vector<Piece*> pieces;

	bool flag = false;

	int i = 0;

	// If all the possible checks aren't happening, then the king is not in check
	pieces.push_back(this->checkLine(this->kings[color]->getLine() + 1, BOARD_HEIGHT - 1, LINE, color));	// Check bottom line
	pieces.push_back(this->checkLine(this->kings[color]->getColumn() + 1, BOARD_WIDTH - 1, COL, color));	// Check right line
	pieces.push_back(this->checkLine(0, this->kings[color]->getLine() - 1, LINE, color));					// Check upper line
	pieces.push_back(this->checkLine(0, this->kings[color]->getColumn() - 1, COL, color));					// Check left line
	pieces.push_back(this->checkDiagonal(wxPoint(0, 0), color));											// Left lower corner
	pieces.push_back(this->checkDiagonal(wxPoint(0, BOARD_HEIGHT), color));									// left upper corner
	pieces.push_back(this->checkDiagonal(wxPoint(BOARD_WIDTH, BOARD_HEIGHT), color));						// Right lower corner
	pieces.push_back(this->checkDiagonal(wxPoint(BOARD_WIDTH, 0), color));									// Right upper corner
	this->checkHorse(color, pieces);

	for (i = 0; i < pieces.size(); i++)
	{
		if (!pieces[i])
		{
			pieces.erase(pieces.begin() + i);
			i--;
		}
	}
	
	if (!pieces.size())
		this->kings[color]->setCheck(false);

	return pieces;
}

bool Board::checkMate(bool color)
{
	bool flag = true;

	std::vector<Piece*> pieces;

	int kingLine = this->kings[color]->getLine();
	int kingCol = this->kings[color]->getColumn();

	unsigned int i = 0;
	unsigned int i2 = 0;

	enum class XDIR
	{
		LEFT = 1,
		RIGHT

	} xDir;

	enum class YDIR
	{
		UP = 1,
		DOWN

	} yDir;

	enum class PATH
	{
		DIAGONAL,
		STRAIGHT

	} path;

	pieces = checkCheck(color);

	if (!pieces.size())
		return false;

	for (i = kingLine - 1; i < kingLine - 1 + KING_RANGE && i < BOARD_HEIGHT && flag; i++)
	{
		for (i2 = kingCol - 1; i2 < kingCol - 1 + KING_RANGE && i < BOARD_HEIGHT && flag; i2++)
		{
			// If another piece is blocking the way
			if (!this->play->checkValidDest(this, this->kings[color], wxPoint(i2, i)))
				continue;

			// If king is not in check after move, then there is no checkmate
			if (!this->play->makeMove(this, this->kings[color], wxPoint(i2, i)))
				flag = false;
		}
	}

	// Return king to the first position
	this->updateBoard(kingLine, kingCol, this->kings[color]);
	this->kings[color]->updateCoords(kingLine, kingCol);

	if (!flag)
		return flag;

	int dstLine = pieces[0]->getLine();
	int dstCol = pieces[0]->getColumn();


	// If only one piece is threatening the king and the king cannot escape, check if we can block it, or if we can eat it
	if (pieces.size() == 1)
	{
		if (dstLine > kingLine)
		{
			yDir = YDIR::DOWN;
		}
		else if (dstLine < kingLine)
		{
			yDir = YDIR::UP;
		}

		if (dstCol > kingCol)
		{
			xDir = XDIR::RIGHT;
		}
		else if (dstCol < kingCol)
		{
			xDir = XDIR::LEFT;
		}

		path = kingLine != dstLine && kingCol != dstCol ? PATH::DIAGONAL : PATH::STRAIGHT;
		  
		if (path == PATH::DIAGONAL)
		{
			i = yDir == YDIR::DOWN ? kingLine + 1 : kingLine - 1;
			i2 = xDir == XDIR::RIGHT ? kingCol + 1 : kingCol - 1;

			while ((yDir == YDIR::DOWN ? i <= dstLine : i >= dstLine) && (xDir == XDIR::RIGHT ? i2 <= dstCol : i2 >= dstCol) && flag)
			{
				if (this->validDestPieces(wxPoint(i2, i), color).size() > 0)	// Check if there's a piece that can block the check's way
					flag = false;

				yDir == YDIR::DOWN ? i++ : i--;
				xDir == XDIR::RIGHT ? i2++ : i2--;
			}
		}
		else if (kingLine == dstLine && kingCol != dstCol)
		{
			
			for (i = xDir == XDIR::RIGHT ? kingCol + 1 : dstCol; flag && xDir == XDIR::RIGHT ? i <= dstCol : i < kingCol; i++)
			{
				if (this->validDestPieces(wxPoint(kingCol, i), color).size() > 0)	// Check if there's a piece that can block the check's way
					flag = false;
			}
		}
		else if (kingCol == dstCol && kingLine != dstLine)
		{
			for (i = yDir == YDIR::DOWN ? kingLine + 1 : dstLine; flag && yDir == YDIR::DOWN ? i <= dstLine : i < kingLine; i++)
			{
				if (this->validDestPieces(wxPoint(i, kingLine), color).size() > 0)	// Check if there's a piece that can block the check's way
					flag = false;
			}
		}
		else
		{
			flag = false;
		}	
	}

	
	return flag;
}

// TODO: this function should check which pieces (of a certain color) can go to a certain location
std::vector<Piece*> Board::validDestPieces(wxPoint dst, bool color)
{
	unsigned int i = 0;
	unsigned int i2 = 0;

	std::vector<Piece*> validPieces;

	// Push all pieces that can go to the specified location
	for (i = 0; i < BOARD_HEIGHT; i++)
	{
		for (i2 = 0; i2 < BOARD_WIDTH; i2++)
		{
			if (this->board[i][i2] && this->board[i][i2]->id != ID::ID_KING && this->board[i][i2]->getColor() == color && this->board[i][i2]->checkMove(dst.y, dst.x, this))
			{
				validPieces.push_back(this->board[i][i2]);
			}
		}
	}
	
	return validPieces;
}

Piece* Board::checkLine(unsigned int startPos, unsigned int endPos, bool lineOrCol, bool color)
{
	Piece* piece = nullptr;
	unsigned int i = 0;

	for (i = startPos; i <= endPos; i++)
	{
		piece = lineOrCol ? this->getPiece(i, this->kings[color]->getColumn()) : this->getPiece(this->kings[color]->getLine(), i);

		if (piece && piece->getColor() != color && (piece->id == ID::ID_ROOK || piece->id == ID::ID_QUEEN || piece->id == ID::ID_KING))
		{
			// If the other king is in the line, check that it's 1 block away, otherwise it's not a check
			if (piece->id == ID::ID_KING && abs(i - lineOrCol ? this->kings[color]->getLine() : this->kings[color]->getColumn()))
			{
				piece = nullptr;
			}
			else
			{
				this->kings[color]->setCheck(true);
			}

			break;
		}
		// If we are colliding with any other piece, we can stop checking because it blocks the king from being checked
		else if (piece)
		{
			piece = nullptr;
			break;
		}
	}

	return piece;
}

Piece* Board::checkDiagonal(wxPoint dst, bool color)
{
	Piece* piece = nullptr;

	unsigned int i = 0;
	unsigned int i2 = 0;

	YDIR yDir;
	XDIR xDir;

	yDir = dst.y > this->kings[color]->getLine() ? YDIR::DOWN : YDIR::UP;
	xDir = dst.x > this->kings[color]->getColumn() ? XDIR::RIGHT : XDIR::LEFT;

	i = yDir == YDIR::DOWN ? this->kings[color]->getLine() + 1 : this->kings[color]->getLine() - 1;
	i2 = xDir == XDIR::RIGHT ? this->kings[color]->getColumn() + 1 : this->kings[color]->getColumn() - 1;

	do
	{
		piece = this->getPiece(i, i2);

		if (piece && piece->getColor() != color && (piece->id == ID::ID_BISHOP || piece->id == ID::ID_QUEEN || piece->id == ID::ID_KING))
		{
			// If piece is not a king, then it for sure threatens our king, otherwise if it is a king, check that he is 1 block close to
			// our king
			if (piece->id != ID::ID_KING || 
				((i == (yDir == YDIR::DOWN ? this->kings[color]->getLine() + 1 : this->kings[color]->getLine() - 1))
					&& (i2 == (xDir == XDIR::RIGHT ? this->kings[color]->getColumn() + 1 : this->kings[color]->getColumn() - 1))))
			{
				this->kings[color]->setCheck(true);
			}
			else
			{
				piece = nullptr;
			}

			break;
		}
		// For pawns check if they are 1 block away diagonally depending on their color
		else if (piece && piece->getColor() != color && piece->id == ID::ID_PAWN)
		{
			if (!(piece->getColor() ? i == this->kings[color]->getLine() - 1 : i == this->kings[color]->getLine() + 1))
				piece = nullptr;
		}
		// If we are colliding with any other piece, we can stop checking because it blocks the king from being checked
		else if (piece)
		{
			piece = nullptr;
			break;
		}

		yDir == YDIR::DOWN ? i++ : i--;
		xDir == XDIR::RIGHT ? i2++ : i2--;

	} while ((yDir == YDIR::DOWN ? i < dst.y : i > dst.y) && (xDir == XDIR::RIGHT ? i2 < dst.x : i2 > dst.x));

	return piece;
}

void Board::checkHorse(bool color, std::vector<Piece*>& pieces)
{
	Piece* piece = nullptr;

	/* Check all options for a horse threatening the king */

	if ((piece = this->getPiece(this->kings[color]->getLine() + TWO, this->kings[color]->getColumn() + ONE)) && piece->getColor() != color && piece->id == ID::ID_KNIGHT)
	{
		this->kings[color]->setCheck(true);
		pieces.push_back(piece);
	}
		

	if ((piece = this->getPiece(this->kings[color]->getLine() - TWO, this->kings[color]->getColumn() - ONE)) && piece->getColor() != color && piece->id == ID::ID_KNIGHT)
	{
		this->kings[color]->setCheck(true);
		pieces.push_back(piece);
	}

	if ((piece = this->getPiece(this->kings[color]->getLine() - TWO, this->kings[color]->getColumn() + ONE)) && piece->getColor() != color && piece->id == ID::ID_KNIGHT)
	{
		this->kings[color]->setCheck(true);
		pieces.push_back(piece);
	}

	if ((piece = this->getPiece(this->kings[color]->getLine() + TWO, this->kings[color]->getColumn() - ONE)) && piece->getColor() != color && piece->id == ID::ID_KNIGHT)
	{
		this->kings[color]->setCheck(true);
		pieces.push_back(piece);
	}

	if ((piece = this->getPiece(this->kings[color]->getLine() + ONE, this->kings[color]->getColumn() + TWO)) && piece->getColor() != color && piece->id == ID::ID_KNIGHT)
	{
		this->kings[color]->setCheck(true);
		pieces.push_back(piece);
	}

	if ((piece = this->getPiece(this->kings[color]->getLine() - ONE, this->kings[color]->getColumn() - TWO)) && piece->getColor() != color && piece->id == ID::ID_KNIGHT)
	{
		this->kings[color]->setCheck(true);
		pieces.push_back(piece);
	}

	if ((piece = this->getPiece(this->kings[color]->getLine() - ONE, this->kings[color]->getColumn() + TWO)) && piece->getColor() != color && piece->id == ID::ID_KNIGHT)
	{
		this->kings[color]->setCheck(true);
		pieces.push_back(piece);
	}

	if ((piece = this->getPiece(this->kings[color]->getLine() + ONE, this->kings[color]->getColumn() - TWO)) && piece->getColor() != color && piece->id == ID::ID_KNIGHT)
	{
		this->kings[color]->setCheck(true);
		pieces.push_back(piece);
	}
}


bool Board::kingCheck(bool color) const
{
	return this->kings[color]->isCheck();
}

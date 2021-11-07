#include "king.h"

King::King(int line, int column, bool color, wxBitmap* image) : Piece(line, column, color, image)
{
	this->id = ID::ID_KING;
}

bool King::isCheck()
{
	return this->check;
}

bool King::checkMove(int line, int column, Board* board)
{
	bool flag = false;

	float lineMovement = abs(float(this->line - line));
	float columnMovement = abs(float(this->column - column));

	if (this->line == line && this->column == column)
		return false;

	if (lineMovement <= 1.f && columnMovement <= 1.f)
	{
		flag = true;
	}

	return flag;
}

bool King::checkCheck(Board* board)
{
	Piece* piece = nullptr;

	unsigned int i = 0;
	unsigned int i2 = 0;
	
	this->checkLine(this->line + 1, BOARD_HEIGHT - this->line - 1, this->column, board);	// Check right line
	this->checkLine(this->column + 1, BOARD_HEIGHT - this->column - 1, this->line, board);	// Check right column
	this->checkLine(0, this->line, this->column, board);									// Check left line
	this->checkLine(0, this->column, this->line, board);									// Check left column

	this->checkDiagonal(wxPoint(0, 0), board);												// Left lower corner
	this->checkDiagonal(wxPoint(0, BOARD_WIDTH), board);										// left upper corner
	this->checkDiagonal(wxPoint(BOARD_WIDTH, BOARD_WIDTH), board);							// Right upper corner
	this->checkDiagonal(wxPoint(BOARD_WIDTH, 0), board);										// Right lower corner



}

void King::checkLine(unsigned int startPos, unsigned int endPos, bool lineOrCol, Board* board)
{
	Piece* piece = nullptr;
	unsigned int i = 0;
	
	for (i = startPos; i <= endPos; i++)
	{
		lineOrCol ? piece = board->getPiece(this->line, i) : board->getPiece(i, this->column);

		if (piece && piece->getColor() != this->color && (piece->id == ID::ID_ROOK || piece->id == ID::ID_QUEEN))
		{
			this->check = true;
			break;
		}
		else if (piece && piece->getColor() == this->color)
		{
			break;
		}
	}
}

void King::checkDiagonal(wxPoint dst, Board* board)
{
	Piece* piece = nullptr;

	unsigned int i = 0;
	unsigned int i2 = 0;

	YDIR yDir;
	XDIR xDir;

	dst.y > this->line ? yDir = YDIR::DOWN : yDir = YDIR::UP;
	column > this->column ? xDir = XDIR::RIGHT : xDir = XDIR::LEFT;

	do
	{
		piece = board->getPiece(i, i2);

		if (piece && piece->getColor() != this->color && (piece->id == ID::ID_BISHOP || piece->id == ID::ID_QUEEN))
		{
			this->check = true;
			break;
		}
		else if (piece && piece->getColor() != this->color && piece->id == ID::ID_PAWN)
		{
			if (!(piece->getColor() ? i == this->line - 1 : i == this->line + 1))
				this->check = false;
		}
		else if (piece && piece->getColor() == this->color)
		{
			break;
		}
	
		yDir == YDIR::DOWN ? i++ : i--;
		xDir == XDIR::RIGHT ? i2++ : i2--;

	} while ((yDir == YDIR::DOWN ? i < line : i > line) && (xDir == XDIR::RIGHT ? i2 < column : i2 > column));
}
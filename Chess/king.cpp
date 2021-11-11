#include "king.h"

King::King(int line, int column, bool color, wxBitmap* image) : Piece(line, column, color, image)
{
	this->id = ID::ID_KING;
	this->check = false;
}

bool King::isCheck()
{
	return this->check;
}

void King::setCheck(bool check)
{
	this->check = check;
}

bool King::checkMove(int line, int column, Board* board)
{
	bool flag = false;
	int prevLine = -1;
	int prevColumn = -1;

	float lineMovement = abs(float(this->line - line));
	float columnMovement = abs(float(this->column - column));

	if (this->line == line && this->column == column)
		return false;

	if (lineMovement <= 1.f && columnMovement <= 1.f)
	{
		flag = true;
	}

	prevLine = this->line;
	prevColumn = this->column;

	this->line = line;
	this->column = column;

	// If the king is in check after the move, then it is invalid
	if (board->checkCheck(this->color))
	{
		this->line = prevLine;
		this->column = prevColumn;
		this->check = false;
		flag = false;
	}
	

	return flag;
}


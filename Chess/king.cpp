#include "king.h"

King::King(int line, int column, bool color, wxBitmap* image) : Piece(line, column, color, image)
{
	this->id = ID::ID_KING;
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
#include "king.h"

King::King(unsigned int line, unsigned int column, bool color) : Piece(line, column, color)
{
	this->id = ID::ID_KING;
}

bool King::checkMove(unsigned int line, unsigned int column)
{
	bool flag = false;

	float lineMovement = abs(float(this->line - line));
	float columnMovement = abs(float(this->column - column));

	if (this->line == line && this->column == column)
		return false;

	if (lineMovement > 0 || columnMovement > 0)
	{
		flag = true;
	}
	else
	{
		flag = false;
	}

	return flag;
}
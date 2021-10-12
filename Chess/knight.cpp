#include "knight.h"

Knight::Knight(unsigned int line, unsigned int column, bool color) : Piece(line, column, color)
{
	this->id = ID::ID_KNIGHT;
}

bool Knight::checkMove(unsigned int line, unsigned int column)
{
	bool flag = false;

	float lineMovement = abs(float(this->line - line));
	float columnMovement = abs(float(this->column - column));

	if (this->line == line && this->column == column)
		return false;

	if (lineMovement == TWO && columnMovement == 1.f)
	{
		flag = true;
	}
	else if (columnMovement == TWO && lineMovement == 1.f)
	{
		flag = true;
	}
	else
	{
		flag = false;
	}

	return flag;
}
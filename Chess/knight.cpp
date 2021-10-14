#include "knight.h"
#include "board.h"

Knight::Knight(int line, int column, bool color) : Piece(line, column, color)
{
	this->id = ID::ID_KNIGHT;
}

bool Knight::checkMove(int line, int column, Board* board)
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
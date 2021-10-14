#include "king.h"
#include "board.h"

King::King(int line, int column, bool color) : Piece(line, column, color)
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
#include "queen.h"

Queen::Queen(int line, int column, bool color) : Piece(line, column, color)
{
	this->id = ID::ID_QUEEN;
}

bool Queen::checkMove(int line, int column, Board* board)
{
	bool flag = false;

	if (this->line == line && this->column == column)
		return false;

	// Check for diagonal squares
	if (!(this->line % 2) && !(this->column % 2) || this->line % 2 && this->column % 2)
	{
		if (!(line % 2) && !(column % 2) || line % 2 && column % 2)
			flag = true;
		else
			flag = false;
	}
	else if (!(this->line % 2) && this->column % 2 || this->line % 2 && !(this->column % 2))
	{
		if (!(line % 2) && column % 2 || line % 2 && !(column % 2))
			flag = true;
		else
			flag = false;
	}
	// Check for straight lines
	else if (this->line == line && this->column != column)
	{
		flag = true;
	}
	else if (this->line != line && this->column == column)
	{
		flag = true;
	}


	return flag;
}
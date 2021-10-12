#include "rook.h"

Rook::Rook(int line, int column, bool color) : Piece(line, column, color)
{
	this->id = ID::ID_ROOK;
}

bool Rook::checkMove(int line, int column, Board* board)
{
	bool flag = false;

	// Check for straight lines
	if (this->line == line && this->column != column)
	{
		flag = true;
	}
	else if (this->line != line && this->column == column)
	{
		flag = true;
	}

	return flag;
}
#include "rook.h"

Rook::Rook(unsigned int line, unsigned int column, bool color) : Piece(line, column, color)
{
	this->id = ID::ID_ROOK;
}

bool Rook::checkMove(unsigned int line, unsigned int column)
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
#include "bishop.h"

Bishop::Bishop(unsigned int line, unsigned int column, bool color) : Piece(line, column, color)
{
	this->id = ID::ID_BISHOP;

}


bool Bishop::checkMove(unsigned int line, unsigned int column)
{
	bool flag = false;
	
	// If the piece didn't move; for Bishop if one of the params didn't change we already know it didn't move
	if (this->line == line || this->column == column)
		return false;

	// Check for diagonal squares
	if (!(this->line % 2) && !(this->column % 2) || this->line % 2 && this->column % 2)
	{
		if (!(line % 2) && !(column % 2) || line % 2 && column % 2)
			flag = true;
		else
			flag = false;
	}
	else
	{
		if (!(line % 2) && column % 2 || line % 2 && !(column % 2))
			flag = true;
		else
			flag = false;
	}

	return flag;
}


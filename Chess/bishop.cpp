#include "bishop.h"

Bishop::Bishop(int line, int column, bool color) : Piece(line, column, color)
{
	this->id = ID::ID_BISHOP;

}

bool Bishop::checkMove(int line, int column, Board* board)
{
	unsigned int i = 0;
	unsigned int i2 = 0;
	bool flag = false;

	enum class XDIR
	{
		LEFT,
		RIGHT

	} xDir;

	enum class YDIR
	{
		UP,
		DOWN

	} yDir;
	
	// If the piece didn't move; for Bishop if one of the params didn't change we already know it didn't move
	if (this->line == line || this->column == column)
		return false;

	// Check for diagonal squares
	if (!(this->line % 2) && !(this->column % 2) || this->line % 2 && this->column % 2)
	{
		if (!(line % 2) && !(column % 2) || line % 2 && column % 2)
		{
			line > this->line ? yDir = YDIR::DOWN : yDir = YDIR::UP;
			column > this->column ? xDir = XDIR::RIGHT : xDir = XDIR::LEFT;
			flag = true;
		}
		else
		{
			flag = false;
		}
			
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


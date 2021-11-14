#include "bishop.h"

Bishop::Bishop(int line, int column, bool color, wxBitmap* image) : Piece(line, column, color, image)
{
	this->id = ID::ID_BISHOP;

}

bool Bishop::checkMove(int line, int column, Board* board)
{
	unsigned int i = 0;
	unsigned int i2 = 0;
	bool flag = true;

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

	line > this->line ? yDir = YDIR::DOWN : yDir = YDIR::UP;
	column > this->column ? xDir = XDIR::RIGHT : xDir = XDIR::LEFT;

	yDir == YDIR::DOWN ? i = this->line + 1 : i = this->line - 1;
	xDir == XDIR::RIGHT ? i2 = this->column + 1 : i2 = this->column - 1;

	while ((yDir == YDIR::DOWN ? i < line : i > line) && (xDir == XDIR::RIGHT ? i2 < column : i2 > column) && flag)
	{
		if (board->getBoard()[i][i2])
		{
			flag = false;
		}

		yDir == YDIR::DOWN ? i++ : i--;
		xDir == XDIR::RIGHT ? i2++ : i2--;

	} 

	if (i != line || i2 != column)
		flag = false;



	return flag;
}


#include "queen.h"

Queen::Queen(int line, int column, bool color, wxBitmap* image) : Piece(line, column, color, image)
{
	this->id = ID::ID_QUEEN;
}

bool Queen::checkMove(int line, int column, Board* board)
{
	unsigned int i = 0;
	unsigned int i2 = 0;
	bool flag = true;

	enum class XDIR
	{
		LEFT = 1,
		RIGHT

	} xDir;

	enum class YDIR
	{
		UP = 1,
		DOWN

	} yDir;

	enum class PATH
	{
		DIAGONAL,
		STRAIGHT

	} path;

	// If the piece didn't move
	if (this->line == line && this->column == column)
		return false;

	if (line > this->line)
	{
		yDir = YDIR::DOWN;
	}
	else if (line < this->line)
	{
		yDir = YDIR::UP;
	}

	if (column > this->column)
	{
		xDir = XDIR::RIGHT;
	}
	else if (column < this->column)
	{
		xDir = XDIR::LEFT;
	}
	 

	this->line != line && this->column != column ? path = PATH::DIAGONAL : path = PATH::STRAIGHT;


	if (path == PATH::DIAGONAL)
	{
		yDir == YDIR::DOWN ? i = this->line + 1 : i = this->line - 1;
		xDir == XDIR::RIGHT ? i2 = this->column + 1 : i2 = this->column - 1;

		while ((yDir == YDIR::DOWN ? i < line : i > line) && (xDir == XDIR::RIGHT ? i2 < column : i2 > column) && flag)
		{
			if (board->getBoard()[i][i2]) {
				flag = false;
			}

			yDir == YDIR::DOWN ? i++ : i--;
			xDir == XDIR::RIGHT ? i2++ : i2--;

		}
		
		if (i != line || i2 != column)
			flag = false;
	
	
	}
	else if (this->line == line && this->column != column)
	{

		for (xDir == XDIR::RIGHT ? i = this->column + 1 : i = column + 1; flag && xDir == XDIR::RIGHT ? i < column : i < this->column; i++)
		{
			if (board->getBoard()[line][i])
			{
				flag = false;
			}
		}
	}
	else if (this->column == column && this->line != line)
	{
		for (yDir == YDIR::DOWN ? i = this->line + 1 : i = line + 1; flag && yDir == YDIR::DOWN ? i < line : i < this->line; i++)
		{
			if (board->getBoard()[i][column]) {
				flag = false;
			}
		}	
	}
	else
	{
		flag = false;
	}

	return flag;
}
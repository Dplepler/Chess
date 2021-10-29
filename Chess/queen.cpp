#include "queen.h"

Queen::Queen(int line, int column, bool color, wxBitmap image) : Piece(line, column, color, image)
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
		yDir == YDIR::DOWN ? i = line - 1 : i = this->line - 1;
		xDir == XDIR::RIGHT ? i2 = column - 1 : i2 = this->column - 1;

		do
		{
			if (board->board[i][i2])
			{
				flag = false;
			}

			i--;
			i2--;

		} while ((yDir == YDIR::DOWN ? i > this->line : i > line) && (xDir == XDIR::RIGHT ? i2 > this->column : i2 > column) && flag);
		
		if (yDir == YDIR::DOWN ? i != this->line : i != line && xDir == XDIR::RIGHT ? i2 != this->column : i2 != column && flag)
		{
			std::cout << "Illegal move, the Queen can't move like that\n";

			flag = false;
		}
		else if (!flag)
		{
			std::cout << "Another piece is blocking the way\n";
		}
	
	
	}
	else if (this->line == line && this->column != column)
	{

		for (xDir == XDIR::RIGHT ? i = this->column + 1 : i = column + 1; flag && xDir == XDIR::RIGHT ? i < column : i < this->column; i++)
		{
			if (board->board[line][i])
			{
				flag = false;
			}
		}

		if (!flag)
			std::cout << "Another piece is blocking the way\n";

	}
	else if (this->column == column && this->line != line)
	{
		for (yDir == YDIR::DOWN ? i = this->line + 1 : i = line + 1; flag && yDir == YDIR::DOWN ? i < line : i < this->line; i++)
		{
			if (board->board[i][column])
			{
				flag = false;
			}
		}

		if (!flag)
			std::cout << "Another piece is blocking the way\n";
		
	}
	else
	{
		std::cout << "Illegal move, the Queen can't move like that";
	}


	return flag;
}
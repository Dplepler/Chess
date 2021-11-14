#include "rook.h"

Rook::Rook(int line, int column, bool color, wxBitmap* image) : Piece(line, column, color, image)
{
	this->id = ID::ID_ROOK;
}

bool Rook::checkMove(int line, int column, Board* board)
{
	unsigned int i = 0;
	bool flag = true;

	if (this->line == line && this->column != column)
	{

		for (this->column > column ? i = this->column + 1 : i = column + 1; flag && this->column > column ? i < column : i < this->column; i++)
		{
			if (board->getBoard()[line][i])
			{
				flag = false;
			}
		}

		if (this->column > column ? i == column : i == line)
			flag = false;


	}
	else if (this->column == column && this->line != line)
	{
		for (line > this->line ? i = this->line + 1 : i = line + 1; flag && line > this->line ? i < line : i < this->line; i++)
		{
			if (board->getBoard()[i][column])
			{
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
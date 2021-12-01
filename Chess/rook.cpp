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

		for (i = this->column > column ? this->column + 1 : column + 1; flag && i < (this->column > column) ?  column : this->column; i++)
		{
			flag = !board->getBoard()[line][i];
		}

		if (i == (this->column > column) ? column : line) {
			flag = false;
		}
	}
	else if (this->column == column && this->line != line)
	{
		for (i = line > this->line ? this->line + 1 : line + 1; flag && i < (line > this->line) ? line : this->line; i++)
		{
			flag = !board->getBoard()[i][column];
		}

	}
	else
	{
		flag = false;
	}

	return flag;
}
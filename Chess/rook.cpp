#include "rook.h"

#include "board.h"

Rook::Rook(int line, int column, bool color) : Piece(line, column, color)
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
		for (this->line > line ? i = this->line + 1 : i = line + 1; flag && this->line > line ? i < line : i < this->line; i++)
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
		std::cout << "Illegal move, the Rook can't move like that";
	}

	return flag;
}
#include "knight.h"

Knight::Knight(unsigned int line, unsigned int column, bool color) : Piece(line, column, color)
{
	this->id = ID::ID_KNIGHT;
}

bool Knight::checkMove(unsigned int line, unsigned int column)
{

	return true;
}
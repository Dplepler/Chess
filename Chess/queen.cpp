#include "queen.h"

Queen::Queen(unsigned int line, unsigned int column, bool color) : Piece(line, column, color)
{
	this->id = ID::ID_QUEEN;
}

bool Queen::checkMove(unsigned int line, unsigned int column)
{

	return true;
}
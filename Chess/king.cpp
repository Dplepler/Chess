#include "king.h"

King::King(unsigned int line, unsigned int column, bool color) : Piece(line, column, color)
{
	this->id = ID::ID_KING;
}

bool King::checkMove(unsigned int line, unsigned int column)
{

	return true;
}
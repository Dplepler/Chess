#include "king.h"

King::King(Line line, Column column) : Piece(line, column)
{
	this->id = ID::ID_KING;
}

bool King::checkMove(Line line, Column column)
{

	return true;
}
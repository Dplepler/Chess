#include "knight.h"

Knight::Knight(Line line, Column column) : Piece(line, column)
{
	this->id = ID::ID_KNIGHT;
}

bool Knight::checkMove(Line line, Column column)
{

	return true;
}
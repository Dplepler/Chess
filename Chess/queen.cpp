#include "queen.h"

Queen::Queen(Line line, Column column) : Piece(line, column)
{
	this->id = ID::ID_QUEEN;
}

bool Queen::checkMove(Line line, Column column)
{

	return true;
}
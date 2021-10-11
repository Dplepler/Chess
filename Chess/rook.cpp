#include "rook.h"

Rook::Rook(Line line, Column column) : Piece(line, column)
{
	this->id = ID::ID_ROOK;
}

bool Rook::checkMove(Line line, Column column)
{
	return true;
}
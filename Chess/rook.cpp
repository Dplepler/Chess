#include "rook.h"

Rook::Rook(unsigned int line, unsigned int column, bool color) : Piece(line, column, color)
{
	this->id = ID::ID_ROOK;
}

bool Rook::checkMove(unsigned int line, unsigned int column)
{
	return true;
}
#include "pawn.h"

Pawn::Pawn(unsigned int line, unsigned int column, bool color) : Piece(line, column, color)
{
	this->id = ID::ID_PAWN;
}

bool Pawn::checkMove(unsigned int line, unsigned int column)
{

	return true;
}
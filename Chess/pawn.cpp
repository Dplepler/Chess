#include "pawn.h"

Pawn::Pawn(Line line, Column column) : Piece(line, column)
{
	this->id = ID_PAWN;
}

bool Pawn::checkMove(Line line, Column column)
{


}
#include "pawn.h"

Pawn::Pawn(unsigned int line, unsigned int column, bool color) : Piece(line, column, color)
{
	this->id = ID::ID_PAWN;
}

bool Pawn::checkMove(unsigned int line, unsigned int column)
{
	bool flag = false;

	// Here we don't want to use the abs function as pawns can only move forward
	unsigned int lineMovement = line - this->line;
	unsigned int columnMovement = column - this->column;

	// For movements that skip two lines,
	if (lineMovement == TWO)
	{
		if (!columnMovement)
			flag = true;
		else
			flag = false;
	}
	else if (lineMovement == 1)
	{
		// If there was no horizontal movement or it was just one square, then we are okay
		if (columnMovement == 1 || !columnMovement)
		{
			flag = true;
		}
		// Otherwise it is an illegal move
		else
		{
			flag = false;
		}

	}
	

	return flag;
}
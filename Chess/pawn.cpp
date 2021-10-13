#include "pawn.h"

#include "board.h"

Pawn::Pawn(int line, int column, bool color) : Piece(line, column, color)
{
	this->id = ID::ID_PAWN;
}

bool Pawn::checkMove(int line, int column, Board* board)
{
	bool flag = false;
	int lineMovement = 0;
	int columnMovement = 0;

	// Here we don't want to use the abs function as pawns can only move forward
	if (this->color == WHITE)
	{
		lineMovement = line - this->line;
		columnMovement = column - this->column;
	}
	else
	{
		lineMovement = this->line - line;
		columnMovement = this->column - column;
	}

	// For movements that skip two lines, check that the pawn has not moved yet, and also check that the player doesn't try
	// to move to the sides
	if (lineMovement == TWO && !columnMovement)
	{
		if ((this->color == WHITE && this->line == WHITE_PAWN_POS && board->board[line + 1][column]) || this->color == BLACK && this->line == BLACK_PAWN_POS && board->board[line - 1][column])
		{
			flag = true;
		}
	
	}
	// If there was no horizontal movement or it was just one square, then we are okay
	else if (lineMovement == 1 && (columnMovement == 1 || !columnMovement))
	{
			flag = true;
	}
	

	return flag;
}
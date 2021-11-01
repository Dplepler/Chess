#include "pawn.h"

Pawn::Pawn(int line, int column, bool color, wxBitmap* image) : Piece(line, column, color, image)
{
	this->id = ID::ID_PAWN;
}

bool Pawn::checkMove(int line, int column, Board* board)
{
	bool flag = false;
	int lineMovement = 0;
	float columnMovement = 0.f;

	// Here we don't want to use the abs function as pawns can only move forward
	if (this->color == WHITE)
	{
		lineMovement = line - this->line;
	}
	else
	{
		lineMovement = this->line - line;
	}

	columnMovement = abs(float(column - this->column));

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
	else if (lineMovement == 1 && !columnMovement)
	{
			flag = true;
	}
	else if (lineMovement == 1 && columnMovement == 1.f)
	{

		if (board->board[line][column])
			flag = true;
		else
			std::cout << "Pawn can only move diagonally when it's eating another piece\n";

	}

	return flag;
}
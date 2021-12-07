#include "knight.h"

Knight::Knight(int line, int column, bool color, wxBitmap* image) : Piece(line, column, color, image)
{
	this->id = ID::ID_KNIGHT;
}

bool Knight::checkMove(int line, int column, Board* board)
{
	bool flag = false;

	float lineMovement = abs(float(this->line - line));
	float columnMovement = abs(float(this->column - column));

	if (this->line == line && this->column == column) {
		return false;
	}
		
	flag = movedTwoBlocks(lineMovement) && movedOneBlock(columnMovement);

	if (!flag) {
		flag = movedTwoBlocks(columnMovement) && movedOneBlock(lineMovement);
	}

	return flag;
}
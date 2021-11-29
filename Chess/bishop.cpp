#include "bishop.h"

Bishop::Bishop(int line, int column, bool color, wxBitmap* image) : Piece(line, column, color, image)
{
	this->id = ID::ID_BISHOP;
}

bool Bishop::checkMove(int line, int column, Board* board)
{
	enum class XDIR
	{
		LEFT,
		RIGHT

	} xDir;

	enum class YDIR
	{
		UP,
		DOWN

	} yDir;
	
	// If the piece didn't move; for Bishop if one of the params didn't change we already know it didn't move
	if (this->line == line || this->column == column) {
		return false;
	}
		
	yDir = (line > this->line) ? YDIR::DOWN : YDIR::UP;
	xDir = (column > this->column) ? XDIR::RIGHT : XDIR::LEFT;

	unsigned int i = 0;
	unsigned int i2 = 0;

	yDir == YDIR::DOWN ? i = this->line + 1 : i = this->line - 1;
	xDir == XDIR::RIGHT ? i2 = this->column + 1 : i2 = this->column - 1;

	while ((yDir == YDIR::DOWN ? i < line : i > line) && (xDir == XDIR::RIGHT ? i2 < column : i2 > column))
	{
		if (board->getBoard()[i][i2]) {
			break;
		}

		yDir == YDIR::DOWN ? i++ : i--;
		xDir == XDIR::RIGHT ? i2++ : i2--;

	} 

	return !(i != line || i2 != column);
}


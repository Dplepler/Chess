#include "king.h"

King::King(int line, int column, bool color, wxBitmap* image) : Piece(line, column, color, image)
{
	this->id = ID::ID_KING;
}

bool King::isCheck()
{
	return this->check;
}

bool King::checkMove(int line, int column, Board* board)
{
	bool flag = false;

	float lineMovement = abs(float(this->line - line));
	float columnMovement = abs(float(this->column - column));

	if (this->line == line && this->column == column)
		return false;

	if (lineMovement <= 1.f && columnMovement <= 1.f)
	{
		flag = true;
	}

	return flag;
}

bool King::checkCheck(Board* board)
{
	Piece* piece = nullptr;

	unsigned int i = 0;
	unsigned int i2 = 0;
	
	this->checkLine(this->line + 1, BOARD_HEIGHT - this->line - 1, this->column, board);
	this->checkLine(this->column + 1, BOARD_HEIGHT - this->column - 1, this->line, board);
	this->checkLine(0, this->line, this->column, board);
	this->checkLine(0, this->column, this->line, board);

	


}

void King::checkLine(unsigned int startPos, unsigned int endPos, unsigned int staticPos, Board* board)
{
	Piece* piece = nullptr;
	unsigned int i = 0;
	
	for (i = startPos; i <= endPos; i++)
	{
		piece = board->getPiece(i, staticPos);

		if (piece->id == ID::ID_ROOK || piece->id == ID::ID_QUEEN)
		{
			this->check = true;
		}
	}
}
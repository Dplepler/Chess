#include "bishop.h"

Bishop::Bishop(unsigned int line, unsigned int column, bool color) : Piece(line, column, color)
{
	this->id = ID::ID_BISHOP;

}


bool Bishop::checkMove(unsigned int line, unsigned int column)
{
	//if (!(this->line % 2) && !(this->column % 2) && !(line % 2) && !(column % 2))
}


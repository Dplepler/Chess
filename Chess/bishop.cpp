#include "bishop.h"

Bishop::Bishop(Line line, Column column) : Piece(line, column)
{
	this->id = ID::ID_BISHOP;

}


bool Bishop::checkMove(Line line, Column column)
{

	return true;
}


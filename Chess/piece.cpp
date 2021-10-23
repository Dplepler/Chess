#include "piece.h"

#include "pawn.h"
#include "rook.h"
#include "knight.h"
#include "bishop.h"
#include "queen.h"
#include "king.h"

Piece::Piece(int line, int column, bool color, wxBitmap image)
{
	this->line = line;
	this->column = column;

	this->id = ID::ID_EMPTY;
	this->color = color;

	this->image = image;

}

void Piece::updateCoords(int line, int column)
{
	this->line = line;
	this->column = column;
}

const char* Piece::idToString(ID id)
{
	switch (id)
	{

	case ID::ID_BISHOP: return "Bishop";
	case ID::ID_KING: return "King";
	case ID::ID_KNIGHT: return "Knight";
	case ID::ID_PAWN: return "Pawn";
	case ID::ID_QUEEN: return "Queen";
	case ID::ID_ROOK: return "Rook";
	case ID::ID_EMPTY: return "Empty";

	}
}
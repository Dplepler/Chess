#include "piece.h"

Piece::Piece(int line, int column, bool color, wxBitmap* image) 
	: line(line), column(column), id(ID::ID_EMPTY), color(color), image(image) { }

int Piece::getLine() const
{
	return this->line;
}

int Piece::getColumn() const
{
	return this->column;
}

wxBitmap* Piece::getImage() const
{
	return this->image;
}

bool Piece::getColor() const
{
	return this->color;
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
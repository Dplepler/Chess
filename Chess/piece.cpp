#include "piece.h"

#include "pawn.h"
#include "rook.h"
#include "knight.h"
#include "bishop.h"
#include "queen.h"
#include "king.h"

Piece::Piece(Line line, Column column)
{
	this->line = line;
	this->column = column;

}

Line Piece::intToLine(unsigned int line)
{
	switch (line)
	{

	case 0: return Line::LINE_1;
	case 1: return Line::LINE_2;
	case 2: return Line::LINE_3;
	case 3: return Line::LINE_4;
	case 4: return Line::LINE_5;
	case 5: return Line::LINE_6;
	case 6: return Line::LINE_7;
	case 7: return Line::LINE_8;

	}
}

Column Piece::intToColumn(unsigned int column)
{
	switch (column)
	{

	case 0: return Column::COL_A;
	case 1: return Column::COL_B;
	case 2: return Column::COL_C;
	case 3: return Column::COL_D;
	case 4: return Column::COL_E;
	case 5: return Column::COL_F;
	case 6: return Column::COL_G;
	case 7: return Column::COL_H;

	}
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
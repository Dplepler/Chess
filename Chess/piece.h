#ifndef PIECE_CLASS_H
#define PIECE_CLASS_H

#include "pawn.h"
#include "rook.h"
#include "knight.h"
#include "bishop.h"
#include "queen.h"
#include "king.h"

enum class Line
{
	LINE_1,
	LINE_2,
	LINE_3,
	LINE_4,
	LINE_5,
	LINE_6,
	LINE_7,
	LINE_8

};

enum class Column
{
	COL_A,
	COL_B,
	COL_C,
	COL_D,
	COL_E,
	COL_F,
	COL_G,
	COL_H

};


class Piece
{

public:

	

	enum id_T
	{
		ID_PAWN,
		ID_ROOK,
		ID_KNIGHT,
		ID_BISHOP,
		ID_QUEEN,
		ID_KING,
		ID_EMPTY

	} id;


	Piece(Line line, Column column);
	virtual bool checkMove(Line line, Column column) = 0;
	
protected:

	Line line;
	Column column;



};




#endif
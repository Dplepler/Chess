#ifndef PIECE_CLASS_H
#define PIECE_CLASS_H

#include <vector>

class Rook;
class Queen;
class King;
class Knight;
class Bishop;
class Pawn;

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

	

	enum class ID
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

	static const char* idToString(ID id);
	static Line intToLine(unsigned int line);
	static Column intToColumn(unsigned int column);
	virtual bool checkMove(Line line, Column column) = 0;
	
protected:

	Line line;
	Column column;

private:

	

};




#endif
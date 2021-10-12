#ifndef PIECE_CLASS_H
#define PIECE_CLASS_H

#include <vector>
#include <cmath>

#define WHITE 0
#define BLACK 1
#define TWO 2.f

class Board;
class Rook;
class Queen;
class King;
class Knight;
class Bishop;
class Pawn;


class Piece
{

public:

	int line;
	int column;
	bool color;

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


	Piece(int line, int column, bool color);

	void updateCoords(int line, int column);
	static const char* idToString(ID id);
	virtual bool checkMove(int line, int column, Board* board) = 0;	

};




#endif
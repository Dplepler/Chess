#ifndef PIECE_CLASS_H
#define PIECE_CLASS_H

#include <vector>

class Rook;
class Queen;
class King;
class Knight;
class Bishop;
class Pawn;


class Piece
{

public:

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


	Piece(unsigned int line, unsigned int column, bool color);

	static const char* idToString(ID id);
	virtual bool checkMove(unsigned int line, unsigned int column) = 0;
	
protected:

	unsigned int line;
	unsigned int column;

private:

	

};




#endif
#ifndef PAWN_CLASS_H
#define PAWN_CLASS_H

#include "piece.h"

#define BLACK_PAWN_POS 6
#define WHITE_PAWN_POS 1

class Piece;

class Pawn : public Piece
{

public:
	// C'tor
	Pawn(int line, int column, bool color);


private:

	virtual bool checkMove(int line, int column, Board* board);


};


#endif
#ifndef PAWN_CLASS_H
#define PAWN_CLASS_H

#include "piece.h"

class Piece;

class Pawn : public Piece
{

public:
	// C'tor
	Pawn(unsigned int line, unsigned int column, bool color);


private:

	virtual bool checkMove(unsigned int line, unsigned int column);


};


#endif
#ifndef PAWN_CLASS_H
#define PAWN_CLASS_H

#include "piece.h"

class Piece;

class Pawn : public Piece
{

public:
	// C'tor
	Pawn(Line line, Column column);


private:

	virtual bool checkMove(Line line, Column column);


};


#endif
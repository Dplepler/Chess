#ifndef ROOK_CLASS_H
#define ROOK_CLASS_H

#include "piece.h"

class Piece;

class Rook : public Piece
{

public:
	// C'tor
	Rook(Line line, Column column);


private:

	virtual bool checkMove(Line line, Column column);


};


#endif
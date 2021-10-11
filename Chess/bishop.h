#ifndef BISHOP_CLASS_H
#define BISHOP_CLASS_H

#include "piece.h"

class Piece;

class Bishop: public Piece
{

public:
	// C'tor
	Bishop(Line line, Column column);


private:

	virtual bool checkMove(Line line, Column column);


};


#endif
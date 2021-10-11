#ifndef BISHOP_CLASS_H
#define BISHOP_CLASS_H

#include "piece.h"

class Piece;

class Bishop: public Piece
{

public:
	// C'tor
	Bishop(unsigned int line, unsigned int column, bool color);


private:

	virtual bool checkMove(unsigned int line, unsigned int column);


};


#endif
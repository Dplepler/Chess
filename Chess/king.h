#ifndef KING_CLASS_H
#define KING_CLASS_H

#include "piece.h"

class Piece;

class King : public Piece
{

public:
	// C'tor
	King(unsigned int line, unsigned int column, bool color);


private:

	virtual bool checkMove(unsigned int line, unsigned int column);


};


#endif
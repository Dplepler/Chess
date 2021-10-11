#ifndef ROOK_CLASS_H
#define ROOK_CLASS_H

#include "piece.h"

class Piece;

class Rook : public Piece
{

public:
	// C'tor
	Rook(unsigned int line, unsigned int column, bool color);


private:

	virtual bool checkMove(unsigned int line, unsigned int column);


};


#endif
#ifndef KNIGHT_CLASS_H
#define KNIGHT_CLASS_H

#include "piece.h"

class Piece;

class Knight : public Piece
{

public:
	// C'tor
	Knight(unsigned int line, unsigned int column, bool color);


private:

	virtual bool checkMove(unsigned int line, unsigned int column);


};


#endif
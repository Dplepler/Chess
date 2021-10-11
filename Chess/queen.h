#ifndef QUEEN_CLASS_H
#define QUEEN_CLASS_H

#include "piece.h"

class Piece;

class Queen : public Piece
{

public:
	// C'tor
	Queen(unsigned int line, unsigned int column, bool color);


private:

	virtual bool checkMove(unsigned int line, unsigned int column);


};


#endif
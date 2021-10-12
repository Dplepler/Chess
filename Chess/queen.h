#ifndef QUEEN_CLASS_H
#define QUEEN_CLASS_H

#include "piece.h"

class Piece;

class Queen : public Piece
{

public:
	// C'tor
	Queen(int line, int column, bool color);


private:

	virtual bool checkMove(int line, int column, Board* board);


};


#endif
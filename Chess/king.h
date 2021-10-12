#ifndef KING_CLASS_H
#define KING_CLASS_H

#include "piece.h"

class Piece;

class King : public Piece
{

public:
	// C'tor
	King(int line, int column, bool color);


private:

	virtual bool checkMove(int line, int column, Board* board);


};


#endif
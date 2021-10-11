#ifndef KING_CLASS_H
#define KING_CLASS_H

#include "piece.h"

class Piece;

class King : public Piece
{

public:
	// C'tor
	King(Line line, Column column);


private:

	virtual bool checkMove(Line line, Column column);


};


#endif
#ifndef KNIGHT_CLASS_H
#define KNIGHT_CLASS_H

#include "piece.h"

class Knight : public Piece
{

public:
	// C'tor
	Knight(Line line, Column column);


private:

	virtual bool checkMove(Line line, Column column);


};


#endif
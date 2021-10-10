#ifndef QUEEN_CLASS_H
#define QUEEN_CLASS_H

#include "piece.h"

class Queen : public Piece
{

public:
	// C'tor
	Queen(Line line, Column column);


private:

	virtual bool checkMove(Line line, Column column);


};


#endif
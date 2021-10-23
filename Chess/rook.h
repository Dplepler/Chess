#ifndef ROOK_CLASS_H
#define ROOK_CLASS_H

#include "piece.h"

class Piece;

class Rook : public Piece
{

public:
	// C'tor
	Rook(int line, int column, bool color, wxBitmap image);


private:

	virtual bool checkMove(int line, int column, Board* board);


};


#endif
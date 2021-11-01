#ifndef KING_CLASS_H
#define KING_CLASS_H

#include "piece.h"

class Piece;
class Board;

class King : public Piece
{

public:
	// C'tor
	King(int line, int column, bool color, wxBitmap* image);


private:

	virtual bool checkMove(int line, int column, Board* board);


};


#endif
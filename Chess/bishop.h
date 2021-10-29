#ifndef BISHOP_CLASS_H
#define BISHOP_CLASS_H

#include "piece.h"

class Piece;
class Board;

class Bishop: public Piece
{

public:
	// C'tor
	Bishop(int line, int column, bool color, wxBitmap image);


private:

	virtual bool checkMove(int line, int column, Board* board);


};


#endif
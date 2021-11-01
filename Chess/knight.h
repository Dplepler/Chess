#ifndef KNIGHT_CLASS_H
#define KNIGHT_CLASS_H

#include "piece.h"

class Piece;
class Board;

class Knight : public Piece
{

public:
	// C'tor
	Knight(int line, int column, bool color, wxBitmap* image);


private:

	virtual bool checkMove(int line, int column, Board* board);


};


#endif
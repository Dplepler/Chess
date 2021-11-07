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
	
	bool isCheck();
	bool checkCheck(Board* board);
	void checkLine(unsigned int startPos, unsigned int endPos, unsigned int staticPos, Board* board);

	
private:

	bool check;
	virtual bool checkMove(int line, int column, Board* board);


};


#endif
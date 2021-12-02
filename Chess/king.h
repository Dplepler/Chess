#ifndef KING_CLASS_H
#define KING_CLASS_H

#include "piece.h"

#define TWO_BLOCKS 2
#define ONE_BLOCK 1

class Piece;
class Board;

enum class XDIR
{
	LEFT,
	RIGHT

};

enum class YDIR
{
	UP,
	DOWN

};

class King : public Piece
{

public:
	// C'tor
	King(int line, int column, bool color, wxBitmap* image);
	
	bool isCheck();
	void setCheck(bool check);
	
private:

	bool check;
	virtual bool checkMove(int line, int column, Board* board);


};


#endif
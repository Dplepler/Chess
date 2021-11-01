#ifndef PIECE_CLASS_H
#define PIECE_CLASS_H

#include <vector>
#include <cmath>

#include "wx/wx.h"
#include "board.h"

#define WHITE 0
#define BLACK 1
#define TWO 2.f

class Board;
class Rook;
class Knight;
class Bishop;
class Queen;
class King;
class Pawn;



class Piece
{

public:

	int line;
	int column;
	bool color;

	wxBitmap* image;

	enum class ID
	{
		ID_PAWN,
		ID_ROOK,
		ID_KNIGHT,
		ID_BISHOP,
		ID_QUEEN,
		ID_KING,
		ID_EMPTY

	} id;


	Piece(int line, int column, bool color, wxBitmap* image);

	void updateCoords(int line, int column);
	static const char* idToString(ID id);
	virtual bool checkMove(int line, int column, Board* board) = 0;	

};




#endif
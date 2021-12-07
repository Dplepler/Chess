#ifndef PIECE_CLASS_H
#define PIECE_CLASS_H

#include <vector>
#include <cmath>

#include "wx/wx.h"
#include "board.h"
#include "PieceIDs.h"

#define WHITE 0
#define BLACK 1

auto movedOneBlock = [](double movement) { return movement == 1.f; };
auto movedTwoBlocks = [](double movement) { return movement == 2.f; };

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

	ID id;

	Piece(int line, int column, bool color, wxBitmap* image);
	virtual ~Piece() = default;

	int getLine() const;
	int getColumn() const;
	bool getColor() const;
	wxBitmap* getImage() const;

	void updateCoords(int line, int column);
	static const char* idToString(ID id);
	virtual bool checkMove(int line, int col, Board* board) = 0;	

protected:

	int line;
	int column;
	bool color;

	wxBitmap* image;

};




#endif
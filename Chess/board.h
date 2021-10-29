#ifndef BOARD_CLASS_H
#define BOARD_CLASS_H

#include <iostream>
#include <string>
#include "wx/wx.h"

class Rook;
class Queen;
class King;
class Knight;
class Bishop;
class Pawn;
class Piece;

#define BOARD_HEIGHT 8
#define BOARD_WIDTH 8

#define PIECES 32

#define TWICE 2

class Board
{

public:

	// C'tor
	Board();
	void updateBoard(int line, unsigned int col, Piece* piece);
	Piece* getPiece(int line, unsigned int col);
	std::vector<std::vector<Piece*>> board;
	

};





#endif
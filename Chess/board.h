#ifndef BOARD_CLASS_H
#define BOARD_CLASS_H

#include <iostream>
#include "pawn.h"
#include "rook.h"
#include "knight.h"
#include "bishop.h"
#include "queen.h"
#include "king.h"
#include "piece.h"

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
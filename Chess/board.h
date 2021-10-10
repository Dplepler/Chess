#ifndef BOARD_CLASS_H
#define BOARD_CLASS_H

#include "piece.h"

#define BOARD_HEIGHT 8
#define BOARD_WIDTH 8

#define TWICE 2

class Board
{

public:

	// C'tor
	Board();

private:

	Piece** board;


	void updateBoard(Piece* srcPiece, Piece* dstPiece);
	

};





#endif
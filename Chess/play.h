#ifndef PLAY_CLASS_H
#define PLAY_CLASS_H

#include "board.h"
#include "piece.h"
#include <iostream>

#define SELECT 0
#define MOVE 1

class Board;
class Piece;

class Play
{

public:

	Play();
	bool turn;
	bool selectOrMove;
	bool gameOver;
	
	bool makeMove(Board* board, Piece* piece, wxPoint dst);
	bool checkValidSrc(Board* board, Piece* piece);
	bool checkValidDest(Board* board, Piece* piece, wxPoint coords);


};




#endif
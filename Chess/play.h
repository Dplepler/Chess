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
	~Play();

	bool gameOver;

	bool isSelectOrMove() const;

	void setSelectOrMove(bool flag);
	void switchMove();

	bool makeMove(Board* board, Piece* piece, wxPoint dst);
	bool checkValidSrc(Board* board, Piece* piece);
	bool checkValidDest(Board* board, Piece* piece, wxPoint coords);

private:

	bool turn;
	bool selectOrMove;


};




#endif
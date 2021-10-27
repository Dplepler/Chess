#ifndef PLAY_CLASS_H
#define PLAY_CLASS_H

#include "board.h"
#include <iostream>


class Play
{

public:

	Play();
	bool turn;
	bool gameOver;
	
	std::string makeMove(Board* board, wxPoint src, wxPoint dst);
	bool checkValidSrc(Board* board, Piece* piece);
	bool checkValidDest(Board* board, Piece* piece, wxPoint coords);


};





#endif
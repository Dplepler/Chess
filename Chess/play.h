#ifndef PLAY_CLASS_H
#define PLAY_CLASS_H

#include "board.h"
#include <iostream>


class Play
{

public:

	Play();
	bool turn;
	
	void makeMove(Board* board);



};





#endif
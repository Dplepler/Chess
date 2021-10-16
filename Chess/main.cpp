#include <iostream>
#include "main.h"
#include "board.h"
#include "play.h"

Main::Main() : wxFrame(nullptr, wxID_ANY, "Plepler Chess")
{

}

Main::~Main()
{



}



//int main(void)
//{
//	unsigned int i = 0;
//	unsigned int i2 = 0;
//
//
//	Board* board = new Board();
//	Play* play = new Play();
//
//	while (!play->gameOver)
//	{
//		for (i = 0; i < BOARD_HEIGHT; i++)
//		{
//
//			for (i2 = 0; i2 < BOARD_WIDTH; i2++)
//			{
//				if (board->board[i][i2])
//					std::cout << Piece::idToString(board->board[i][i2]->id) << ", ";
//
//			}
//
//			std::cout << "\n";
//		}
//
//
//		play->makeMove(board);
//
//		
//
//	}
//}
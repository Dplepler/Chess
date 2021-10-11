#include "play.h"

Play::Play() {}

void Play::makeMove(Board* board)
{
	int line;
	int column;
	Piece* piece = nullptr;

	std::cout << "Make a move\n" << "unsigned int and column of piece to move (in that order): ";
	std::cin >> line >> column;

	piece = board->getPiece(line, column);

	std::cout << "Make a move\n" << "unsigned int and column of piece to go to (in that order): ";
	std::cin >> line >> column;

	if (piece->checkMove(line, column))
	{


	}
	



}
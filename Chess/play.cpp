#include "play.h"

Play::Play()
{
	this->turn = WHITE;
	this->gameOver = false;
}

void Play::makeMove(Board* board)
{
	int line;
	int column;
	bool tryAgain = false;

	Piece* piece = nullptr;

	do 
	{

		tryAgain = false;

		std::cout << "Make a move\n" << "line and column of piece to move (in that order): ";
		std::cin >> line >> column;

		std::cout << "\n";

		piece = board->getPiece(line, column);

		if (!piece)
		{
			tryAgain = true;
		}
		else if ((piece->color == WHITE && this->turn == BLACK) || (piece->color == BLACK && this->turn == WHITE))
		{
			tryAgain = true;
			std::cout << "You can't move the other player's piece\n";
		}
			
	
	} while (tryAgain);
	
	do
	{
		std::cout << "Make a move\n" << "line and column of piece to go to (in that order): ";
		std::cin >> line >> column;

		std::cout << "\n";

		if (board->board[line][column] && board->board[line][column]->color == piece->color)
			std::cout << "You already have a piece in the desired position\n";

	} while (board->board[line][column] && board->board[line][column]->color == piece->color);
	

	if (piece->checkMove(line, column))
	{
		board->updateBoard(line, column, piece);
		piece->updateCoords(line, column);
	}
	else
	{
		std::cout << "Invalid move, try again\n";  
	}

	this->turn = !this->turn;

}
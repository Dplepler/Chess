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
		tryAgain = false;

		std::cout << "Make a move\n" << "line and column of piece to go to (in that order): ";
		std::cin >> line >> column;

		std::cout << "\n";

		if (line > BOARD_HEIGHT - 1 || column > BOARD_WIDTH - 1)
		{
			std::cout << "One or more parameters are too high\n";
			tryAgain = true;
		}

		else if (board->board[line][column] && board->board[line][column]->color == piece->color)
		{
			std::cout << "You already have a piece in the desired position\n";
			tryAgain = true;
		}
			

	} while (tryAgain);
	

	if (piece->checkMove(line, column, board))
	{
		board->updateBoard(line, column, piece);
		piece->updateCoords(line, column);

		this->turn = !this->turn;
	}
	else
	{
		std::cout << "Invalid move, try again\n";
	}
}
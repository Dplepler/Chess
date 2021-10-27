#include "play.h"

Play::Play()
{
	this->turn = WHITE;
	this->gameOver = false;
}

std::string Play::makeMove(Board* board, wxPoint src, wxPoint dst)
{
	std::string errorMessage;

	Piece* piece = nullptr;

	piece = board->getPiece(src.y, src.x);


	//if ((piece->color == WHITE && this->turn == BLACK) || (piece->color == BLACK && this->turn == WHITE))
	//{
	//	errorMessage = "You can't move the other player's piece\n";
	//}


	
			

	if (piece->checkMove(dst.y, dst.x, board))
	{
		board->updateBoard(dst.y, dst.x, piece);
		piece->updateCoords(dst.y, dst.x);

		this->turn = !this->turn;
	}
	else
	{
		errorMessage = "Invalid move, try again\n";
	}

	return errorMessage;
}

bool Play::checkValidSrc(Board* board, Piece* piece)
{
	bool flag = true;

	if ((piece->color == WHITE && this->turn == BLACK) || (piece->color == BLACK && this->turn == WHITE))
	{
		flag = false;
		
	}

	return flag;
}

bool Play::checkValidDest(Board* board, Piece* piece, wxPoint coords)
{
	bool flag = true;;

	if (board->board[coords.y][coords.x] && board->board[coords.y][coords.x]->color == piece->color)
	{
		flag = false;
	}

	return flag;
}
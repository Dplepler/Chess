#include "play.h"

Play::Play()
{
	this->turn = WHITE;
	this->selectOrMove = SELECT;
	this->gameOver = false;
}

bool Play::makeMove(Board* board, Piece* piece, wxPoint dst)
{
	bool flag = false;
	this->selectOrMove = SELECT;

	if (piece->checkMove(dst.y, dst.x, board))
	{
		board->updateBoard(dst.y, dst.x, piece);
		piece->updateCoords(dst.y, dst.x);

		this->turn = !this->turn;
	}
	else
	{
		flag = true;
	}

	return flag;
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
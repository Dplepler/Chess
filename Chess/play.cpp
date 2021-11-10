#include "play.h"

Play::Play()
{
	this->turn = WHITE;
	this->selectOrMove = SELECT;
	this->gameOver = false;
}

bool Play::isSelectOrMove() const
{
	return this->selectOrMove;
}

void Play::setSelectOrMove(bool flag)
{
	this->selectOrMove = flag;
}

bool Play::makeMove(Board* board, Piece* piece, wxPoint dst)
{
	bool flag = false;
	bool kingCheck = false;
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

	if ((piece->getColor() == WHITE && this->turn == BLACK) || (piece->getColor() == BLACK && this->turn == WHITE))
	{
		flag = false;
	}

	return flag;
}

bool Play::checkValidDest(Board* board, Piece* piece, wxPoint coords)
{
	bool flag = true;;

	if (board->getBoard()[coords.y][coords.x] && board->getBoard()[coords.y][coords.x]->getColor() == piece->getColor())
	{
		flag = false;
	}

	return flag;
}
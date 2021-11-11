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
	int prevLine = piece->getLine();
	int prevCol = piece->getColumn();

	this->selectOrMove = SELECT;

	if (piece->checkMove(dst.y, dst.x, board))
	{
		if (board->checkCheck(piece->getColor()))	// If the current player's king is in check
			kingCheck = true;

		board->updateBoard(dst.y, dst.x, piece);
		piece->updateCoords(dst.y, dst.x);
		
		// If the player's king was in check and his move didn't change that, it's invalid
		if (!(kingCheck && board->checkCheck(piece->getColor())))
		{
			this->turn = !this->turn;
		}
		else
		{
			board->updateBoard(prevLine, prevCol, piece);
			piece->updateCoords(prevLine, prevCol);
			flag = true;
		}
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
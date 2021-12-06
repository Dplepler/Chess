#include "play.h"

Play::Play() : turn(WHITE), selectOrMove(SELECT), gameOver(false) { }

bool Play::isSelectOrMove() const
{
	return this->selectOrMove;
}

void Play::setSelectOrMove(bool flag)
{
	this->selectOrMove = flag;
}

void Play::switchMove()
{
	this->turn = !this->turn;
}

bool Play::makeMove(Board* board, Piece* piece, wxPoint dst)
{
	bool flag = false;
	bool kingCheck = false;
	int prevLine = piece->getLine();
	int prevCol = piece->getColumn();

	this->selectOrMove = SELECT;

	if (!piece->checkMove(dst.y, dst.x, board)) {
		return true;
	}

	board->updateBoard(dst.y, dst.x, piece);
	piece->updateCoords(dst.y, dst.x);
		
	// If the player's king is in check after his move, the move is invalid
	if (board->checkCheck(piece->getColor()).size() > 0)
	{
		board->updateBoard(prevLine, prevCol, piece);
		piece->updateCoords(prevLine, prevCol);
		flag = true;
	}	


	return flag;
}

bool Play::checkValidSrc(Board* board, Piece* piece)
{
	return !((piece->getColor() == WHITE && this->turn == BLACK) || (piece->getColor() == BLACK && this->turn == WHITE));
}

bool Play::checkValidDest(Board* board, Piece* piece, wxPoint coords)
{
	return !(board->getBoard()[coords.y][coords.x] && board->getBoard()[coords.y][coords.x]->getColor() == piece->getColor());
}
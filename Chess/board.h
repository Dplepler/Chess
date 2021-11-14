#ifndef BOARD_CLASS_H
#define BOARD_CLASS_H

#include <iostream>
#include <string>
#include "wx/wx.h"
#include "PieceIDs.h"

class Rook;
class Queen;
class King;
class Knight;
class Bishop;
class Pawn;
class Piece;
class Play;

#define BOARD_HEIGHT 8
#define BOARD_WIDTH 8

#define PIECES 32

#define TWICE 2
#define KING_RANGE 3

class Board
{

public:

	// C'tor
	Board(Play* play);
	~Board();

	std::vector<std::vector<Piece*>> getBoard();

	void updateBoard(int line, int col, Piece* piece);
	std::vector<Piece*> validDestPieces(wxPoint dst, bool color);
	Piece* getPiece(int line, int col) const;
	bool kingCheck(bool color) const;

	bool checkCheck(bool color);
	bool checkMate(bool color);
	bool checkLine(unsigned int startPos, unsigned int endPos, bool lineOrCol, bool color);
	bool checkDiagonal(wxPoint dst, bool color);
	bool checkHorse(bool color);
	

private:

	std::vector<std::vector<Piece*>> board;
	std::vector<King*> kings;

	Play* play;


};





#endif
#pragma once
#ifndef BOARD
#define BOARD
#include "Piece.h"

class Board
{
public:
	bool IsFreeBlock(int pX, int pY) const;
	bool IsPossibleMovement(int pX, int pY, int pPiece, int pRotation) const;
	bool HereBomb(int pX, int pY) const;
	void StorePiece(int pX, int pY, int pPiece, int pRotation);
	int StorePieceBomb(int pX, int pY);
	int DeletePossibleLines();
	bool IsGameOver() const;
	void InitBoard();



private:
	enum { POS_FREE, POS_FILLED };          // POS_FREE = free position of the board; POS_FILLED = filled position of the board
	int mBoard[BOARD_HEIGHT][BOARD_WIDTH]; // Board that contains the pieces
	void DeleteLine(int pY);
	Piece *mPieces;

};

#endif

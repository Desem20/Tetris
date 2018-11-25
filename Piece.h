#pragma once
#ifndef PIECE
#define PIECE
#include "Gotoxy.h"
#include <Windows.h>
#define BOARD_WIDTH 10             // Board width in blocks 
#define BOARD_HEIGHT 12            // Board height in blocks
#define PIECE_BLOCKS 5 // Number of horizontal and vertical blocks of a matrix piece
#define FIFTY 50
#define TWOHUNDRED 200
#include <iostream>
using namespace std;

class Piece
{
public:
	int checkline(int pPiece, int  pRotation, int line) const;
	int GetBlockType(int pPiece, int pRotation, int pX, int pY) const;
	char SignPiece(int pPiece) const;
	 void draw(int blocktype, int rotate, int x = 3, int y = 7) const;
     void DeleteDraw(int blocktype, int rotate, int x, int y) const;
	  void DeleteDrawBomb(int x, int y) const;
	enum eNumbers { ONE = 1, TWO, THREE, FOUR, FIVE,SIX,SEVEN,TEN=10,SIXTEEN=16 } const;
private:
	
	static const char mPieces[SEVEN /*kind*/][FOUR/* rotation */][FIVE/* horizontal blocks */][FIVE/* vertical blocks */];

};
#endif // !PIECE


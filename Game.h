#pragma once
#ifndef _GAME_
#define _GAME_
#define EXIT 9
#define START 1
#include "Board.h"
#include <time.h>
#include <Windows.h>
#include <conio.h>

class Game
{
public:
	int getScore() const;
	int getNumpieces() const;
	void SetScore(int Score = 0);
	void SetNumpieces(int Numpieces = 0);
	void ScoreLines(int numLines, int piece);
	int GetRand(int pA, int pB) const;
	void drawWindow() const;
	void Move(int &x, int &y, int &rotate, int piece, Board &board, Game &game, bool &stopHere, char newDirection, int &softclick);
	void PrintScorePieces() const;
	void LocateAll(int &i, int j, int piece, int rotate, Board &board, Game &game, bool stopHere, int direction = 0);
	int locateJok(int j, Board &board);
	bool Iflocate(int i, int j, int blocktype, int rotate, Board &board);
	void Run() ;
	void MakeFaster();
	void MakeSlower();
	void Pause() const;
	int Getspeed() const;


	enum eKEYS { PAUSE = 50, FAST, SLOW, STRAITLOCATE = 'a', J = 's', LEFT = 'K', RIGHT = 'M', DOWN = 'P', ROTATE = 'H' } const;


private:
	int Score;
	int Numpieces = 0;
	Piece *piece;
	int sleep = 500;




};
#endif

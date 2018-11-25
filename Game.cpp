#include "Game.h"
using namespace std;
//random number from pA to pB
int Game::GetRand(int pA = 0, int pB = 6) const
{
	return rand() % (pB - pA + 1) + pA;
}
void Game::MakeFaster()
{
	sleep -= FIFTY;
}
void Game::MakeSlower() 
{
	sleep += FIFTY;
}
int Game::Getspeed() const
{
	return sleep;
}
int Game::getNumpieces() const
{
	return Numpieces;
}
int Game::getScore() const
{
	return Score;
}

void Game::SetScore(int n)
{
	Score += n;
}
void Game::ScoreLines(int numLines, int piece)
{
	switch (numLines)
	{
	case 0:
		break;
	case 1:
		if (piece == Piece::TWO)
			SetScore(FIFTY);//if the joker is the last part that missing to delete the line
		else
			SetScore(FIFTY * Piece::TWO);
		break;
	case 2:
		SetScore(FIFTY * Piece::SIX);
		break;
	case 3:
		SetScore(FIFTY * Piece::TEN);
		break;
	default:
		SetScore(FIFTY * Piece::SIXTEEN);
	}
}
void Game::SetNumpieces(int m)
{
	Numpieces += m;
}
void Game::Move(int &x, int &y, int &rotate, int piece, Board &board, Game &game, bool &stopHere, char newDirection, int &softClick)
{
	int i = x;
	int j = y;
	int casting = (int)newDirection;
	switch (casting)
	{
	case LEFT:
		if (board.IsPossibleMovement(x, y - 1, piece, rotate))
		{
			y = y - 1;
			this->piece->draw(piece, rotate, x, y);
			Sleep(TWOHUNDRED);
			this->piece->DeleteDraw(piece, rotate, x, y);
			LocateAll(x, y, piece, rotate, board, game, stopHere);
		}
		else if (piece == 3)
			LocateAll(x, --j, piece, rotate, board, game, stopHere, LEFT);
		break;
	case RIGHT:
		if (board.IsPossibleMovement(x, y + 1, piece, rotate))
		{
			y = y + 1;
			this->piece->draw(piece, rotate, x, y);
			Sleep(TWOHUNDRED);
			this->piece->DeleteDraw(piece, rotate, x, y);
			LocateAll(x, y, piece, rotate, board, game, stopHere);
		}
		else if (piece == Piece::THREE)
			LocateAll(x, ++j, piece, rotate, board, game, stopHere, RIGHT);
		break;
	case DOWN:
		if (board.IsPossibleMovement(x + 1, y, piece, rotate))
		{
			x = x + 1;
			this->piece->draw(piece, rotate, x, y);
			Sleep(TWOHUNDRED);
			this->piece->DeleteDraw(piece, rotate, x, y);
			LocateAll(x, y, piece, rotate, board, game, stopHere);
			if (softClick<Piece::TWO)
				game.SetScore(Piece::ONE);
			else
				game.SetScore(Piece::TWO);
		}
		break;
	case ROTATE:
		if (rotate == Piece::THREE)
		{
			if (board.IsPossibleMovement(x + 1, y, piece, 0))
			{
				rotate = 0;
				this->piece->draw(piece, rotate, x, y);
				Sleep(TWOHUNDRED);
				this->piece->DeleteDraw(piece, rotate, x, y);
				LocateAll(x, y, piece, rotate, board, game, stopHere);
			}
		}
		else if (board.IsPossibleMovement(x + 1, y, piece, rotate + 1))
		{
			rotate++;
			this->piece->draw(piece, rotate, x, y);
			Sleep(TWOHUNDRED);
			this->piece->DeleteDraw(piece, rotate, x, y);
			LocateAll(x, y, piece, rotate, board, game, stopHere);
		}
		break;

	case PAUSE://this is drawing when the game pause:
		if (board.IsPossibleMovement(x, y, piece, rotate))
		{
			this->piece->draw(piece, rotate, x, y);
			game.Pause();
			this->piece->DeleteDraw(piece, rotate, x, y);
		}
		break;
	case FAST:
		game.MakeFaster();
		break;
	case SLOW:
		game.MakeSlower();
		break;
	case STRAITLOCATE://if you press 'a' the piece go straight to the her location
		for (x; x < BOARD_HEIGHT; x++)
		{
			if (board.IsPossibleMovement(x, y, piece, rotate))
			{
				this->piece->draw(piece, rotate, x, y);
				this->piece->DeleteDraw(piece, rotate, x, y);
				LocateAll(x, y, piece, rotate, board, game, stopHere);

			}
		}
	case J://if you press 's' you letting know that if there is J,he we stops in this location
		stopHere = true;
		break;

	}
}
void Game::drawWindow() const
{
	for (int i = 0; i < BOARD_HEIGHT; i++)
	{
		gotoxy(0, BOARD_WIDTH + i);
		cout << '#';
	}
	for (int i = 0; i < BOARD_HEIGHT; i++)
	{
		gotoxy(BOARD_WIDTH + 1, BOARD_WIDTH + i);
		cout << '#';
	}
	for (int j = 1; j < BOARD_WIDTH + 1; j++)
	{
		gotoxy(j, BOARD_WIDTH + BOARD_HEIGHT);
		cout << '#';
	}


}
void Game::PrintScorePieces() const
{
	gotoxy(0, 7);
	cout << "the total score is" << " " << Score;
	gotoxy(0, 8);
	cout << "the total pieces is" << " " << Numpieces;

}
void Game::LocateAll(int &i, int j, int piece, int rotate, Board &board, Game &game, bool stopHere, int direction)
{
	if (piece == Piece::THREE)//if this is the bomb
	{
		int NumBlockBomb;
		int x = i;
		x++;
		if (board.HereBomb(x, j))
		{
			if (LEFT == direction)
				j++;
			else if (RIGHT == direction)
				j--;
			this->piece->DeleteDrawBomb(x - 1, j);
			NumBlockBomb = board.StorePieceBomb(x - 1, j - 1);
			game.SetScore(NumBlockBomb*-FIFTY);
			i = BOARD_HEIGHT;//if it located so go out from the loop to the next piece
		}
	}
	else if (piece == Piece::TWO)
	{
		if ((locateJok(j, board) == i) || (stopHere))
		{
			board.StorePiece(i, j - 1, 2, 0);
			this->piece->draw(piece, rotate, i, j);
			i = BOARD_HEIGHT;//if it located so go out from the loop to the next piece
		}
	}
	else if (Iflocate(i, j, piece, rotate, board))
	{
		this->piece->draw(piece, rotate, i, j);
		i = BOARD_HEIGHT;;//if it located so go out from the loop to the next piece
	}
}
int Game::locateJok(int j, Board &board)
{
	int index = -5;
	for (int k = -5; k < BOARD_HEIGHT; k++)
		if (board.IsPossibleMovement(k, j, 2, 0))
			index = k;
	return index;
}
bool Game::Iflocate(int i, int j, int blocktype, int rotate, Board &board)
{
	i++;//checks the next row,if there are collision in the next raw,locate here.
	if (board.IsPossibleMovement(i, j, blocktype, rotate) == false)
	{
		board.StorePiece(i - 1, j - 1, blocktype, rotate);
		return true;//return true if the is the location where you locate the piece
	}
	else
		return false;
}
void Game::Pause() const
{
	bool check = true;
	while (check)
	{
		if (_kbhit())
		{
			int keyPressed = _getch(); // take the head of the buffer
			if ((keyPressed - '0') == Piece::TWO)
				check = false;
		}
	}
}
void Game::Run()
{
	bool gameover = false, loop = false;
	bool bombed = false;
	int countLines;
	Board board;
	Game game;
	char keyPressed = 0;
	int softclick = 0;
	board.InitBoard();
	srand(time(NULL));
	game.SetNumpieces();
	game.SetScore();
	game.drawWindow();
	while (!(board.IsGameOver()) && (!gameover))
	{
		loop = false;
		bool stopHere = false;
		int count = 0;
		int j = 3;//starting point
		int piece = GetRand();
		int rotate = 0;
		game.PrintScorePieces();
		for (int i = -5; i < BOARD_HEIGHT; i++)
		{
			if (board.IsPossibleMovement(i, j, piece, rotate))
			{
				this->piece->draw(piece, rotate, i, j);
				Sleep(game.Getspeed());
				this->piece->DeleteDraw(piece, rotate, i, j);
				LocateAll(i, j, piece, rotate, board, game, stopHere);
				loop = true;

			}
			while (_kbhit()) // checks if there is anything in the buffer
			{
				keyPressed = _getch(); // take the head of the buffer
				if ((keyPressed - '0') == 9)
					break;
				Move(i, j, rotate, piece, board, game, stopHere, keyPressed, softclick);//moving if its possible		
				game.PrintScorePieces();
				softclick++;
			}
			softclick = 0;
			if (i > 0 && (!loop))
				gameover = true;
			if ((stopHere) && piece == 2)
				i--;
			if ((keyPressed - '0') == EXIT || gameover)
				break;
		}
		if (((keyPressed - '0') == EXIT))
			break;
		countLines = board.DeletePossibleLines();//delete all the lines and return the number of the lines
		game.ScoreLines(countLines, piece);//add by the rules points
		game.SetNumpieces(1);//add every time the piece is fallen
	};
	system("cls");
	gotoxy(5, BOARD_WIDTH);
	cout << "game is over,my friend";

};

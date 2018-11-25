#include "Board.h"
#include "Piece.h"
const char Piece::mPieces[SEVEN/*kind*/][FOUR/* rotation */][FIVE/* horizontal blocks */][FIVE/* vertical blocks */] =
{
	// Square
	{
		{
			{ 0, 0, 0, 0, 0 },
			{ 0, 0, 0, 0, 0 },
			{ 0, 0, 1, 1, 0 },
			{ 0, 0, 1, 1, 0 },
			{ 0, 0, 0, 0, 0 }
		},
		{
			{ 0, 0, 0, 0, 0 },
			{ 0, 0, 0, 0, 0 },
			{ 0, 0, 1, 1, 0 },
			{ 0, 0, 1, 1, 0 },
			{ 0, 0, 0, 0, 0 }
		},
		{
			{ 0, 0, 0, 0, 0 },
			{ 0, 0, 0, 0, 0 },
			{ 0, 0, 1, 1, 0 },
			{ 0, 0, 1, 1, 0 },
			{ 0, 0, 0, 0, 0 }
		},
		{
			{ 0, 0, 0, 0, 0 },
			{ 0, 0, 0, 0, 0 },
			{ 0, 0, 1, 1, 0 },
			{ 0, 0, 1, 1, 0 },
			{ 0, 0, 0, 0, 0 }
		}
	},
	// I
	{
		{
			{ 0, 0, 0, 0, 0 },
			{ 0, 0, 0, 0, 0 },
			{ 0, 2, 2, 2, 2 },
			{ 0, 0, 0, 0, 0 },
			{ 0, 0, 0, 0, 0 }
		},
		{
			{ 0, 0, 0, 0, 0 },
			{ 0, 0, 2, 0, 0 },
			{ 0, 0, 2, 0, 0 },
			{ 0, 0, 2, 0, 0 },
			{ 0, 0, 2, 0, 0 }
		},
		{
			{ 0, 0, 0, 0, 0 },
			{ 0, 0, 0, 0, 0 },
			{ 2, 2, 2, 2, 0 },
			{ 0, 0, 0, 0, 0 },
			{ 0, 0, 0, 0, 0 }
		},
		{
			{ 0, 0, 2, 0, 0 },
			{ 0, 0, 2, 0, 0 },
			{ 0, 0, 2, 0, 0 },
			{ 0, 0, 2, 0, 0 },
			{ 0, 0, 0, 0, 0 }
		}
	},
	//JOKER
	{
	{
		{ 0, 0, 0, 0, 0 },
		{ 0, 0, 0, 0, 0 },
		{ 0, 0, 3, 0, 0 },
		{ 0, 0, 0, 0, 0 },
		{ 0, 0, 0, 0, 0 },
	},
	{
		{ 0, 0, 0, 0, 0 },
		{ 0, 0, 0, 0, 0 },
		{ 0, 0, 3, 0, 0 },
		{ 0, 0, 0, 0, 0 },
		{ 0, 0, 0, 0, 0 },
	},
	{
		{ 0, 0, 0, 0, 0 },
		{ 0, 0, 0, 0, 0 },
		{ 0, 0, 3, 0, 0 },
		{ 0, 0, 0, 0, 0 },
		{ 0, 0, 0, 0, 0 },
	},
	{
		{ 0, 0, 0, 0, 0 },
		{ 0, 0, 0, 0, 0 },
		{ 0, 0, 3, 0, 0 },
		{ 0, 0, 0, 0, 0 },
		{ 0, 0, 0, 0, 0 },
		}
	},
{
		//BOMB
	{
		{ 0, 0, 0, 0, 0 },
		{ 0, 0, 0, 0, 0 },
		{ 0, 0, 4, 0, 0 },
		{ 0, 0, 0, 0, 0 },
		{ 0, 0, 0, 0, 0 },
	},
	{
		{ 0, 0, 0, 0, 0 },
		{ 0, 0, 0, 0, 0 },
		{ 0, 0, 4, 0, 0 },
		{ 0, 0, 0, 0, 0 },
		{ 0, 0, 0, 0, 0 },
	},
	{
		{ 0, 0, 0, 0, 0 },
		{ 0, 0, 0, 0, 0 },
		{ 0, 0, 4, 0, 0 },
		{ 0, 0, 0, 0, 0 },
		{ 0, 0, 0, 0, 0 },
	},
	{
		{ 0, 0, 0, 0, 0 },
		{ 0, 0, 0, 0, 0 },
		{ 0, 0, 4, 0, 0 },
		{ 0, 0, 0, 0, 0 },
		{ 0, 0, 0, 0, 0 },
		}
	},
	// L
	{
		{
			{ 0, 0, 0, 0, 0 },
			{ 0, 5, 0, 0, 0 },
			{ 0, 5, 5, 5, 0 },
			{ 0, 0, 0, 0, 0 },
			{ 0, 0, 0, 0, 0 }
		},
		{
			{ 0, 0, 0, 0, 0 },
			{ 0, 0, 5, 5, 0 },
			{ 0, 0, 5, 0, 0 },
			{ 0, 0, 5, 0, 0 },
			{ 0, 0, 0, 0, 0 }
		},
		{
			{ 0, 0, 0, 0, 0 },
			{ 0, 0, 0, 0, 0 },
			{ 0, 5, 5, 5, 0 },
			{ 0, 0, 0, 5, 0 },
			{ 0, 0, 0, 0, 0 }
		},
		{
			{ 0, 0, 0, 0, 0 },
			{ 0, 0, 5, 0, 0 },
			{ 0, 0, 5, 0, 0 },
			{ 0, 5, 5, 0, 0 },
			{ 0, 0, 0, 0, 0 }
		}
	},
	// T
	{
		{
			{ 0, 0, 0, 0, 0 },
			{ 0, 0, 6, 0, 0 },
			{ 0, 0, 6, 6, 0 },
			{ 0, 0, 6, 0, 0 },
			{ 0, 0, 0, 0, 0 }
		},
		{
			{ 0, 0, 0, 0, 0 },
			{ 0, 0, 0, 0, 0 },
			{ 0, 6, 6, 6, 0 },
			{ 0, 0, 6, 0, 0 },
			{ 0, 0, 0, 0, 0 }
		},
		{
			{ 0, 0, 0, 0, 0 },
			{ 0, 0, 6, 0, 0 },
			{ 0, 6, 6, 0, 0 },
			{ 0, 0, 6, 0, 0 },
			{ 0, 0, 0, 0, 0 }
		},
		{
			{ 0, 0, 0, 0, 0 },
			{ 0, 0, 6, 0, 0 },
			{ 0, 6, 6, 6, 0 },
			{ 0, 0, 0, 0, 0 },
			{ 0, 0, 0, 0, 0 }
		}
	},
	{
	// N
	    {
		    { 0, 0, 0, 0, 0 },
		    { 0, 7, 7, 0, 0 },
		    { 0, 0, 7, 7, 0 },
		    { 0, 0, 0, 0, 0 },
		    { 0, 0, 0, 0, 0 }
	   },
	   {
		    { 0, 0, 0, 0, 0 },
		    { 0, 0, 0, 7, 0 },
		    { 0, 0, 7, 7, 0 },
		    { 0, 0, 7, 0, 0 },
		    { 0, 0, 0, 0, 0 }
	   },
	{
	     	{ 0, 0, 0, 0, 0 },
	    	{ 0, 0, 0, 0, 0 },
	    	{ 0, 7, 7, 0, 0 },
	     	{ 0, 0, 7, 7, 0 },
	    	{ 0, 0, 0, 0, 0 }
	},
	{
		    { 0, 0, 0, 0, 0 },
	     	{ 0, 0, 7, 0, 0 },
	    	{ 0, 7, 7, 0, 0 },
		    { 0, 7, 0, 0, 0 },
		    { 0, 0, 0, 0, 0 }
	}
   },
};
int Piece::GetBlockType(int pPiece, int  pRotation, int pX, int pY) const
{
	return mPieces[pPiece][pRotation][pX][pY];
}
int Piece::checkline(int pPiece, int  pRotation, int line) const//return true if the line is empty
{
	for (int j = 0; j < FIVE; j++)
		if (mPieces[pPiece][pRotation][line][j] != 0)
			return false;

	return true;
}
 void Piece::draw(int blocktype, int rotate, int x/*row*/, int y/*col*/) const
{
	char sign = SignPiece(blocktype);
	for (int i = 0; i < Piece::FIVE; i++)
	{
		for (int j = 0; j <Piece::FIVE; j++)
		{
			gotoxy(y + j, x + BOARD_WIDTH + i);
			if (this->GetBlockType(blocktype, rotate, i, j) != 0)
			{
				cout << sign << endl;
			}
		}
	}
}
 void Piece::DeleteDraw(int blocktype, int rotate, int x/*row*/, int y/*col*/) const
{
	for (int i = 0; i < Piece::FIVE; i++)
	{
		for (int j = 0; j <Piece::FIVE; j++)
		{
			gotoxy(y + j, x + BOARD_WIDTH + i);
			if (this->GetBlockType(blocktype, rotate, i, j) != 0)
			{
				cout << ' ' << endl;
			}
		}
	}
}
 void Piece::DeleteDrawBomb(int x, int y)  const
{
	for (int i = x + 1; i < Piece::FIVE - 1 + x; i++)
	{
		for (int j = y + 1; j <Piece::FIVE - 1 + y; j++)
		{
			gotoxy(j, 10 + i);
			if (i < BOARD_HEIGHT && j>0 && j < BOARD_HEIGHT - 1)
				cout << ' ' << endl;
		}
	}
}
char Piece::SignPiece(int pPiece) const
{
	switch (pPiece)
	{
	case 0:
		return '1';
		break;
	case 1:
		return '2';
		break;
	case 2:
		return 'J';
		break;
	case 3:
		return '@';
		break;
	case 4:
		return '5';
		break;
	case 5:
		return '6';
		break;
	case 6:
		return '7';
		break;
	}
}
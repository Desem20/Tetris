#include "Board.h"
//Init the board blocks with free positions
void Board::InitBoard()
{
	for (int i = 0; i < BOARD_HEIGHT; i++)
		for (int j = 0; j < BOARD_WIDTH; j++)
			mBoard[i][j] = POS_FREE;
}
void Board::StorePiece(int pX, int pY, int pPiece, int pRotation)
{
	// Store each block of the piece into the board
	for (int i1 = pX, i2 = 0; i1 < pX + PIECE_BLOCKS; i1++, i2++)
	{
		for (int j1 = pY, j2 = 0; j1 < pY + PIECE_BLOCKS; j1++, j2++)
		{
			// Store only the blocks of the piece that are not holes
			if (mPieces->GetBlockType(pPiece, pRotation, i2, j2) != 0)
				mBoard[i1][j1] = mPieces->GetBlockType(pPiece, pRotation, i2, j2);
		}
	}
}
int Board::StorePieceBomb(int pX, int pY)
{
	int count = 0;
	for (int i = pX + 1; i < pX + Piece::FOUR; i++)
	{
		for (int j = pY + 1; j < pY + Piece::FOUR; j++)
		{
			if (mBoard[i][j] != POS_FREE && (i<BOARD_HEIGHT && (j >= 0 && j<BOARD_WIDTH)))
				count++;
			if (i<BOARD_HEIGHT && j<BOARD_WIDTH)
				mBoard[i][j] = POS_FREE;
		}
	}
	return count;

}
/*
Check if the game is over becase a piece have achived the upper position
Returns true or false
*/
bool Board::IsGameOver() const
{
	//If the first line has blocks, then, game over
	for (int i = 0; i < BOARD_WIDTH; i++)
	{
		if (mBoard[0][i] == POS_FILLED)
			return true;
	}

	return false;
}
void Board::DeleteLine(int pY)
{
	// Moves all the upper lines one row down
	for (int j = 0; j < BOARD_WIDTH; j++)
	{
		gotoxy(j + 1, pY + BOARD_WIDTH);
		cout << ' ';
	}
	Sleep(FIFTY);
	for (int i = pY; i >= 0; i--)
	{
		for (int j = 0; j < BOARD_WIDTH; j++)
		{
			if (i != 0)//when i=0 it can'n get the mBoard[i-1][j]because its out of the limit of the array
			{
				mBoard[i][j] = mBoard[i - 1][j];
				gotoxy(j + 1, i + BOARD_WIDTH);
				if (mBoard[i - 1][j] != POS_FREE)
				{
					if (mBoard[i - 1][j] == 3)
						cout << 'J';
					else if (mBoard[i - 1][j] == 4)
						cout << '@';
					else
						cout << mBoard[i - 1][j];
				}
				else
					cout << ' ';
			}
			else
			{
				gotoxy(j + 1, i + BOARD_WIDTH);
				cout << ' ';
			}

		}
	}
}

//Delete all the lines that should be removed
int Board::DeletePossibleLines()
{
	int count = 0;//counts the number of lines that removed
	for (int i = BOARD_HEIGHT - 1; i >= 0; i--)
	{
		int j = 0;
		while (j < BOARD_WIDTH)
		{
			if (mBoard[i][j] == POS_FREE)
				break;
			j++;
		}

		if (j == BOARD_WIDTH)
		{
			DeleteLine(i);
			i++;
			count++;
		}
	}
	return count;
}
bool Board::IsFreeBlock(int pX, int pY) const
{
	if (mBoard[pX][pY] == POS_FREE)
		return true;
	else
		return false;
}
bool Board::IsPossibleMovement(int pX, int pY, int pPiece, int pRotation) const
{
	// Checks collision with pieces already stored in the board or the board limits
	// This is just to check the 5x5 blocks of a piece with the appropriate area in the board
	for (int i1 = pX, i2 = 0; i1 < pX + PIECE_BLOCKS; i1++, i2++)
	{
		for (int j1 = pY, j2 = 0; j1 < pY + PIECE_BLOCKS; j1++, j2++)
		{
			// Check if the piece is outside the limits of the board
			if (i1 < 0 || i1 > BOARD_HEIGHT - 1 || j1<1 || j1 > BOARD_WIDTH)
			{
				if (mPieces->GetBlockType(pPiece, pRotation, i2, j2) != 0)
					return 0;
			}

			// Check if the piece have collisioned with a block already stored in the map
			if (j1 >= 1 && j1 <= BOARD_WIDTH)
			{
				if ((mPieces->GetBlockType(pPiece, pRotation, i2, j2) != 0) && (!IsFreeBlock(i1, j1 - 1)))
					return false;
			}
		}
	}
	// No collision
	return true;
}
bool Board::HereBomb(int pX, int pY) const
{
	// Checks collision with pieces already stored in the board  
	// This is just to check the 5x5 blocks of a piece with the appropriate area in the board
	for (int i1 = pX, i2 = 0; i1 < pX + PIECE_BLOCKS; i1++, i2++)
	{
		for (int j1 = pY, j2 = 0; j1 < pY + PIECE_BLOCKS; j1++, j2++)
		{
			// Check if the piece have collisioned with a block already stored in the map
			if (j1 >= 1 && j1 <= BOARD_WIDTH)
			{
				if ((mPieces->GetBlockType(3, 0, i2, j2) != 0) && (!IsFreeBlock(i1, j1 - 1)))
					return true;//return true if here you need to bomb 
			}
		}
	}
	return false;
}

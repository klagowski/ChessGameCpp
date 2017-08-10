#include "Rook.h"


char Rook::GetPieceName()
{
	return 'R';
}


bool Rook::MoveRules(int _currentRow, int _currentCol, int _destinationRow, int _destinationCol, vector<vector<Piece*>> _chessSquare)
{
	/** Sprawdzenie, czy ruch odbywa siê w jednym wierszu.*/
	if (_currentRow == _destinationRow)
	{
		/** Sprawdzenie, czy pola wzd³u¿ ruchu s¹ puste.*/
		int tempCol = (_destinationCol > _currentCol) ? 1 : -1;
		for (int i = _currentCol + tempCol; i != _destinationCol; i += tempCol)
		{
			if (_chessSquare[_currentRow][i] != 0)
			{
				return false;
			}
		}
		return true;
	}
	/** Sprawdzenie, czy ruch odbywa siê w jednej kolumnie.*/
	else if(_destinationCol == _currentCol)
	{
		/** Sprawdzenie, czy pola wzd³u¿ ruchu s¹ puste.*/
		int tempRow = (_destinationRow > _currentRow) ? 1 : -1;
		for (int i = _currentRow + tempRow; i != _destinationRow; i += tempRow)
		{
			if (_chessSquare[i][_currentCol] != 0)
			{
				return false;
			}
		}
		return true;
	}
	return false;
}


Rook::~Rook()
{
}


#include "Bishop.h"


char Bishop::GetPieceName()
{
	return 'B';
}


bool Bishop::MoveRules(int _currentRow, int _currentCol, int _destinationRow, int _destinationCol, vector<vector<Piece*>> _chessSquare)
{
	/** Sprawdzenie, czy ruch odbywa siê po przek¹tnych.*/
	if ((_destinationCol - _currentCol == _destinationRow - _currentRow) || (_destinationCol - _currentCol == _currentRow - _destinationRow)) 
	{
		/** Sprawdzenie, czy pola wzd³u¿ ruchu s¹ puste.*/
		int tempRow = (_destinationRow > _currentRow) ? 1 : -1;
		int tempCol = (_destinationCol > _currentCol) ? 1 : -1;
		
		for (int iRow = _currentRow + tempRow, iCol = _currentCol + tempCol; iRow != _destinationRow; iRow += tempRow, iCol += tempCol)
		{
			if (_chessSquare[iRow][iCol] != 0) 
			{
				return false;
			}
		}
		return true;
	}
	return false;
}

Bishop::~Bishop()
{
}

#include "Queen.h"


char Queen::GetPieceName()
{
	return 'Q';
}


bool Queen::MoveRules(int _currentRow, int _currentCol, int _destinationRow, int _destinationCol, vector<vector<Piece*>> _chessSquare)
{
	/** Sprawdzenie, czy ruch odbywa si� po przek�tnych.*/
	if ((_destinationCol - _currentCol == _destinationRow - _currentRow) || (_destinationCol - _currentCol == _currentRow - _destinationRow)) 
	{
		int tempRow = (_destinationRow > _currentRow) ? 1 : -1;///<Zmienna przyjmuje warto�� 1 gdy ruch odbywa sie w d�, -1 gdy w g�re.
		int tempCol = (_destinationCol > _currentCol) ? 1 : -1;///<Zmienna przyjmuje warto�� 1 gdy ruch odbywa sie w prawo, -1 gdy w lewo.
		/** Sprawdzenie, czy pola wzd�u� ruchu s� puste.*/
		for (int iRow = _currentRow + tempRow, iCol = _currentCol + tempCol; iRow != _destinationRow; iRow += tempRow, iCol += tempCol)
		{
			if (_chessSquare[iRow][iCol] != 0)
			{
				return false;
			}
		}
		return true;
	}
	/** Sprawdzenie, czy ruch odbywa si� w jednym wierszu.*/
	else if (_currentRow == _destinationRow)
	{
		int tempCol = (_destinationCol > _currentCol) ? 1 : -1;///<Zmienna przyjmuje warto�� 1 gdy ruch odbywa sie w prawo, -1 gdy w lewo.
		/** Sprawdzenie, czy pola wzd�u� ruchu s� puste.*/
		for (int i = _currentCol + tempCol; i != _destinationCol; i += tempCol)
		{
			if (_chessSquare[_currentRow][i] != 0)
			{
				return false;
			}
		}
		return true;
	}
	/** Sprawdzenie, czy ruch odbywa si� w jednej kolumnie.*/
	else if (_currentCol == _destinationCol)
	{
		int tempRow = (_destinationRow > _currentRow) ? 1 : -1;///<Zmienna przyjmuje warto�� 1 gdy ruch odbywa sie w d�, -1 gdy w g�re.
		/** Sprawdzenie, czy pola wzd�u� ruchu s� puste.*/
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


Queen::~Queen()
{
}

#include "Pawn.h"


bool Pawn::MoveRules(int _currentRow, int _currentCol, int _destinationRow, int _destinationCol, vector< vector<Piece*> > _chessSquare)
{	/** Sprawdzenie, czy docelowe pole jest puste.*/
	if (_chessSquare[_destinationRow][_destinationCol] == 0)
	{
		/** Sprawdzenie, czy ruch odbywa sie w tej samej kolumnie.*/
		if(_currentCol== _destinationCol)
		{
			/** Sprawdzenie, czy Pionek jest koloru bia�ego.*/
			if (GetPieceColor() == 'W')
			{
				/** Sprawdzenie, czy Pionek b�dzie porusza� sie o jedno pole na szachownicy.*/
				if (_destinationRow == _currentRow - 1)
				{
					return true;
				}
				/** Sprawdzenie, czy Pionek znajduje si� w pozycji pocz�tkowej - dozwolony ruch o dwa pola na szachownicy.*/
				else if (_currentRow == 6)
				{
					if (_destinationRow == _currentRow - 2)
					{
						return true;
					}
				}
			}
			/** Kolor Pionka czarny*/
			else
			{
				if (_destinationRow == _currentRow + 1)
				{
					return true;
				}
				else if (_currentRow == 1)
				{
					if (_destinationRow == _currentRow + 2)
					{
						return true;
					}
				}
			}
		}
	}
	/** Docelowe pole jest zajmowane przez inn� figur�.*/
	else
	{
		/** Sprawdzenie, czy Pionek bedzie porusza� si� o jedna kolumne w prawo lub w lewo na szachownicy.*/
		if (_currentCol == _destinationCol + 1 || _currentCol == _destinationCol - 1)
		{
			/** Sprawdzenie, czy Pionek jest koloru bia�ego.*/
			if (GetPieceColor() == 'W')
			{
				/** Sprawdzenie czy Pionek b�dzie porusza� sie o jedno pole na szachownicy.*/
				if (_destinationRow == _currentRow - 1)
				{
					return true;
				}
			}
			/** Kolor Pionka czarny*/
			else
			{
				if (_destinationRow == _currentRow + 1)
				{
					return true;
				}
			}
		}
	}
	return false;
}


char Pawn::GetPieceName()
{
	return 'P';
}


Pawn::~Pawn()
{
}

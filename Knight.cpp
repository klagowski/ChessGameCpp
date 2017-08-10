#include "Knight.h"


char Knight::GetPieceName()
{
	return 'N';
}


bool Knight::MoveRules(int _currentRow, int _currentCol, int _destinationRow, int _destinationCol, vector<vector<Piece*>> _chessSquare)
{
	/** Sprawdzenie, czy Skoczek bedzie porusza� si� o jedna kolumne w prawo/lewo na szachownicy.
		Wtedy dozwolony ruch o dwa rz�dy w g�re/d� ma szachownicy*/
	if ((_currentCol == _destinationCol + 1) || (_currentCol == _destinationCol - 1))
	{
		if ((_currentRow == _destinationRow + 2) || (_currentRow == _destinationRow - 2))
		{
			return true;
		}
	}
	/** Sprawdzenie, czy Skoczek bedzie porusza� si� o dwie kolumne w prawo/lewo na szachownicy.
	Wtedy dozwolony ruch o jeden rz�dy w g�re/d� ma szachownicy*/
	if ((_currentCol == _destinationCol + 2) || (_currentCol == _destinationCol - 2))
	{
		if ((_currentRow == _destinationRow + 1) || (_currentRow == _destinationRow - 1))
		{
			return true;
		}
	}
	return false;
}


Knight::~Knight()
{
}

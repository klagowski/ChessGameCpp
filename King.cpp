#include "King.h"

char King::GetPieceName()
{
	return 'K';
}


bool King::MoveRules(int _currentRow, int _currentCol, int _destinationRow, int _destinationCol, vector<vector<Piece*>> _chessSquare)
{
	/** Sprawdzenie, czy docelowe pole znajdujê siê wokó³ Króla.*/
	if (((_destinationRow - _currentRow) <= 1 && (_destinationRow - _currentRow) >= -1) && ((_destinationCol - _currentCol) <= 1 && (_destinationCol - _currentCol) >= -1))
	{
		return true;
	}
	return false;
}


King::~King()
{
}

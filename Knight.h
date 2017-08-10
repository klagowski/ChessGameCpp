#pragma once
#include "Piece.h"

/** Klasa pochodna klasy bazowej Piece.
Klasa reprezenuje Skoczka.*/
class Knight :public Piece
{
public:
	virtual char GetPieceName();///<Funkcja wirtualna zwraca nazwe pionka: N-Knight.
	virtual bool MoveRules(int _currentRow, int _currentCol, int _destinationRow, int _destinationCol, vector< vector<Piece*> > _chessSquare);///<Funkcja wirtualna sprawdza czy figura mo¿e wykonaæ danu ruch.
	Knight(char _pieceColor) : Piece(_pieceColor) {};///<Konstruktor.
	virtual ~Knight();///<Destruktor.
};


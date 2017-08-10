#pragma once
#include "Piece.h"

/** Klasa pochodna klasy bazowej Piece.
	Klasa reprezenuje Skoczka.*/
class Bishop : public Piece
{
public:
	virtual char GetPieceName();///<Funkcja wirtualna zwraca nazwe pionka: B-Bishop.
	virtual bool MoveRules(int _currentRow, int _currentCol, int _destinationRow, int _destinationCol, vector< vector<Piece*> > _chessSquare);///<Funkcja wirtualna sprawdza czy figura mo¿e wykonaæ danu ruch.
	Bishop(char _pieceColor) : Piece(_pieceColor) {};///<Konstruktor.
	virtual ~Bishop();///<Destruktor.
};


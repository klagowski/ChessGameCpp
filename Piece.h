#pragma once
#include <iostream>
#include <vector>

using namespace std;
/** Klasa abstrakcyjna*/
class Piece
{ 
protected:
	char pieceColor; ///<Pole przechowuje kolor pionka: W-White, B-Black.
	
public:
	virtual char GetPieceName()=0;///<Funkcja wirtualna zwraca nazwe pionka: P-Pawn, R-Rook, B-Bishop, N-Knight, Q-Queen, K-King.
	char GetPieceColor() { return pieceColor; };///<Funkcja(getter) zwraca "char pieceColor".
	virtual bool MoveRules(int currentRow, int currentCol, int destinationRow, int destinationCol, vector< vector<Piece*> > _chessSquare) = 0; ///<Funkcja wirtualna sprawdza czy dana figura mo¿e wykonaæ danu ruch.

	Piece(char _pieceColor = 'W') :pieceColor(_pieceColor) { };///<Konstruktor.
	virtual ~Piece() {};///<Destruktor.
};


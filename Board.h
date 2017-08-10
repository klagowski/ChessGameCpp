#pragma once
#include <vector>
#include "Pawn.h"
#include "King.h"
#include "Knight.h"
#include "Rook.h"
#include "Piece.h"
#include "Bishop.h"
#include "Queen.h"

/** Klasa Board jest odpowiedzialna za umiejscowienie obiektów klasy Piece na tablicy obiektów chessSquare oraz jej obs³uge*/
class Board
{
public:
	void ResetBoard();///<Metoda uzupelnia tablice obiektów Piece zerami.
	void SetPieceStandartChessBoard();///<Metoda uzupelnia tablice obiektów Piece obiektami klas pochodnych dla gry standardowej.
	///Metoda uzupelnia tablice obiektów Piece obiektami klas pochodnych dla wirtualnej szachownicy.
	void SetPieceVirtualChessBoard(int _destinationRow, int _destinationCol, char _pieceColor, char _pieceType, vector<vector<Piece*>> _chessSquare);
	bool IsKingInCheck(string _playerName);///<Metoda szuka obiektów klasy King, a nastêpnie sprawdza czy Król jest szachowany.
	bool CanPieceMove(string _playerName);///<Metoda sprawdza czy pionki mog¹ wykonaæ jakikolwiek ruch.

	vector< vector<Piece*> > chessSquare; ///<Definicja tablicy obiektów "Piece".

	Board();///<Konstruktor.
	~Board();///<Destruktor.
};


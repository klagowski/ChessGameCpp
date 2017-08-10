#pragma once
#include <vector>
#include "Pawn.h"
#include "King.h"
#include "Knight.h"
#include "Rook.h"
#include "Piece.h"
#include "Bishop.h"
#include "Queen.h"

/** Klasa Board jest odpowiedzialna za umiejscowienie obiekt�w klasy Piece na tablicy obiekt�w chessSquare oraz jej obs�uge*/
class Board
{
public:
	void ResetBoard();///<Metoda uzupelnia tablice obiekt�w Piece zerami.
	void SetPieceStandartChessBoard();///<Metoda uzupelnia tablice obiekt�w Piece obiektami klas pochodnych dla gry standardowej.
	///Metoda uzupelnia tablice obiekt�w Piece obiektami klas pochodnych dla wirtualnej szachownicy.
	void SetPieceVirtualChessBoard(int _destinationRow, int _destinationCol, char _pieceColor, char _pieceType, vector<vector<Piece*>> _chessSquare);
	bool IsKingInCheck(string _playerName);///<Metoda szuka obiekt�w klasy King, a nast�pnie sprawdza czy Kr�l jest szachowany.
	bool CanPieceMove(string _playerName);///<Metoda sprawdza czy pionki mog� wykona� jakikolwiek ruch.

	vector< vector<Piece*> > chessSquare; ///<Definicja tablicy obiekt�w "Piece".

	Board();///<Konstruktor.
	~Board();///<Destruktor.
};


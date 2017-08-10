#pragma once
#include <vector>
#include <cctype>
#include <Windows.h>
#include <algorithm>
#include "Board.h"
#include "Printer.h"

/** Klasa GamePlay jest odpowiedzialna za prowadzenie rozgrywki i obs³uge Menu.*/
class GamePlay
{
private:
	Board ChessBoard;///<Obiekt klasy Board.
	Printer ChessBoardPrint;///<Obiekt klasy Printer.

	string playerName;///<Zmienna przechowuj¹ca nazwê aktualnego gracza - White/Black.
	int menuOption;///<Zmienna przechowuj¹ca stan/rodzaj rogrywki: 0-Menu, 1-Szachy, 2-Wirtualna Szachownica.
	int messageNumber;///<Wartoœæ zmiennej determinuuje wydrukowanie wiadomoœci/erroru: 0-brak wiadomoœci, 1-7-wiadomoœæ/error.

public:
	void AskForPieceVirtualChessBoard();///<Metoda odpowiedzialna za komunikacjê z graczem podczas ustawiania pionków na Wirtualnej Szachownicy.
	///<Metoda sprawdza poprawnoœæ wprowadzonych wspó³rzêdnych/pionków na Wirtualnej Szachownicy np bk-d1(Black King na pole d1).
	bool CheckPieceForVirtualChessBoard(string  _setPieceData);
	///Metoda konwertuje wczytane wartoœci z klawiatury dla ustawiania pionków na Wirtualnej Szachownicy.
	void ConvertPieceDataForVirtualChessBoard(string  _setPieceData, int &_destinationRow, int &_destinationCol, char &_pieceColor, char &_pieceType);
	void SetMessageNumber(int _messageNumber);///<Setter do zmiennej messageNumber.
	bool AreYouSure();///<Gracz potwierdza - Y/N - gdy zmiana menuOption z 1 na 2 i dowrotnie oraz podczas wyjscia z programu.
	void StartGame();///<Metoda z nieskoñczon¹ pêtl¹ rozgrywki.
	bool MenuMove(vector< vector<Piece*> > &_chessSquare);///<Metoda wykonuje ruch gracza.
	bool CheckCoordinates(string playerMove);///<Metoda sprawdza poprawnoœæ wprowadzonych wspó³rzêdnych podczas ruchu pionka np. a2-a3.
	///Metoda konwertuje wczytane wartoœci z klawiatury dla ruchu pionków na wartosci 0-7.
	void ConvertCoordinates(string  playerMove, int &currentRow, int &currentCol, int &destinationRow, int &destinationCol);
	void ChangeName();///<Metoda gdy jest wywo³ywana zmiena wartosc playerName: White/Black.
	int GetMenuOption();///<Getter zmiennej menuOption.
	void SetMenuOption(int _menuOption);///<Setter zmiennej menuOption.
	bool GameOver();///<Metoda sprawdza stan rozgrywki: wygrana/remis.
    ///Metoda sprawdza ruch pionka pod wzglêdem np. próby  przesuniêcia pustego pola lub zbicia w³asnego pionka.
	bool IsCoordinatesLegal(int currentRow, int currentCol, int destinationRow, int destinationCol, vector< vector<Piece*> > _chessSquare);
	///Metoda wykonuje ruch pionka na szachownicy.
	bool MakeMove(vector< vector<Piece*> > &_chessSquare, string _playerMove);
	GamePlay(string _playerName = "White") :playerName(_playerName) { menuOption = 0; }///<Konstruktor
	~GamePlay();///<Destruktor
};


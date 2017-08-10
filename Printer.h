#pragma once
#include <string>
#include <Windows.h>
#include <iostream>
#include <vector>
#include "Board.h"

/** Klasa Printer jest odpowiedzialna za drukowanie planszy szachownicy oraz wyswietlanie komunikat�w*/
class Printer
{
//private:
//	char displayBoard[40][90];///Tablica przechowuje znaki typu char, kt�re po wydrukowaniu wygl�daj� jak plansza szachownicy.

public:
	void PrintAskForMove(int _menuOption, string _playerName);///Metoda drukuje polecenie wykonanie ruchu lub wybrania opcji z Menu.
	void PrintMessage(int &_messageNumber);///Metoda drukuje wiadomo�ci na ekranie
	void PrintBoard(int _menuOption, vector< vector<Piece*> > _chessSquare);///Metoda drukuje plansze szachownicy.

	Printer();///<Konstruktor.
	~Printer();///<Destruktor.
};


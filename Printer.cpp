#include "Printer.h"

void Printer::PrintAskForMove(int _menuOption, string _playerName)
{
	/** Zmiana koloru tekstu na zielony.*/
	HANDLE uchwyt;
	uchwyt = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(uchwyt, 2);

	/** Spawdzenie, czy gra nie jest rozpoczêta.*/
	if (_menuOption == 0)
	{
		cout << endl << "Wybierz opcje z MENU (np. 1): ";
	}
	else cout << "Ruch gracza " << _playerName<<":";
}

void Printer::PrintMessage(int &_messageNumber)
{
	/** Zmiana koloru tekstu na czerwony.*/
	HANDLE uchwyt;
	uchwyt = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(uchwyt, 4);

	/** Sprawdzenie, któr¹ wiadomoœæ nale¿y wydrukowaæ.*/
	if (_messageNumber == 1)
	{
		cout << "Nalezy wybrac opcje z MENU!";
	}
	else if (_messageNumber == 2)
	{
		cout << "Szach Krola!" << endl << endl;
	}
	else if (_messageNumber == 3)
	{
		cout << "Wskazana figura nie moze ruszac sie w ten sposob!" << endl << endl;
	}
	else if (_messageNumber == 4)
	{
		cout << "Niepoprawne dane, wpisz jeszcze raz!" << endl << endl;
	}
	else if (_messageNumber == 5)
	{
		cout << "Nie mozesz przesunac pustego pola :)" << endl << endl;
	}
	else if (_messageNumber == 6)
	{
		cout << "Nie mozesz zajac wlasnego pionka. " << endl << endl;
	}
	else if (_messageNumber == 7)
	{
		cout << "Nie kontrolujesz pionkow przyciwnika! Wybierz swoj pionek." << endl << endl;
	}

	_messageNumber = 0;///Ustawienie wartoœci wyœwietlanej wiadomoœci na 0 - ¿adna wiadomoœæ nie zostanie wydrukowana.
}

void Printer::PrintBoard(int _menuOption, vector< vector<Piece*> > _chessSquare)
{
	HANDLE uchwyt;
	uchwyt = GetStdHandle(STD_OUTPUT_HANDLE);
	char displayBoard[40][90];///Tablica przechowuje znaki typu char, które po wydrukowaniu wygl¹daj¹ jak plansza szachownicy.
	/** Kopiowanie ci¹gu znaków do tablicy displayBoard[40][90].*/
	strncpy_s(displayBoard[0], "                                                                                     ", 90);
	strncpy_s(displayBoard[1], "      A     B     C     D     E     F     G     H                                    ", 90);
	strncpy_s(displayBoard[2], "   +-----+-----+-----+-----+-----+-----+-----+-----+   +----------------------------+", 90);
	strncpy_s(displayBoard[3], "   |     |*****|     |*****|     |*****|     |*****|   |                            |", 90);
	strncpy_s(displayBoard[4], " 8 |     |*****|     |*****|     |*****|     |*****| 8 |            MENU            |", 90);
	strncpy_s(displayBoard[5], "   |     |*****|     |*****|     |*****|     |*****|   |                            |", 90);
	strncpy_s(displayBoard[6], "   +-----+-----+-----+-----+-----+-----+-----+-----+   +----------------------------+", 90);
	strncpy_s(displayBoard[7], "   |*****|     |*****|     |*****|     |*****|     |   |                            |", 90);
	strncpy_s(displayBoard[8], " 7 |*****|     |*****|     |*****|     |*****|     | 7 | 1. Szachy                  |", 90);
	strncpy_s(displayBoard[9], "   |*****|     |*****|     |*****|     |*****|     |   | 2. Wirtualna Szachownica   |", 90);
	strncpy_s(displayBoard[10], "   +-----+-----+-----+-----+-----+-----+-----+-----+   | 3. Wyjscie                 |", 90);
	strncpy_s(displayBoard[11], "   |     |*****|     |*****|     |*****|     |*****|   |                            |", 90);
	strncpy_s(displayBoard[12], " 6 |     |*****|     |*****|     |*****|     |*****| 6 +----------------------------+", 90);
	strncpy_s(displayBoard[13], "   |     |*****|     |*****|     |*****|     |*****|                                 ", 90);
	strncpy_s(displayBoard[14], "   +-----+-----+-----+-----+-----+-----+-----+-----+                                 ", 90);
	strncpy_s(displayBoard[15], "   |*****|     |*****|     |*****|     |*****|     |                                 ", 90);
	strncpy_s(displayBoard[16], " 5 |*****|     |*****|     |*****|     |*****|     | 5                               ", 90);
	strncpy_s(displayBoard[17], "   |*****|     |*****|     |*****|     |*****|     |                                 ", 90);
	strncpy_s(displayBoard[18], "   +-----+-----+-----+-----+-----+-----+-----+-----+                                 ", 90);
	strncpy_s(displayBoard[19], "   |     |*****|     |*****|     |*****|     |*****|                                 ", 90);
	strncpy_s(displayBoard[20], " 4 |     |*****|     |*****|     |*****|     |*****| 4                               ", 90);
	strncpy_s(displayBoard[21], "   |     |*****|     |*****|     |*****|     |*****|                                 ", 90);
	strncpy_s(displayBoard[22], "   +-----+-----+-----+-----+-----+-----+-----+-----+                                 ", 90);
	strncpy_s(displayBoard[23], "   |*****|     |*****|     |*****|     |*****|     |                                 ", 90);
	strncpy_s(displayBoard[24], " 3 |*****|     |*****|     |*****|     |*****|     | 3                               ", 90);
	strncpy_s(displayBoard[25], "   |*****|     |*****|     |*****|     |*****|     |                                 ", 90);
	strncpy_s(displayBoard[26], "   +-----+-----+-----+-----+-----+-----+-----+-----+                                 ", 90);
	strncpy_s(displayBoard[27], "   |     |*****|     |*****|     |*****|     |*****|                                 ", 90);
	strncpy_s(displayBoard[28], " 2 |     |*****|     |*****|     |*****|     |*****| 2                               ", 90);
	strncpy_s(displayBoard[29], "   |     |*****|     |*****|     |*****|     |*****|                                 ", 90);
	strncpy_s(displayBoard[30], "   +-----+-----+-----+-----+-----+-----+-----+-----+                                 ", 90);
	strncpy_s(displayBoard[31], "   |*****|     |*****|     |*****|     |*****|     |                                 ", 90);
	strncpy_s(displayBoard[32], " 1 |*****|     |*****|     |*****|     |*****|     | 1                               ", 90);
	strncpy_s(displayBoard[33], "   |*****|     |*****|     |*****|     |*****|     |                                 ", 90);
	strncpy_s(displayBoard[34], "   +-----+-----+-----+-----+-----+-----+-----+-----+                                 ", 90);
	strncpy_s(displayBoard[35], "                                                                                     ", 90);
	strncpy_s(displayBoard[36], "      A     B     C     D     E     F     G     H                                    ", 90);
	strncpy_s(displayBoard[37], "                                                                      ChessGame v.1.0", 90);

	/** Sprawdzenie stanu gry.*/
	if (_menuOption == 1)
	{
		strncpy_s(displayBoard[8], " 7 |*****|     |*****|     |*****|     |*****|     | 7 | 1. Restart                 |", 90);
		strncpy_s(displayBoard[16]," 5 |*****|     |*****|     |*****|     |*****|     | 5      Przyklad: a2-a3          ", 90);
	}
	else if (_menuOption == 2)
	{
		strncpy_s(displayBoard[9], "   |*****|     |*****|     |*****|     |*****|     |   | 2. Restart                 |", 90);
		strncpy_s(displayBoard[16]," 5 |*****|     |*****|     |*****|     |*****|     | 5      Przyklad: bk-a3          ", 90);
		strncpy_s(displayBoard[19],"   |     |*****|     |*****|     |*****|     |*****|        Wpisz -ready, gdy gotowe.", 90);
	}

	int displayRow[8] = { 4,8,12,16,20,24,28,32 }; ///Tablica zmiennych przechowuje numery wierszy w których nale¿y wydrukowaæ nazwy figur.
	int displayCol[8] = { 6,12,18,24,30,36,42,48 };///Tablica zmiennych przechowuje numery kolumn w których nale¿y wydrukowaæ nazwy figur.

	/** Zmienne przechowuj¹ tymczasowo zmienne z tablic displayRow i displayCol.*/
	int tRow = 0;
	int tCol = 0;

	/** Sprawdzanie ka¿dego pola tablicy _chessSquare*/
	for (int iRow = 0; iRow < 8; iRow++)
	{
		tRow = displayRow[iRow];
		for (int iCol = 0; iCol < 8; iCol++)
		{
			tCol = displayCol[iCol];
			/** Sprawdzanie czy pole jest puste*/
			if (_chessSquare[iRow][iCol] == 0)
			{
				/** Uzupelnienie tablicy displayBoard znakami '*' oraz ' ' */
				if ((tRow % 8 != 0) && (tCol % 12 == 0)) displayBoard[tRow][tCol] = '*';
				else if ((tRow % 8 == 0) && (tCol % 12 != 0)) displayBoard[tRow][tCol] = '*';
				else displayBoard[tRow][tCol] = ' ';
			}
			/** Uzupelnienie tablicy displayBoard znakami odpowiadaj¹cymi figurom, które znajduj¹ sie na danym polu */
			else if (_chessSquare[iRow][iCol]->GetPieceName() == 'P') displayBoard[tRow][tCol] = 'P';
			else if (_chessSquare[iRow][iCol]->GetPieceName() == 'K') displayBoard[tRow][tCol] = 'K';
			else if (_chessSquare[iRow][iCol]->GetPieceName() == 'N') displayBoard[tRow][tCol] = 'N';
			else if (_chessSquare[iRow][iCol]->GetPieceName() == 'R') displayBoard[tRow][tCol] = 'R';
			else if (_chessSquare[iRow][iCol]->GetPieceName() == 'B') displayBoard[tRow][tCol] = 'B';
			else if (_chessSquare[iRow][iCol]->GetPieceName() == 'Q') displayBoard[tRow][tCol] = 'Q';
		}
	}

	/** Drukowanie tablicy displayBoard */
	for (int iRow = 0; iRow<38; iRow++)
	{
		tRow = (iRow / 4) - 1;
		for (int iCol = 0; iCol < 86; iCol++)
		{
			tCol = (iCol / 6) - 1;
			if ((iRow > 3) && (iCol>5) && (iRow % 4 == 0) && (iCol % 6 == 0) && (iRow <= 32) && (iCol <= 48) && (_chessSquare[tRow][tCol] != 0))
			{
				if (_chessSquare[tRow][tCol]->GetPieceColor() == 'B')
				{
					SetConsoleTextAttribute(uchwyt, 4);
					cout << displayBoard[iRow][iCol];
					SetConsoleTextAttribute(uchwyt, 7);
				}
				else
				{
					SetConsoleTextAttribute(uchwyt, 6);
					cout << displayBoard[iRow][iCol];
					SetConsoleTextAttribute(uchwyt, 7);
				}
			}
			else
			{
				SetConsoleTextAttribute(uchwyt, 7);
				cout << displayBoard[iRow][iCol];
			}
		}
		cout << endl;
	}
}


Printer::Printer()
{
}


Printer::~Printer()
{
}

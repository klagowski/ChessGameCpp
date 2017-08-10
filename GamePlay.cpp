#include "GamePlay.h"

using namespace std;

void GamePlay::AskForPieceVirtualChessBoard()
{
	system("cls");
	ChessBoardPrint.PrintBoard(menuOption, ChessBoard.chessSquare);
	string setPieceData;

	do
	{
		cout << "Umiesc pionek na szachownicy: ";
		cin >> setPieceData;
		transform(setPieceData.begin(), setPieceData.end(), setPieceData.begin(), ::tolower);

		if (CheckPieceForVirtualChessBoard(setPieceData))
		{
			int destinationRow, destinationCol;
			char pieceColor, pieceType;
			ConvertPieceDataForVirtualChessBoard(setPieceData, destinationRow, destinationCol, pieceColor, pieceType);
			ChessBoard.SetPieceVirtualChessBoard(destinationRow, destinationCol, pieceColor, pieceType, ChessBoard.chessSquare);
			system("cls");
			ChessBoardPrint.PrintBoard(menuOption, ChessBoard.chessSquare);
		}
		else cout << "Niepoprawne dane! " << endl << endl;
	} while (setPieceData!="-ready");
	SetMenuOption(1);
}

bool GamePlay::CheckPieceForVirtualChessBoard(string _setPieceData)
{
	///Sprawdzenie, czy wczytany string ma dlugosc rowna 5.
	if (_setPieceData.length() != 5) return false;
	///Sprawdzenie, czy trzeci znak jest "-".
	else if ((int)_setPieceData[2] != 45) return false;
	///Sprawdzenie, czy 4 znak jest z zakresu a-g.
	else if ((int)_setPieceData[3] < 97 || (int)_setPieceData[3]>104) return false;
	///Sprawdzenie, czy 4 znak jest z zakresu 1-8.
	else if ((int)_setPieceData[4] < 49 || (int)_setPieceData[4]>56) return false;
	///Sprawdzenie 0 i 1 znaku.
	else if ((_setPieceData[0] == 'w' || _setPieceData[0] =='b') && (_setPieceData[1] == 'k' || _setPieceData[1] == 'q' || _setPieceData[1] == 'r' || _setPieceData[1] == 'b' || _setPieceData[1] == 'n' || _setPieceData[1] == 'p')) return true;

	else return false;
}

void GamePlay::ConvertPieceDataForVirtualChessBoard(string _setPieceData, int &_destinationRow, int &_destinationCol, char &_pieceColor, char &_pieceType)
{
	
	for (size_t i = 3; i <= _setPieceData.size(); i++) //konwersja do asci
	{
		if (i == 3)
		{
			_destinationCol = (int)_setPieceData[i] - 97;
		}
		else if (i == 4)
		{
			for (int j = 0; j < 8; j++)
			{
				if (_setPieceData[i] - 49 == j) { _destinationRow = 7 - j; };
			}
		}
	}
	transform(_setPieceData.begin(), _setPieceData.end(), _setPieceData.begin(), ::toupper);
	_pieceColor = _setPieceData[0];
	_pieceType = _setPieceData[1];
}

void GamePlay::SetMessageNumber(int _messageNumber)
{
	messageNumber = _messageNumber;
}

bool GamePlay::AreYouSure()
{
	char playerCommand;
	cout << "Jestes pewien? (Y/N): ";
	do
	{
		cin >> playerCommand;
		if (playerCommand == 'y' || playerCommand == 'Y')
		{
			return true;
		}
		else if (playerCommand == 'n' || playerCommand == 'N') 
		{  
			return false; 
		}
		else
		{
			cout << "Y/N: ";
		}
	} while (playerCommand != 'y'&& playerCommand != 'Y' && playerCommand != 'n' && playerCommand != 'N');
	return false;
}

void GamePlay::StartGame()
{
	ChessBoardPrint.PrintBoard(menuOption, ChessBoard.chessSquare);
	SetMessageNumber(0);
	SetMenuOption(0);
	while(true)
	{
		if (GetMenuOption() == 1 || GetMenuOption() == 2)GameOver();
		
		ChessBoardPrint.PrintMessage(messageNumber);
		ChessBoardPrint.PrintAskForMove(menuOption, playerName);

		if (MenuMove(ChessBoard.chessSquare))
		{
			system("cls");
			ChessBoardPrint.PrintBoard(menuOption, ChessBoard.chessSquare);
		}
	}
}

bool GamePlay::MenuMove(vector< vector<Piece*> > &_chessSquare)
{
	string playerMove;
	cin >> playerMove;
	transform(playerMove.begin(), playerMove.end(), playerMove.begin(), ::tolower);

	
	///Wybranie typy rogrywki: Szachy.
	if (playerMove[0] == '1')
	{
		if (GetMenuOption() == 1)
		{
			if(AreYouSure())
			{
				SetMenuOption(1);
				ChessBoard.SetPieceStandartChessBoard();
				playerName = "White";
				return true;
			}
		}
		else if (GetMenuOption() == 0)
		{
			SetMenuOption(1);
			ChessBoard.SetPieceStandartChessBoard();
			playerName = "White";
			return true;
		}
	}
	///Wybranie typu rogrywki: Wirtualna Szachownica.
	else if (playerMove[0] == '2')
	{
		if (GetMenuOption() == 1)
		{
			if (AreYouSure())
			{
				ChessBoard.ResetBoard();
				SetMenuOption(2);
				AskForPieceVirtualChessBoard();
				playerName = "White";
				return true;
			}
		}
		else if (GetMenuOption() == 0)
		{
			ChessBoard.ResetBoard();
			SetMenuOption(2);
			AskForPieceVirtualChessBoard();
			playerName = "White";
			return true;
		}
	}
	///Wyjœcie z programu exit(0).
	else if (playerMove[0] == '3')
	{
		if(AreYouSure())exit(0);	
	}
	///Wykoanie ruchu pionkiem.
	else if (CheckCoordinates(playerMove))
	{
		MakeMove(ChessBoard.chessSquare, playerMove);
	}
	else
	{
		SetMessageNumber(4);
		return false;
	}
	return true;
}

bool GamePlay::CheckCoordinates(string playerMove)
{
	if (playerMove.length() != 5) return false;

	if (((int)playerMove[0]< 97 || (int)playerMove[0]>104)) return false;

	else if ((int)playerMove[1] < 49 || (int)playerMove[1]>56) return false;
	
	else if ((int)playerMove[2] != 45) return false;
	
	else if ((int)playerMove[3] < 97 || (int)playerMove[3]>104) return false;
	
	else if ((int)playerMove[4] < 49 || (int)playerMove[4]>56) return false;

	else if ((int)playerMove[0] == (int)playerMove[3] && (int)playerMove[1] == (int)playerMove[4]) return false;

	else return true;
}

void GamePlay::ConvertCoordinates(string playerMove, int &currentRow, int &currentCol, int &destinationRow, int &destinationCol)
{
		for (size_t i = 0; i <= playerMove.size(); i++) 
		{
			if (i == 0)
			{
				currentCol = (int)playerMove[i] - 97;
			}
			else if (i == 1)
			{
				for (int j = 0; j < 8; j++)
				{
					if (playerMove[i] - 49 == j) { currentRow = 7 - j; };
				}
			}
			else if ( i == 3)
			{
				destinationCol = (int)playerMove[i] - 97;
			}
			else if (i == 4)
			{
				for (int j = 0; j < 8; j++)
				{
					if (playerMove[i] - 49 == j) { destinationRow = 7 - j; };
				}
			}
	}
}

void GamePlay::ChangeName()
{
	playerName = (playerName == "White" ? "Black" : "White");
}

int GamePlay::GetMenuOption()
{
	return menuOption;
}

void GamePlay::SetMenuOption(int _menuOption)
{
	menuOption = _menuOption;
}

bool GamePlay::GameOver()
{
		///Sprawdzenie, czy pionki mog¹ wykonaæ ruch.
		if (!ChessBoard.CanPieceMove(playerName)) 
		{
			///Sprawdzenie, czy Król jest szachowny.
			if (ChessBoard.IsKingInCheck(playerName))
			{
				SetMessageNumber(0);
				SetMenuOption(0);
				ChangeName();
				cout << "Szach-mat, " << playerName << " wygrywa!!!" << endl;
			} 
			else
			{
				SetMessageNumber(0);
				SetMenuOption(0);
				cout << "Remis!" << endl;
			}
		}
		return !ChessBoard.CanPieceMove(playerName);
}
	
bool GamePlay::IsCoordinatesLegal(int currentRow, int currentCol, int destinationRow, int destinationCol, vector<vector<Piece*>> _chessSquare)
{
	///Sprawdzenie, czy gracz nie chce przesun¹æ pustego pola.
	if (_chessSquare[currentRow][currentCol] == 0)
	{
		SetMessageNumber(5);
		return false;
	}
	///Sprawdzenie, czy gracz nie chce zbiæ w³asnego pionka.
	else if (_chessSquare[destinationRow][destinationCol] != 0)
	{
		if (_chessSquare[destinationRow][destinationCol]->GetPieceColor() == playerName[0])
		{
			SetMessageNumber(6);
			return false;
		}
		else return true;
	}
	///Sprawdzenie, czy gracz nie chce przesun¹æ pionka przeciwnika.
	else if (_chessSquare[currentRow][currentCol] != 0)
	{
		if (_chessSquare[currentRow][currentCol]->GetPieceColor() != playerName[0])
		{
			SetMessageNumber(7);
			return false;
		}
		else return true;
	}
	return true;
}

bool GamePlay::MakeMove(vector<vector<Piece*>>& _chessSquare,string _playerMove)
{
	int currentRow = 0, currentCol = 0, destinationRow = 0, destinationCol = 0;
	ConvertCoordinates(_playerMove, currentRow, currentCol, destinationRow, destinationCol);
	if (IsCoordinatesLegal(currentRow, currentCol, destinationRow, destinationCol, _chessSquare))
	{
		if (_chessSquare[currentRow][currentCol]->MoveRules(currentRow, currentCol, destinationRow, destinationCol, _chessSquare))
		{
			Piece* TempPiece = _chessSquare[destinationRow][destinationCol];
			_chessSquare[destinationRow][destinationCol] = _chessSquare[currentRow][currentCol];
			_chessSquare[currentRow][currentCol] = 0;
			if (!ChessBoard.IsKingInCheck(playerName))
			{
				delete TempPiece;
				ChangeName();
				return true;
			}
			else
			{
				_chessSquare[currentRow][currentCol] = _chessSquare[destinationRow][destinationCol];
				_chessSquare[destinationRow][destinationCol] = TempPiece;
				SetMessageNumber(2);
			}
		}
		else
		{
			SetMessageNumber(3);
			return false;
		}
	}
	return false;
}


GamePlay::~GamePlay()
{
}

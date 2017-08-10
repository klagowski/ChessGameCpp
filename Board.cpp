#include <iostream>
#include <Windows.h>
#include <vector>
#include <string>
#include <algorithm> 
#include "Board.h"

using namespace std;

void Board::SetPieceStandartChessBoard()
{
	ResetBoard();///<Uzupelnia tablice chessSquare zerami.
	
	/** Umiescowienie bia³ych pionków na planszy*/
	chessSquare[7][4] = new King('W');
	chessSquare[7][1] = new Knight('W');
	chessSquare[7][6] = new Knight('W');
	chessSquare[7][0] = new Rook('W');
	chessSquare[7][7] = new Rook('W');
	chessSquare[7][2] = new Bishop('W');
	chessSquare[7][5] = new Bishop('W');
	chessSquare[7][3] = new Queen('W');
	for (int iCol = 0; iCol < 8; iCol++)
	{
		chessSquare[6][iCol] = new Pawn('W');
	}
	/** Umiescowienie czarnych pionków na planszy*/
	chessSquare[0][4] = new King('B');
	chessSquare[0][1] = new Knight('B');
	chessSquare[0][6] = new Knight('B');
	chessSquare[0][0] = new Rook('B');
	chessSquare[0][7] = new Rook('B');
	chessSquare[0][2] = new Bishop('B');
	chessSquare[0][5] = new Bishop('B');
	chessSquare[0][3] = new Queen('B');
	for (int iCol = 0; iCol < 8; iCol++)
	{
		chessSquare[1][iCol] = new Pawn('B');
	}
}

void Board::ResetBoard()
{
	for (auto &it : chessSquare)
	fill(it.begin(), it.end(), nullptr);
}

void Board::SetPieceVirtualChessBoard(int _destinationRow, int _destinationCol, char _pieceColor, char _pieceType, vector<vector<Piece*>> _chessSquare)
{
	if (_pieceType=='K') chessSquare[_destinationRow][_destinationCol] = new King(_pieceColor);
	else if (_pieceType == 'Q') chessSquare[_destinationRow][_destinationCol] = new Queen(_pieceColor);
	else if (_pieceType == 'R') chessSquare[_destinationRow][_destinationCol] = new Rook(_pieceColor);
	else if (_pieceType == 'B') chessSquare[_destinationRow][_destinationCol] = new Bishop(_pieceColor);
	else if (_pieceType == 'N') chessSquare[_destinationRow][_destinationCol] = new Knight(_pieceColor);
	else if (_pieceType == 'P') chessSquare[_destinationRow][_destinationCol] = new Pawn(_pieceColor);
}

bool Board::CanPieceMove(string _playerName)
{
	/** Sprawdzenie wszytkich pionków czy mog¹ wykonaæ ruch.*/
	for (int iRow = 0; iRow < 8; iRow++)
	{
		for (int iCol = 0; iCol < 8; iCol++)
		{
			if (chessSquare[iRow][iCol] != 0)
			{
				/** Sprawdzenie, cz pionki gracza mog¹ wykonaæ ruch zgodny z zasadami.*/
				if (chessSquare[iRow][iCol]->GetPieceColor() == _playerName[0])
				{
					for (int iMoveRow = 0; iMoveRow < 8; iMoveRow++)
					{
						for (int iMoveCol = 0; iMoveCol < 8; iMoveCol++)
						{
							if (chessSquare[iMoveRow][iMoveCol] == 0 || chessSquare[iMoveRow][iMoveCol]->GetPieceColor() != _playerName[0])
							{
								if (chessSquare[iRow][iCol]->MoveRules(iRow, iCol, iMoveRow, iMoveCol, chessSquare))
								{
									/** Wykonanie ruchu i sprawdzenie czy Król jest szachowany.*/
									Piece* TempPiece = chessSquare[iMoveRow][iMoveCol];
									chessSquare[iMoveRow][iMoveCol] = chessSquare[iRow][iCol];
									chessSquare[iRow][iCol] = 0;
									bool bTemp = !IsKingInCheck(_playerName);
									/** Cofniêcie ruchu.*/
									chessSquare[iRow][iCol] = chessSquare[iMoveRow][iMoveCol];
									chessSquare[iMoveRow][iMoveCol] = TempPiece;
									if (bTemp)
									{
										return true;
									}
								}
							}
						}
					}
				}
			}
		}
	}
	return false;
}

bool Board::IsKingInCheck(string _playerName)
{
	/** Zmienne przechowuj¹ce po³oŸenie Króla*/
	int kingRow;
	int kingCol;

	bool IsThereKing = false;///<Wartoœc logiczna przyjmuj¹ca true, gdy Król zostanie znaleziony.

	/** Szukanie Króla*/
	for (int iRow = 0; iRow < 8; iRow++)
	{
		for (int iCol = 0; iCol < 8; iCol++)
		{
			if (chessSquare[iRow][iCol] != 0)
			{
				if (chessSquare[iRow][iCol]->GetPieceColor() == _playerName[0])
				{
					if (chessSquare[iRow][iCol]->GetPieceName() == 'K')
					{
						IsThereKing = true;
						kingRow = iRow;
						kingCol = iCol; 
					}
				}
			}
		}
	}
	
	/** Sprawdzenie, czy pionki oponenta mog¹ zbiæ Króla*/
	if (IsThereKing)
	{
		for (int iRow = 0; iRow < 8; iRow++)
		{
			for (int iCol = 0; iCol < 8; iCol++)
			{
				if (chessSquare[iRow][iCol] != 0)
				{
					if (chessSquare[iRow][iCol]->GetPieceColor() != _playerName[0])
					{
						if (chessSquare[kingRow][kingCol]->GetPieceColor() == _playerName[0] || chessSquare[kingRow][kingCol] == 0)
						{
							if (chessSquare[iRow][iCol]->MoveRules(iRow, iCol, kingRow, kingCol, chessSquare))
							{
								return true;
							}
						}
					}
				}
			}
		}
	}
	return false;
}

/** Deklaracja tablicy chessSquare o wielkoœci 8x8 i uzupelnienie jej zerami.*/
Board::Board() :chessSquare(8, vector<Piece*>(8, 0)) {};
		
Board::~Board()
{
	chessSquare.clear();///<Usuniêcie obiektów klasy Piece.
}

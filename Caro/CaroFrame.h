#pragma once
#include "data.h"
#include "view.h"
#include "model.h"
void ClearMatrix();
bool Check_Win(const char symbol);
void HandleKeyForBoard(int x, int y, KEY_EVENT_RECORD key);
void HandleKeyForBoardBot(int x, int y, KEY_EVENT_RECORD key);
void DrawBoard(int pSize);
void ClearBoard(int pSize);
void RemoveLogoFrame();
void DrawInforFrame();
void DrawLogoFrame();
void DrawLogoHcmus();
void DrawWin(int n);
void DrawAvatarBattle(int player1, int player2);
void RemoveScore();
void DrawScore(int player1, int player2);
void DrawTurn(int n);
void DrawSaveAndContinue();
void HandleKeyForSaveGame(int x, int y, KEY_EVENT_RECORD key);
void SaveInforFile(string FileName);
void SaveNameFile();
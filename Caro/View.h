#pragma once
#ifndef VIEW_H
#define VIEW_H

#pragma once
#include "data.h"

void FixConsoleWindow();
void SetWindowSize(int width, int height);
void CreateConsoleWindow(int width, int height);
void ShowScrollbar(bool Show);
void GotoXY(int x, int y);
void DrawBoard(int pSize);
void SetFont(const wchar_t name[], int size);
void ShowCur(bool CursorVisibility);
void PrintTextColor(const wstring& s, const int& color);
void MainMenu();
void DrawChangeSetting(int x, int y);
void Music_Mode(int i);
void Sound_Mode(int i);
void TextColor(int color);
void PrintTextColor_Char(const char& s, const int& color);
#endif


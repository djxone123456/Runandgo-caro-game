#pragma once
#ifndef VIEW_H
#define VIEW_H

#include "data.h"

void CreateConsoleWindow(int width, int height);
void GotoXY(int x, int y);
void DrawBoard(int pSize);
void ShowCur(bool CursorVisibility);
void PrintTextColor(const wstring& s, const int& color);
void PrintTextColor(const string& s, const int& color);
void PrintTextColor_Char(const char& s, const int& color);
void TextColor(int color);
#endif


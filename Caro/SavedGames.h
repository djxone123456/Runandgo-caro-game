#pragma once
#ifndef SAVEDGAMES_H
#define SAVEDGAMES_H
#include "LoadData.h"

struct Load
{
	string NamePL1;
	string NamePL2;
	int Point_1;
	int Point_2;
	int Draw;
	string Character_1;
	string Character_2;
	int Result;// 0 - chua xong; 1 - xong r -> van moi
	string Turn; // x - o
	char Table[16 * 16];// bang
};

//function
void DrawSavedBoard();
void DrawButton();
void PrintFileName(string Name[]);
void LoadGame(Load& File, string Name);
void HandleKeyForLoad(int x, int y, KEY_EVENT_RECORD key);
void PrintFirstFileInfo();
void DeleteInfo();

#endif

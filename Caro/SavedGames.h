#pragma once
#ifndef SAVEDGAMES_H
#define SAVEDGAMES_H
#include "loadData.h"

struct Load
{
	string NamePL1;
	string NamePL2;
	int Point_1;
	int Point_2;
	int Draw;
	int Character_1;
	int Character_2;
	int Result;// 0 - not one; 1 - finished -> new game
	int Turn; // x - o
	char Table[BOARD_SIZE * BOARD_SIZE];// board
};

//function
void DrawSavedBoard();
void DrawButton();
void PrintFileName(string Name[]);
void LoadGame(Load& File, string Name);
void HandleKeyForLoad(int x, int y, KEY_EVENT_RECORD key);
void DeleteInfo();

#endif
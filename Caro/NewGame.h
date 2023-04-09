#pragma once
#ifndef NEWGAME_H
#define NEWGAME_H

#include "Control.h"
#include "View.h"
#include "Data.h"
#include "D2_data.h"
#include "Store.h"

#define D3_NewGame_Box_Left 43
#define D3_NewGame_Box_Top 12
#define D3_NewGame_Box_Max_i 82
#define D3_NewGame_Box_Max_j 35
#define D3_Vertical_Thick_Line char(219)
#define D3_Upper_Horizontal_Thick_Line char(223)
#define D3_Lower_Horizontal_Thick_Line char(220)
#define D3_Left_Arrow char(17)
#define D3_Right_Arrow char(16)
#define D3_Vertical_Button_Line char(186)
#define D3_Horizontal_Button_Thin_Line char(196)
#define D3_Horizontal_Button_Double_Line char(205)
#define D3_Upper_Left_Corner_Button_Line char(214)
#define D3_Upper_Right_Corner_Button_Line char(183)
#define D3_Lower_Left_Corner_Button_Line char(200)
#define D3_Lower_Right_Corner_Button_Line char(188)

const string D3_NewGame_Mode[] = { "Play with Robot", "Play with Human" };
extern int D3_GameMode;
extern int D3_Y2;

int NewGame();
void HandleKeyForNewGame(int D3_X, int D3_Y, KEY_EVENT_RECORD key);
void D3_EraseConsole(int x1, int x2, int y1);

#endif


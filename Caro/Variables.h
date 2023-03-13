#pragma once
#include "Data.h"

//Global Variables
_POINT _A[BOARD_SIZE][BOARD_SIZE];
bool _TURN;
int _COMMAND;
int _X = FIRST_CELL_X, _Y = FIRST_CELL_Y;

//Menu Control
bool _KEYPRESSED = 0;
int _MENU = 1;
int _CURRENT_MENU = 0;

//Main Menu
int DEFAULT_X = 80;
int DEFAULT_Y = 22;

// Setting
int music_mode = 1;
int sound_mode = 1;
int _SETTING = 0;
int _Y_Set = STop + 5;
#ifndef DATA_H
#define DATA_H

#pragma once
#pragma comment(lib, "winmm.lib")

//Library
#include <iostream>
#include <windows.h>
#include <fstream>
#include <string>
#include <io.h>
#include <fcntl.h>
#include <conio.h>
#include <stdio.h>

//Namespace
using std::cout;
using std::cin;
using std::string;
using std::wcout;
using std::wstring;

//Game Data
#define BOARD_SIZE 15
#define LEFT 5 
#define TOP 5 
#define FIRST_CELL_X LEFT + 2
#define FIRST_CELL_Y TOP + 1

//Console size
#define HEIGHT 720
#define WIDTH 1280

//ASCII Code For Board (Single Line)
//#define VERTICAL_LINE char(179)
//#define HORIZONTAL_LINE char(196)
//#define RIGHT_TOP char(191)
//#define RIGHT_BOTTOM char(217)
//#define LEFT_TOP char(218)
//#define LEFT_BOTTOM char(192)
//#define T_SHAPE_UP char(193)
//#define T_SHAPE_DOWN char(194)
//#define T_SHAPE_RIGHT char(195)
//#define T_SHAPE_LEFT char(180)
//#define CROSS char(197)

//ASCII Code For Board (Double Line)
#define VERTICAL_LINE char(186)
#define HORIZONTAL_LINE char(205)
#define RIGHT_TOP char(187)
#define RIGHT_BOTTOM char(188)
#define LEFT_TOP char(201)
#define LEFT_BOTTOM char(200)
#define T_SHAPE_UP char(202)
#define T_SHAPE_DOWN char(203)
#define T_SHAPE_RIGHT char(204)
#define T_SHAPE_LEFT char(185)
#define CROSS char(206)

//ASCII Code For Selected Part Of The Menu
#define SELECTED_LEFT char(175)
#define SELECTED_RIGHT char(174)

// ASCII Code For Box
#define Horizontal_Line char(219)
#define Upper_Vertical char(223)
#define Lower_Vertical char(220)

// Menu's Box Data
#define BMax_i 85
#define BMax_j 35
#define BLeft 43
#define BTop 19

// Help Data
#define HLeft 43
#define HTop 5
#define HMax_i 82
#define HMax_j 36
#define Left_Arrow char(17)
#define Right_Arrow char(16)
#define Up_Arrow char(30)
#define Down_Arrow char(31)

//Setting Data
#define SLeft 43
#define STop 9
#define SMax_i 82
#define SMax_j 32

// Info data
#define ILeft 43
#define ITop 5
#define IMax_i 82
#define IMax_j 36

struct _POINT {
	int x, y, c;
};

//Global Variables
extern _POINT _A[BOARD_SIZE][BOARD_SIZE];
extern bool _TURN;
extern int _COMMAND;
extern int _X, _Y;

//Menu Control
extern bool _KEYPRESSED;
extern int _MENU;
extern int _CURRENT_MENU;

//Main Menu
extern int DEFAULT_X;
extern int  DEFAULT_Y;

//Setting
extern int music_mode;
extern int sound_mode;
const string mode[] = { "Off", "On" };
extern int _SETTING;
extern int _Y_Set;

#endif
#pragma once
#ifndef MAINMENU_H
#define MAINMENU_H

#include "Control.h"
#include "View.h"
#include "Data.h"
#include "Error.h"
#include "Help.h"
#include "Settings.h"
#include "About.h"
#include "Ranking.h"

//DEFINES
#define D1_Left_Arrow char(17)
#define D1_Right_Arrow char(16)
static const int D1_MenuItems = 6;

//VARIABLES
static int CurrentPoint = 0;

//FUNCTIONS HERE
static void Logo();
static void MenuDefault();
static void DrawCursor(int, int);
static void EraseCursor(int, int);
static void DrawButton(int, int, int, int);
static void DrawMenuBorder(int, int, int, int);
static void DeleteButton(int, int, int, int);
static void MenuLogo(int, int);
static void MenuFrame();
void HandleKeyForMainMenu(int, int, KEY_EVENT_RECORD);
int MainMenu();

#endif

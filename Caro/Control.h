#pragma once
#ifndef CONTROL_H
#define CONTROL_H

#include "data.h"
#include "view.h"
#include "model.h"

#include "Error.h"
#include "Help.h"
#include "Settings.h"
#include "MainMenu.h"  // This is the main header for Dev 1
#include "Store.h"  // This is the main header for Dev 2
#include "NewGame.h" // This is the main header for Dev 3
#include "SavedGames.h"  // This is the main header for Dev 4
#include "CaroFrame.h" // This is the main header for Dev 5
#include "Ranking.h"
#include "About.h"

void StartGame();
void HandleKeyForBoard(int x, int y, KEY_EVENT_RECORD key);
void HandleEvent(int x, int y, void(*func)(int, int, KEY_EVENT_RECORD));
void Exit();
void ControlMenu();

#endif
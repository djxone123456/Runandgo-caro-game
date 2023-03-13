#pragma once
#ifndef CONTROL_H
#define CONTROL_H
#pragma once

#include "data.h"
#include "view.h"
#include "model.h"

void StartGame();
void HandleKeyForBoard(int x, int y, KEY_EVENT_RECORD key);
void HandleKeyForMainMenu(int X, int Y, KEY_EVENT_RECORD key);
void HandleKeyForHelp(int X, int Y, KEY_EVENT_RECORD key);
void HandleKeyForSetting(int x, int y, KEY_EVENT_RECORD key);
void HandleKeyForInfo(int X, int Y, KEY_EVENT_RECORD key);
void HandleEvent(int x, int y, void(*func)(int, int, KEY_EVENT_RECORD));
void Exit();
void ControlMenu();
void Music_Control();

#endif
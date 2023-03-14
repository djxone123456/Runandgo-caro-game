#pragma once
#ifndef CONTROL_H
#define CONTROL_H

#include "data.h"
#include "view.h"
#include "model.h"
#include "NewGame.h"
#include "Store.h"

void StartGame();
void HandleKeyForBoard(int x, int y, KEY_EVENT_RECORD key);
void HandleKeyForInfo(int X, int Y, KEY_EVENT_RECORD key);
void HandleEvent(int x, int y, void(*func)(int, int, KEY_EVENT_RECORD));
void Exit();
void ControlMenu();

#endif
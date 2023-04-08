#pragma once
#ifndef STORE_H
#define STORE_H
#include "D2_data.h"
#include "NewGame.h"

//FUNCTIONS
void HandleKeyForChoosingChar(int x, int y, KEY_EVENT_RECORD key);
int Store();
void PrintCharacter(int code, int _x, int _y);

#endif
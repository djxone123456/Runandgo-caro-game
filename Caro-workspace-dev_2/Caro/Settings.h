#pragma once
#ifndef SETTING_H
#define SETTING_H
#include "D2_data.h"

//FUNCTIONS
int Setting();
void HandleKeyForSettings(int x, int y, KEY_EVENT_RECORD key);
void BackgroundMusic();
int ImportSettings();
int ExportSettings();

#endif

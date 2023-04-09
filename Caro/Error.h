#pragma once
#ifndef ERROR_H
#define ERROR_H

#include "Control.h"
#include "View.h"
#include "Data.h"
#include "Error.h"

//FUNCTIONS HERE
static void AllignCenterString(const D1_POINT);
static void AllignCenterWString(const D1_POINT);
static void CreateFrame(int, int, int, int);
static void DeleteFrame(int, int, int, int);
void HandleKeyForError(int, int, KEY_EVENT_RECORD);
int ErrorPopUp(const int);

#endif
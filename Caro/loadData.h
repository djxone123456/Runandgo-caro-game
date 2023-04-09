#pragma once
#ifndef LOADDATA_H
#define LOADDATA_H

#include "Data.h"
#include "Control.h"
#include "View.h"
#include "Error.h"

//Name file position
extern int Name_X;
extern int Name_Y;

//File Info possition
extern int Info_X;
extern int Info_Y;

extern int Locate;
//ten file can load
extern string Name[10];

// So file da luu
extern int Numb_of_file;

//Process to update saved files
extern bool isLoadFile;
extern string loadedFileName;

#endif
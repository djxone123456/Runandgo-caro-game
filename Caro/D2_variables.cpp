#include "D2_data.h"

//TYPE NAME & CHOOSE CHARACTER VARIABLES
int D2_PLAYER = 1;
string D2_PLAYER01_NAME = "";
string D2_PLAYER02_NAME = "Mega Roboto";
int D2_PLAYER01_CHARACTER = 1;
int D2_PLAYER02_CHARACTER = 1;

//SETTINGS
int D2_BACKGROUND_MUSIC;
int D2_INGAME_MUSIC;
int D2_WHICH_SETTING = 0;
 
//BOARD
int Turn = 0;
int Score1 = 0;
int Score2 = 0;
int Draw = 0;
int Temp = 0;
int Finish = 1; //1 finished
int Count = 0;
string FileName = "";
char _MATRIX[BOARD_SIZE][BOARD_SIZE]{};

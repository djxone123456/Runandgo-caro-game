#include "Data.h"

//Global Variables
_POINT _A[BOARD_SIZE][BOARD_SIZE];
bool _TURN;
int _COMMAND;
int _X = FIRST_CELL_X, _Y = FIRST_CELL_Y;

//Menu Control
bool _KEYPRESSED = 0;
int _MENU = 1;
int _CURRENT_MENU = 0;

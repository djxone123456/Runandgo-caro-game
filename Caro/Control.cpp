#include "Control.h"
#include "View.h"

//Start Game
void StartGame() {
	system("cls");
	ResetData();
	DrawBoard(BOARD_SIZE);
}

//Handle key for the chess board
void HandleKeyForBoard(int x, int y, KEY_EVENT_RECORD key) {
	if (key.bKeyDown) //Key pressed
	{
		switch (key.wVirtualKeyCode)
		{
		case VK_RETURN: //Enter
			cout << "X";
			ShowCur(0);
			break;
		case VK_ESCAPE: //Esc
			break;
		case VK_LEFT: case 0x41: //Left arrow
			ShowCur(1);
			if (_X == FIRST_CELL_X) {
				_X += (BOARD_SIZE - 1) * x;
				GotoXY(_X, _Y);
			}
			else {
				GotoXY(_X - x, _Y);
				_X -= x;
			}
			break;
		case VK_RIGHT: case 0x44: //Right arrow
			ShowCur(1);
			if (_X == FIRST_CELL_X + (BOARD_SIZE - 1) * x) {
				_X = FIRST_CELL_X;
				GotoXY(_X, _Y);
			}
			else {
				GotoXY(_X + x, _Y);
				_X += x;
			}
			break;
		case VK_DOWN: case 0x53: //Down arrow
			ShowCur(1);
			if (_Y == FIRST_CELL_Y + (BOARD_SIZE - 1) * y) {
				_Y = FIRST_CELL_Y;
				GotoXY(_X, _Y);
			}
			else {
				GotoXY(_X, _Y + y);
				_Y += y;
			}
			break;
		case VK_UP: case 0x57: //Up arrow
			ShowCur(1);
			if (_Y == FIRST_CELL_Y) {
				_Y += (BOARD_SIZE - 1) * y;
				GotoXY(_X, _Y);
			}
			else {
				GotoXY(_X, _Y - y);
				_Y -= y;
			}
			break;
		default:
			break;
		}
	}
}

//Handle event
void HandleEvent(int x, int y, void(*func)(int, int, KEY_EVENT_RECORD)) {
	DWORD DWNumberOfEvents = 0;
	DWORD DWNumberOfEventsRead = 0; 
	HANDLE HConsoleInput = GetStdHandle(STD_INPUT_HANDLE); 
	GetNumberOfConsoleInputEvents(HConsoleInput, &DWNumberOfEvents); 
	if (DWNumberOfEvents) {
		INPUT_RECORD* IREventBuffer = new INPUT_RECORD[DWNumberOfEvents];
		ReadConsoleInput(HConsoleInput, IREventBuffer, DWNumberOfEvents, &DWNumberOfEventsRead);
		for (DWORD i = 0; i < DWNumberOfEvents; ++i) {
			if (IREventBuffer[i].EventType == KEY_EVENT) 
				func(x, y, IREventBuffer[i].Event.KeyEvent);
		}
	}
}

//Control Menu:
//0: Main Menu
//1: New Game
//2: Load game
//3: Settings
//4: Help
//5: Info
//6: Exit
void ControlMenu() {
	while (1) {
		if (_KEYPRESSED) {
			_KEYPRESSED = 0;
			_CURRENT_MENU = _MENU;
			system("cls");

			switch (_MENU) {
			case 0:
				MainMenu();
				break;
			case 1:
				NewGame();
				break;
			case 2:
				//Load game
				break;
			case 3:
				Setting();

				break;
			case 4:
				About();
				break;
			case 5:
				Help();
				break;
			case 6:
				Exit();
				break;
			}
		}
		switch (_CURRENT_MENU) {
		case 0:
			HandleEvent(80, 22, HandleKeyForMainMenu);
			break;
		case 1:
			HandleEvent(D3_NewGame_Box_Left + 41, D3_NewGame_Box_Top + 8, HandleKeyForNewGame);
			break;
		case 2:
			break;
		case 3:
			HandleEvent(80, 22, HandleKeyForSettings);
			break;
		case 4:
			HandleEvent(80, 22, HandleKeyForAbout);
			break;
		case 5:
			HandleEvent(80, 22, HandleKeyForHelp);
			break;
		case 7:
			HandleEvent(0, 0, HandleKeyForChoosingChar);
			break;
		}
	}
}

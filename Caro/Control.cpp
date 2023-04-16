#include "Control.h"
#include "View.h"

//Start Game
void StartGame() {
	system("cls");
	DrawBoard(BOARD_SIZE);
	DrawInforFrame();
	DrawLogoFrame();
	DrawLogoHcmus();
	DrawAvatarBattle(D2_PLAYER01_CHARACTER, D2_PLAYER02_CHARACTER);
	DrawScore(Score1, Score2);
	DrawTurn(1);
	GotoXY(FIRST_CELL_X, FIRST_CELL_Y);
	ShowCur(1);
	PrintDataBoard();
	_CURRENT_MENU = 9;
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
				DrawSavedBoard();
				DrawButton();
				PrintFileName(Name);
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
			HandleEvent(0, 0, HandleKeyForLoad);
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
		case 8:
			HandleEvent(4, 2, HandleKeyForSaveGame);
			break;
		case 9:
			if (D3_GameMode == 1)
				HandleEvent(4, 2, HandleKeyForBoard);
			else
				HandleEvent(4, 2, HandleKeyForBoardBot);
			break;
		case 10:
			HandleEvent(4, 2, HandleKeyForSaveGame_ESC);
			break;
		}
	}
}

void InitGame() {
	Turn = 0;
	Score1 = 0;
	Score2 = 0;
	Draw = 0;
	Count = 0;
	FileName = "";
	D2_PLAYER = 1;
	D2_PLAYER01_NAME = "";
	D2_PLAYER02_NAME = "Mega Roboto";
	D2_PLAYER01_CHARACTER = 1;
	D2_PLAYER02_CHARACTER = 1;
	D3_GameMode = 0;
	D3_Y2 = D3_NewGame_Box_Top + 8;
}
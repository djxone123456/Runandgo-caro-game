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
			if (sound_mode)
				PlaySound(TEXT("Sounds//put-x-o.wav"), NULL, SND_FILENAME | SND_ASYNC);
			cout << "X";
			ShowCur(0);
			break;
		case VK_ESCAPE: //Esc
			break;
		case VK_LEFT: case 0x41: //Left arrow
			ShowCur(1);
			if (sound_mode)
				PlaySound(TEXT("Sounds//move-in-board.wav"), NULL, SND_FILENAME | SND_ASYNC);
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
			if (sound_mode)
				PlaySound(TEXT("Sounds//move-in-board.wav"), NULL, SND_FILENAME | SND_ASYNC);
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
			if (sound_mode)
				PlaySound(TEXT("Sounds//move-in-board.wav"), NULL, SND_FILENAME | SND_ASYNC);
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
			if (sound_mode)
				PlaySound(TEXT("Sounds//move-in-board.wav"), NULL, SND_FILENAME | SND_ASYNC);
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

//Handle key for the main menu
void HandleKeyForMainMenu(int X, int Y, KEY_EVENT_RECORD key) {
	if (key.bKeyDown) //Key pressed
	{
		switch (key.wVirtualKeyCode)
		{
		case VK_RETURN: {//Enter
			if (sound_mode)
				PlaySound(TEXT("Sounds//select.wav"), NULL, SND_FILENAME | SND_ASYNC);
			_KEYPRESSED = 1;
			break; 
		}
		case VK_DOWN: case 0x53: {//Down arrow
			if (sound_mode)
				PlaySound(TEXT("Sounds//switch-selection.wav"), NULL, SND_FILENAME | SND_ASYNC);
			GotoXY(DEFAULT_X, DEFAULT_Y);
			printf(" ");
			GotoXY(DEFAULT_X + 13, DEFAULT_Y);
			printf(" ");
			if (DEFAULT_Y == Y + 10) {
				DEFAULT_Y = Y;
				_MENU = 1;
			}
			else {
				DEFAULT_Y += 2;
				_MENU++;
			}
			GotoXY(DEFAULT_X, DEFAULT_Y);
			cout << SELECTED_LEFT;
			GotoXY(DEFAULT_X + 13, DEFAULT_Y);
			cout << SELECTED_RIGHT;
			break; 
		}
		case VK_UP: case 0x57: {//Up arrow
			if (sound_mode)
				PlaySound(TEXT("Sounds//switch-selection.wav"), NULL, SND_FILENAME | SND_ASYNC);
			GotoXY(DEFAULT_X, DEFAULT_Y);
			printf(" ");
			GotoXY(DEFAULT_X + 13, DEFAULT_Y);
			printf(" ");
			if (DEFAULT_Y == Y) {
				DEFAULT_Y = Y + 10;
				_MENU = 6;
			}
			else {
				DEFAULT_Y -= 2;
				_MENU--;
			}
			GotoXY(DEFAULT_X, DEFAULT_Y);
			cout << SELECTED_LEFT;
			GotoXY(DEFAULT_X + 13, DEFAULT_Y);
			cout << SELECTED_RIGHT;
			break;
		}
		default:
			break;
		}
	}
}

//Handle key for the Help Menu
void HandleKeyForHelp(int X, int Y, KEY_EVENT_RECORD key) {
	if (key.bKeyDown && key.wVirtualKeyCode == VK_RETURN) {
		if (sound_mode)
			PlaySound(TEXT("Sounds//select.wav"), NULL, SND_FILENAME | SND_ASYNC);
		_MENU = 1;
		_CURRENT_MENU = 0;
		system("cls");
		MainMenu();
		DEFAULT_X = 80;
		DEFAULT_Y = 22;
	}
}

// Handle key for Setting Menu
void HandleKeyForSetting(int x, int y, KEY_EVENT_RECORD key) {
	//y is useless
	if (key.bKeyDown) //Key pressed
	{
		switch (key.wVirtualKeyCode)
		{
		case VK_RETURN: //Enter
			if (sound_mode)
				PlaySound(TEXT("Sounds//select.wav"), NULL, SND_FILENAME | SND_ASYNC);
			_SETTING = 0;
			_Y_Set = STop + 5;
			system("cls");
			_CURRENT_MENU = 0;
			_MENU = 1;
			system("cls");
			MainMenu();
			DEFAULT_X = 80;
			DEFAULT_Y = 22;
			break;
		case VK_LEFT: case 0x41: //Left arrow
			if (sound_mode)
				PlaySound(TEXT("Sounds//switch-selection.wav"), NULL, SND_FILENAME | SND_ASYNC);
			if (_SETTING == 0 && music_mode == 0)
			{
				music_mode = 1;
				Music_Mode(music_mode);
				Music_Control();
			}
			if (_SETTING == 1 && sound_mode == 0)
			{
				sound_mode = 1;
				Sound_Mode(sound_mode);
			}
			DrawChangeSetting(x, _Y_Set);
			break;
		case VK_RIGHT: case 0x44: //Right arrow
			if (sound_mode)
				PlaySound(TEXT("Sounds//switch-selection.wav"), NULL, SND_FILENAME | SND_ASYNC);
			if (_SETTING == 0 && music_mode == 1)
			{
				music_mode = 0;
				Music_Mode(music_mode);
				Music_Control();
			}
			if (_SETTING == 1 && sound_mode == 1)
			{
				sound_mode = 0;
				Sound_Mode(sound_mode);
			}
			DrawChangeSetting(x, _Y_Set);
			break;
		case VK_DOWN: case 0x53: //Down arrow
			if (sound_mode)
				PlaySound(TEXT("Sounds//switch-selection.wav"), NULL, SND_FILENAME | SND_ASYNC);
			GotoXY(x - 4, _Y_Set);
			printf(" ");
			GotoXY(x + 6, _Y_Set);
			printf(" ");
			if (_SETTING == 1)
			{
				_SETTING = 0;
				_Y_Set = STop + 5;
			}
			else
			{
				_SETTING += 1;
				_Y_Set += 2;
			}
			DrawChangeSetting(x, _Y_Set);
			break;
		case VK_UP: case 0x57: //Up arrow
			if (sound_mode)
				PlaySound(TEXT("Sounds//switch-selection.wav"), NULL, SND_FILENAME | SND_ASYNC);
			GotoXY(x - 4, _Y_Set);
			printf(" ");
			GotoXY(x + 6, _Y_Set);
			printf(" ");
			if (_SETTING == 0)
			{
				_SETTING = 1;
				_Y_Set = STop + 7;
			}
			else
			{
				_SETTING -= 1;
				_Y_Set -= 2;
			}
			DrawChangeSetting(x, _Y_Set);
			break;
		default:
			break;
		}
	}
}

// Handle key for The Info Menu
void HandleKeyForInfo(int X, int Y, KEY_EVENT_RECORD key) {
	if (key.bKeyDown && key.wVirtualKeyCode == VK_RETURN) {
		if (sound_mode)
			PlaySound(TEXT("Sounds//select.wav"), NULL, SND_FILENAME | SND_ASYNC);
		_MENU = 1;
		_CURRENT_MENU = 0;
		system("cls");
		MainMenu();
		DEFAULT_X = 80;
		DEFAULT_Y = 22;
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

//Close Console
void Exit() {
	HWND hwnd = GetConsoleWindow();
	SendMessage(hwnd, WM_CLOSE, 0, 0);
}

////Control Menu:
////0: Main Menu
////1: New Game
////2: Load game
////3: Settings
////4: Help
////5: Info
////6: Exit
//void ControlMenu() {
//	while (1) {
//		if (_KEYPRESSED) {
//			switch (_MENU) {
//			case 1:
//				_KEYPRESSED = 0;
//				//New game
//				break;
//			case 2:
//				_KEYPRESSED = 0;
//				//Load game
//				break;
//			case 3:
//				_KEYPRESSED = 0;
//				_CURRENT_MENU = 3;
//				//Settings
//				system("cls");
//				
//				break;
//			case 4:
//				_CURRENT_MENU = 4;
//				_KEYPRESSED = 0;
//				system("cls");
//				//Help
//				break;
//			case 5:
//				_KEYPRESSED = 0;
//				_CURRENT_MENU = 5;
//				system("cls");
//				//Info
//				break;
//			case 6:
//				system("cls");
//				//Say goodbye and exit
//				Sleep(1000);
//				Exit();
//				break;
//			}
//		}
//		switch (_CURRENT_MENU) {
//		case 0:
//			HandleEvent(80, 22, HandleKeyForMainMenu);
//			break;
//		case 1:
//			break;
//		case 2:
//			break;
//		case 3:
//			HandleEvent(90, STop + 5, HandleKeyForSetting);
//			break;
//		case 4:
//			HandleEvent(80, 22, HandleKeyForHelp);
//			break;
//		case 5:
//			HandleEvent(80, 22, HandleKeyForInfo);
//			break;
//		}
//	}
//}

void Music_Control()
{
	if (music_mode)
		mciSendString(L"play \"Sounds//background-music.mp3\" repeat", NULL, 0, 0);
	else
		mciSendString(L"pause \"Sounds//background-music.mp3\"", NULL, 0, 0);

	//If use "close", when turn off music, it will slow the game	
	//mciSendString(L"close \"Sounds//background-music.mp3\"", NULL, 0, 0);   
}
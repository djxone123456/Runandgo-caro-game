#include "MainMenu.h"

int MainMenu()
{
	//Control Menu:
	//0: Main Menu
	//1: New Game
	//2: Load game
	//3: Settings
	//4: Help
	//5: Info
	//6: Exit
	MenuDefault();
	CurrentPoint = 0;
	DrawCursor(129, 17 + 3 * CurrentPoint);
	
	return 0x0000;
}

void HandleKeyForMainMenu(int x, int y, KEY_EVENT_RECORD key)
{
	if (key.bKeyDown) //Key pressed
	{
		switch (key.wVirtualKeyCode) {
		case VK_DOWN: case 0x53: //Press Down key
			if (D2_INGAME_MUSIC) PlaySound(TEXT("sounds//switch-selection.wav"), NULL, SND_FILENAME | SND_ASYNC);
			//Change cursor
			EraseCursor(129, 17 + 3 * CurrentPoint);
			CurrentPoint = (CurrentPoint + 1) % D1_MenuItems;
			DrawCursor(129, 17 + 3 * CurrentPoint);
			break;

		case VK_UP: case 0x57: //Press Up key
			if (D2_INGAME_MUSIC) PlaySound(TEXT("sounds//switch-selection.wav"), NULL, SND_FILENAME | SND_ASYNC);
			//Change cursor
			EraseCursor(129, 17 + 3 * CurrentPoint);
			CurrentPoint = (CurrentPoint + D1_MenuItems - 1) % D1_MenuItems;
			DrawCursor(129, 17 + 3 * CurrentPoint);
			break;

		case VK_RETURN: //Press Enter key
			if (D2_INGAME_MUSIC) PlaySound(TEXT("sounds//select.wav"), NULL, SND_FILENAME | SND_ASYNC);
			system("cls");
			_KEYPRESSED = 1;
			_MENU = CurrentPoint + 1;
			break;

		default:
			break;
		}
	}
}

static void Logo() 
{
	ShowCur(0);
	int OldMode = _setmode(_fileno(stdout), _O_WTEXT);

	//Print & Effect
	int x = 44, y = 1, x_last = 45 + int(D2_CAROCHESS_0.size());
	for (int i = 0; i < (int)D2_CAROCHESS_0.size() - i; i++) {
		GotoXY(++x, y);
		wcout << D2_CAROCHESS_0[i];
		GotoXY(x, y + 1);
		wcout << D2_CAROCHESS_1[i];
		GotoXY(x, y + 2);
		wcout << D2_CAROCHESS_2[i];
		GotoXY(x, y + 3);
		wcout << D2_CAROCHESS_3[i];
		GotoXY(x, y + 4);
		wcout << D2_CAROCHESS_4[i];
		GotoXY(x, y + 5);
		wcout << D2_CAROCHESS_5[i];
		GotoXY(x, y + 6);
		wcout << D2_CAROCHESS_6[i];
		GotoXY(x, y + 7);
		wcout << D2_CAROCHESS_7[i];
		GotoXY(x, y + 8);
		wcout << D2_CAROCHESS_8[i];
		GotoXY(x, y + 9);
		wcout << D2_CAROCHESS_9[i];

		GotoXY(--x_last, y);
		wcout << D2_CAROCHESS_0[D2_CAROCHESS_0.size() - 1 - i];
		GotoXY(x_last, y + 1);
		wcout << D2_CAROCHESS_1[D2_CAROCHESS_0.size() - 1 - i];
		GotoXY(x_last, y + 2);
		wcout << D2_CAROCHESS_2[D2_CAROCHESS_0.size() - 1 - i];
		GotoXY(x_last, y + 3);
		wcout << D2_CAROCHESS_3[D2_CAROCHESS_0.size() - 1 - i];
		GotoXY(x_last, y + 4);
		wcout << D2_CAROCHESS_4[D2_CAROCHESS_0.size() - 1 - i];
		GotoXY(x_last, y + 5);
		wcout << D2_CAROCHESS_5[D2_CAROCHESS_0.size() - 1 - i];
		GotoXY(x_last, y + 6);
		wcout << D2_CAROCHESS_6[D2_CAROCHESS_0.size() - 1 - i];
		GotoXY(x_last, y + 7);
		wcout << D2_CAROCHESS_7[D2_CAROCHESS_0.size() - 1 - i];
		GotoXY(x_last, y + 8);
		wcout << D2_CAROCHESS_8[D2_CAROCHESS_0.size() - 1 - i];
		GotoXY(x_last, y + 9);
		wcout << D2_CAROCHESS_9[D2_CAROCHESS_0.size() - 1 - i];
		Sleep(10);
	}
	int CurrentMode = _setmode(_fileno(stdout), OldMode);
}

static void MenuLogo(int x, int y)
{
	int OldMode = _setmode(_fileno(stdout), _O_WTEXT);
	GotoXY(x, y);
	wcout << D1_MENULOGO_1;
	GotoXY(x, y + 1);
	wcout << D1_MENULOGO_2;
	GotoXY(x, y + 2);
	wcout << D1_MENULOGO_3;
	GotoXY(x, y + 3);
	wcout << D1_MENULOGO_4;
	GotoXY(x, y + 4);
	wcout << D1_MENULOGO_5;
	GotoXY(x, y + 5);
	wcout << D1_MENULOGO_6;
	GotoXY(x, y + 6);
	wcout << D1_MENULOGO_7;
	GotoXY(x, y + 7);
	wcout << D1_MENULOGO_8;
	GotoXY(x, y + 8);
	wcout << D1_MENULOGO_9;
	GotoXY(x, y + 9);
	wcout << D1_MENULOGO_10;
	GotoXY(x, y + 10);
	wcout << D1_MENULOGO_11;
	GotoXY(x, y + 11);
	wcout << D1_MENULOGO_12;
	GotoXY(x, y + 12);
	wcout << D1_MENULOGO_13;
	GotoXY(x, y + 13);
	wcout << D1_MENULOGO_14;
	int CurrentMode = _setmode(_fileno(stdout), OldMode);
}

static void MenuFrame()
{
	MenuLogo(106, 18);
	DrawMenuBorder(100, 13, 150, 36);

	int x, y;
	x = 132; y = 17;
	GotoXY(x, y);
	printf("New Game");
	y += 3;
	GotoXY(x, y);
	printf("Load Games");
	y += 3;
	GotoXY(x, y);
	printf("Settings");
	y += 3;
	GotoXY(x, y);
	printf("About Us");
	y += 3;
	GotoXY(x, y);
	printf("Help");
	y += 3;
	GotoXY(x, y); 
	printf("Exit");

}

static void DrawCursor(int x, int y)
{
	GotoXY(x, y);
	cout << D1_Right_Arrow;
}

static void EraseCursor(int x, int y)
{
	GotoXY(x, y);
	cout << " ";
}

static void DrawButton(int TopLeftX, int TopLeftY, int BottomRightX, int BottomRightY)
{
	GotoXY(TopLeftX, TopLeftY);
	cout << LEFT_TOP;
	for (int i = TopLeftX; i < BottomRightX; i++)
		cout << HORIZONTAL_LINE;
	cout << RIGHT_TOP;

	for (int Y = TopLeftY + 1; Y < BottomRightY; Y++)
	{
		GotoXY(TopLeftX, Y); cout << VERTICAL_LINE;
		GotoXY(BottomRightX + 1, Y); cout << VERTICAL_LINE;
	}

	GotoXY(TopLeftX, BottomRightY);
	cout << LEFT_BOTTOM;
	for (int i = TopLeftX; i < BottomRightX; i++)
		cout << HORIZONTAL_LINE;
	cout << RIGHT_BOTTOM;
}

static void DrawMenuBorder(int TopLeftX, int TopLeftY, int BottomRightX, int BottomRightY)
{
	int OldMode = _setmode(_fileno(stdout), _O_WTEXT);
	GotoXY(TopLeftX, TopLeftY);
	for (int i = TopLeftX; i <= BottomRightX; i++)
		wcout << DarkBottomHalf;

	for (int Y = TopLeftY + 1; Y < BottomRightY; Y++)
	{
		GotoXY(TopLeftX, Y); wcout << DarkSquareBox;
		GotoXY(BottomRightX, Y); wcout << DarkSquareBox;
	}

	GotoXY(TopLeftX, BottomRightY);
	for (int i = TopLeftX; i <= BottomRightX; i++)
		wcout << DarkTopHalf;
	int CurrentMode = _setmode(_fileno(stdout), OldMode);
}

static void DeleteButton(int TopLeftX, int TopLeftY, int BottomRightX, int BottomRightY)
{
	GotoXY(TopLeftX, TopLeftY);
	cout << ' ';
	for (int i = TopLeftX; i < BottomRightX; i++)
		cout << ' ';
	cout << ' ';

	for (int Y = TopLeftY + 1; Y < BottomRightY; Y++)
	{
		GotoXY(TopLeftX, Y); cout << ' ';
		GotoXY(BottomRightX + 1, Y); cout << ' ';
	}

	GotoXY(TopLeftX, BottomRightY);
	cout << ' ';
	for (int i = TopLeftX; i < BottomRightX; i++)
		cout << ' ';
	cout << ' ';
}

static void MenuDefault()
{
	system("cls");
	Logo();
	Ranking();
	MenuFrame();
	DrawCursor(129, 17);
}
#include "View.h"

//Fix the size of the console window
void FixConsoleWindow() {
	HWND consoleWindow = GetConsoleWindow();
	LONG style = GetWindowLong(consoleWindow, GWL_STYLE);
	style = style & ~(WS_MAXIMIZEBOX) & ~(WS_THICKFRAME);
	SetWindowLong(consoleWindow, GWL_STYLE, style);
}

//Set the size of the console window
void SetWindowSize(int width, int height) {
	HWND consoleWindow = GetConsoleWindow();
	RECT r;
	HANDLE hConsole;
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	GetWindowRect(consoleWindow, &r);
	MoveWindow(consoleWindow, 0, 0, width, height, TRUE);
}

//Hide scrollbar of the console window
void ShowScrollbar(bool Show) {
	HWND hWnd = GetConsoleWindow();
	ShowScrollBar(hWnd, SB_BOTH, Show);
}

//Set font size & font
void SetFont(const wchar_t name[], int size) {
	CONSOLE_FONT_INFOEX cfi;
	cfi.cbSize = sizeof cfi;
	cfi.nFont = 0;
	cfi.dwFontSize.X = 0;
	cfi.dwFontSize.Y = size; //Font size
	cfi.FontFamily = FF_DONTCARE;
	cfi.FontWeight = FW_NORMAL;
	wcscpy_s(cfi.FaceName, name);
	SetCurrentConsoleFontEx(GetStdHandle(STD_OUTPUT_HANDLE), FALSE, &cfi);
}

//Create the console window
void CreateConsoleWindow(int width, int height) {
	system("color 70");
	SetConsoleTitle(L"Caro Game");
	SetWindowSize(width, height);
	ShowScrollbar(0);
	FixConsoleWindow();
}

//Go to position (x, y)
void GotoXY(int x, int y) {
	COORD coord;
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

//Show/Hide Cursor on the console window
void ShowCur(bool CursorVisibility) {
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO ConCurInf;
	ConCurInf.dwSize = 10;
	ConCurInf.bVisible = CursorVisibility;
	SetConsoleCursorInfo(handle, &ConCurInf);
}

//Change color of Text since this function is called
void TextColor(int color)
{
	static int __BACKGROUND = 7;
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_SCREEN_BUFFER_INFO csbiInfo;
	GetConsoleScreenBufferInfo(h, &csbiInfo);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),
		color + (__BACKGROUND << 4));
}

//Print color text USAGE: PrintTextColor(L"example", <color>);
void PrintTextColor(const wstring& s, const int& color) {
	TextColor(color);
	int OldMode = _setmode(_fileno(stdout), _O_WTEXT);
	wcout << s;
	int CurrentMode = _setmode(_fileno(stdout), OldMode);
	TextColor(0);
}

//Draw the Caro board
void DrawBoard(int pSize) {
	ShowCur(0);
	int Max_i = pSize * 2;
	int Max_j = pSize * 4;
	//Effect
	GotoXY(LEFT, TOP);
	cout << LEFT_TOP << HORIZONTAL_LINE;
	GotoXY(LEFT + Max_j, TOP + Max_i);
	cout << RIGHT_BOTTOM;
	int j = 1;
	for (int i = 1; j < Max_j / 2; i++, j++) {

		GotoXY(LEFT + 2 * j, TOP);
		cout << HORIZONTAL_LINE << HORIZONTAL_LINE;
		GotoXY(LEFT, TOP + i);
		cout << VERTICAL_LINE;

		GotoXY(LEFT + Max_j - 2 * j, TOP + Max_i);
		cout << HORIZONTAL_LINE << HORIZONTAL_LINE;
		GotoXY(LEFT + Max_j, TOP + Max_i - i);
		cout << VERTICAL_LINE;

		Sleep(20);
	}
	//Draw board
	for (int i = 0; i <= Max_i; i++) {
		GotoXY(LEFT, TOP + i);
		for (int j = 0; j <= Max_j; j++) {
			if (i == 0) {
				if (j == 0) cout << LEFT_TOP;
				else if (j == Max_j) cout << RIGHT_TOP;
				else if (j % 4 == 0) cout << T_SHAPE_DOWN;
				else cout << HORIZONTAL_LINE;
			}
			else if (i == Max_i) {
				if (j == 0) cout << LEFT_BOTTOM;
				else if (j == Max_j) cout << RIGHT_BOTTOM;
				else if (j % 4 == 0) cout << T_SHAPE_UP;
				else cout << HORIZONTAL_LINE;
			}
			else if (i % 2 == 0) {
				if (j == 0) cout << T_SHAPE_RIGHT;
				else if (j == Max_j) cout << T_SHAPE_LEFT;
				else if (j % 4 == 0) cout << CROSS;
				else cout << HORIZONTAL_LINE;
			}
			else {
				if (j % 4 == 0) cout << VERTICAL_LINE;
				else cout << " ";
			}
		}
	}
	GotoXY(FIRST_CELL_X, FIRST_CELL_Y); //Move pointer to the first cell
	ShowCur(1);
}

//Draw main menu
void MainMenu() {
	ShowCur(0);
	int OldMode = _setmode(_fileno(stdout), _O_WTEXT);
	wstring l1 = L"  ▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄	\n";
	wstring l2 = L"▄▄█•••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••█▄▄	\n";
	wstring l3 = L"█•••██████╗•█████╗•██████╗••██████╗••••••██████╗██╗••██╗███████╗███████╗███████╗••█	\n";
	wstring l4 = L"█••██╔════╝██╔══██╗██╔══██╗██╔═══██╗••••██╔════╝██║••██║██╔════╝██╔════╝██╔════╝••█	\n";
	wstring l5 = L"█••██║•••••███████║██████╔╝██║•••██║••••██║•••••███████║█████╗••███████╗███████╗••█	\n";
	wstring l6 = L"█••██║•••••██╔══██║██╔══██╗██║•••██║••••██║•••••██╔══██║██╔══╝••╚════██║╚════██║••█	\n";
	wstring l7 = L"█••╚██████╗██║••██║██║••██║╚██████╔╝••••╚██████╗██║••██║███████╗███████║███████║••█  \n";
	wstring l8 = L"█•••╚═════╝╚═╝••╚═╝╚═╝••╚═╝•╚═════╝••••••╚═════╝╚═╝••╚═╝╚══════╝╚══════╝╚══════╝••█  \n";
	wstring l9 = L"▀▀█•••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••█▀▀	\n";
	wstring l0 = L"  ▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀	\n";
	//Print & Effect
	int x = 44, y = 7, x_last = 45 + l1.size();
	for (int i = 0; i <= l1.size() - 1 - i; i++) {
		GotoXY(++x, y);
		wcout << l1[i];
		GotoXY(x, y + 1);
		wcout << l2[i];
		GotoXY(x, y + 2);
		wcout << l3[i];
		GotoXY(x, y + 3);
		wcout << l4[i];
		GotoXY(x, y + 4);
		wcout << l5[i];
		GotoXY(x, y + 5);
		wcout << l6[i];
		GotoXY(x, y + 6);
		wcout << l7[i];
		GotoXY(x, y + 7);
		wcout << l8[i];
		GotoXY(x, y + 8);
		wcout << l9[i];
		GotoXY(x, y + 9);
		wcout << l0[i];

		GotoXY(--x_last, y);
		wcout << l1[l1.size() - 1 - i];
		GotoXY(x_last, y + 1);
		wcout << l2[l1.size() - 1 - i];
		GotoXY(x_last, y + 2);
		wcout << l3[l1.size() - 1 - i];
		GotoXY(x_last, y + 3);
		wcout << l4[l1.size() - 1 - i];
		GotoXY(x_last, y + 4);
		wcout << l5[l1.size() - 1 - i];
		GotoXY(x_last, y + 5);
		wcout << l6[l1.size() - 1 - i];
		GotoXY(x_last, y + 6);
		wcout << l7[l1.size() - 1 - i];
		GotoXY(x_last, y + 7);
		wcout << l8[l1.size() - 1 - i];
		GotoXY(x_last, y + 8);
		wcout << l9[l1.size() - 1 - i];
		GotoXY(x_last, y + 9);
		wcout << l0[l1.size() - 1 - i];

		Sleep(3);
	}
	int CurrentMode = _setmode(_fileno(stdout), OldMode);

	//Draw bars

	for (int i = 0; i < BMax_i; i += 3) {

		GotoXY(BLeft + i, BTop);
		cout << Lower_Vertical << Lower_Vertical << Lower_Vertical;

		GotoXY(BMax_i + BLeft - i, BMax_j);
		cout << Upper_Vertical << Upper_Vertical << Upper_Vertical;
		Sleep(5);
	}

	x = 83; y = 22;
	GotoXY(x, y);
	printf("New Game");

	y += 2;
	GotoXY(x, y);
	printf("Continue");

	y += 2;
	GotoXY(x, y);
	printf("Settings");

	y += 2;
	x += 2;
	GotoXY(x, y);
	printf("Help");

	y += 2;
	GotoXY(x, y);
	printf("Info");

	y += 2;
	GotoXY(x, y);
	printf("Exit");

	GotoXY(80, 22);
	cout << SELECTED_LEFT;
	GotoXY(93, 22);
	cout << SELECTED_RIGHT;
}

//Draw arrow and blur arrow when change settings
void DrawChangeSetting(int x, int y)
{
	switch (_SETTING)
	{
	case 0:
		GotoXY(x - 5, y);
		printf(" ");
		TextColor(music_mode == 0 ? 0 : 8);
		cout << Right_Arrow;

		GotoXY(x + 5, y);
		printf(" ");
		TextColor(music_mode == 0 ? 8 : 0);
		cout << Left_Arrow;
		TextColor(0);
		break;
	case 1:
		GotoXY(x - 5, y);
		printf(" ");
		TextColor(sound_mode == 0 ? 0 : 8);
		cout << SELECTED_RIGHT;

		GotoXY(x + 5, y);
		printf(" ");
		TextColor(sound_mode == 0 ? 8 : 0);
		cout << SELECTED_LEFT;
		TextColor(0);
		break;
	default:
		break;
	}
}

//Draw Setting On/Off of background music
void Music_Mode(int i)
{
	int x = 90, y = STop + 5;
	GotoXY(x, y);
	printf(" ");
	GotoXY(x + 1, y);
	printf(" ");
	GotoXY(x + 2, y);
	printf(" ");
	GotoXY(x, y);
	cout << mode[i];

	GotoXY(x - 4, y);
	TextColor(i == 0 ? 0 : 8);
	cout << SELECTED_RIGHT;

	GotoXY(x + 6, y);
	TextColor(i == 0 ? 8 : 0);
	cout << SELECTED_LEFT;
	TextColor(0);
}

//Draw Setting On/Off of ingame music
void Sound_Mode(int i)
{
	int x = 90, y = STop + 7;
	GotoXY(x, y);
	printf(" ");
	GotoXY(x + 1, y);
	printf(" ");
	GotoXY(x + 2, y);
	printf(" ");
	GotoXY(x, y);
	cout << mode[i];
	TextColor(0);
}

void PrintTextColor_Char(const char& s, const int& color) {
	TextColor(color);
	cout << s;
	TextColor(0);
}
#include "View.h"

//Fix the size of the console window
static void FixConsoleWindow() {
	HWND consoleWindow = GetConsoleWindow();
	LONG style = GetWindowLong(consoleWindow, GWL_STYLE);
	style = style & ~(WS_MAXIMIZEBOX) & ~(WS_THICKFRAME);
	SetWindowLong(consoleWindow, GWL_STYLE, style);
}

//Set the size of the console window
static void SetWindowSize(int width, int height) {
	HWND consoleWindow = GetConsoleWindow();
	RECT r;
	HANDLE hConsole;
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	GetWindowRect(consoleWindow, &r);
	MoveWindow(consoleWindow, 0, 0, width, height, TRUE);
}

//Hide scrollbar of the console window
static void ShowScrollbar(bool Show) {
	HWND hWnd = GetConsoleWindow();
	ShowScrollBar(hWnd, SB_BOTH, Show);
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

//Print color text USAGE: PrintTextColor("example", <color>);
void PrintTextColor(const string& s, const int& color) {
	TextColor(color);
	int OldMode = _setmode(_fileno(stdout), _O_WTEXT);
	cout << s;
	int CurrentMode = _setmode(_fileno(stdout), OldMode);
	TextColor(0);
}

void PrintTextColor_Char(const char& s, const int& color) {
	TextColor(color);
	cout << s;
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
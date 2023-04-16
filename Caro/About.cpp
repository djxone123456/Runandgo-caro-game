#include "About.h"

int About() {
	ShowCur(0);
	int OldMode = _setmode(_fileno(stdout), _O_WTEXT);
	int _pos_x = D2_X_ABOUT + 20;
	for (int i = 0; i < D2_ABOUT_1.size() - 1 - i; i += 2) {
		GotoXY(_pos_x + i, D2_Y_ABOUT - 7);
		wcout << D2_ABOUT_1[i] << D2_ABOUT_1[i + 1];
		GotoXY(_pos_x + i, D2_Y_ABOUT - 6);
		wcout << D2_ABOUT_2[i] << D2_ABOUT_2[i + 1];
		GotoXY(_pos_x + i, D2_Y_ABOUT - 5);
		wcout << D2_ABOUT_3[i] << D2_ABOUT_3[i + 1];
		GotoXY(_pos_x + i, D2_Y_ABOUT - 4);
		wcout << D2_ABOUT_4[i] << D2_ABOUT_4[i + 1];
		GotoXY(_pos_x + i, D2_Y_ABOUT - 3);
		wcout << D2_ABOUT_5[i] << D2_ABOUT_5[i + 1];
		GotoXY(_pos_x + i, D2_Y_ABOUT - 2);
		wcout << D2_ABOUT_6[i] << D2_ABOUT_6[i + 1];

		GotoXY(_pos_x + int(D2_ABOUT_1.size()) - i - 2, D2_Y_ABOUT - 7);
		wcout << D2_ABOUT_1[D2_ABOUT_1.size() - 2 - i] << D2_ABOUT_1[D2_ABOUT_1.size() - 1 - i];
		GotoXY(_pos_x + int(D2_ABOUT_1.size()) - i - 2, D2_Y_ABOUT - 6);
		wcout << D2_ABOUT_2[int(D2_ABOUT_1.size()) - 2 - i] << D2_ABOUT_2[D2_ABOUT_1.size() - 1 - i];
		GotoXY(_pos_x + int(D2_ABOUT_1.size()) - i - 2, D2_Y_ABOUT - 5);
		wcout << D2_ABOUT_3[D2_ABOUT_1.size() - 2 - i] << D2_ABOUT_3[D2_ABOUT_1.size() - 1 - i];
		GotoXY(_pos_x + int(D2_ABOUT_1.size()) - i - 2, D2_Y_ABOUT - 4);
		wcout << D2_ABOUT_4[D2_ABOUT_1.size() - 2 - i] << D2_ABOUT_4[D2_ABOUT_1.size() - 1 - i];
		GotoXY(_pos_x + int(D2_ABOUT_1.size()) - i - 2, D2_Y_ABOUT - 3);
		wcout << D2_ABOUT_5[D2_ABOUT_1.size() - 2 - i] << D2_ABOUT_5[D2_ABOUT_1.size() - 1 - i];
		GotoXY(_pos_x + int(D2_ABOUT_1.size()) - i - 2, D2_Y_ABOUT - 2);
		wcout << D2_ABOUT_6[D2_ABOUT_1.size() - 2 - i] << D2_ABOUT_6[D2_ABOUT_1.size() - 1 - i];

		Sleep(10);
	}

	int CurrentMode = _setmode(_fileno(stdout), OldMode);

	for (int i = 0; i < 82; i += 2) {
		GotoXY(D2_X_ABOUT + i, D2_Y_ABOUT);
		cout << D2_LOWER_FRAME << D2_LOWER_FRAME;
		GotoXY(D2_X_ABOUT + 80 - i, D2_Y_ABOUT + 31);
		cout << D2_UPPER_FRAME << D2_UPPER_FRAME;
		Sleep(10);
	}

	for (int i = 1; i < 31; i += 2) {
		GotoXY(D2_X_ABOUT + 81, D2_Y_ABOUT + i);
		cout << D2_VERTICAL_FRAME;
		GotoXY(D2_X_ABOUT + 81, D2_Y_ABOUT + i + 1);
		cout << D2_VERTICAL_FRAME;
		GotoXY(D2_X_ABOUT, D2_Y_ABOUT + 31 - i);
		cout << D2_VERTICAL_FRAME;
		GotoXY(D2_X_ABOUT, D2_Y_ABOUT + 31 - i - 1);
		cout << D2_VERTICAL_FRAME;
		Sleep(10);
	}

	OldMode = _setmode(_fileno(stdout), _O_WTEXT);
	GotoXY(D2_X_ABOUT + 26, D2_Y_ABOUT + 3);
	wcout << L"ADVANCED PROGRAMMING TECHNIQUE";

	GotoXY(D2_X_ABOUT + 32, D2_Y_ABOUT + 4);
	wcout << L"PROJECT CARO CHESS";

	GotoXY(D2_X_ABOUT + 5, D2_Y_ABOUT + 6);
	wcout << L"───────────────────────═══════ Instructor ═══════───────────────────────";
	GotoXY(D2_X_ABOUT + 30, D2_Y_ABOUT + 8);
	wcout << L"PhD. Trương Toàn Thịnh";
	GotoXY(D2_X_ABOUT + 5, D2_Y_ABOUT + 10);
	wcout << L"─────────────────────────═══════ Author ═══════─────────────────────────";

	GotoXY(D2_X_ABOUT + 25, D2_Y_ABOUT + 12);
	wcout << L"Nguyễn Đình Nhân";
	GotoXY(D2_X_ABOUT + 49, D2_Y_ABOUT + 12);
	wcout << L"22120246";

	GotoXY(D2_X_ABOUT + 25, D2_Y_ABOUT + 14);
	wcout << L"Nguyễn Lê Tấn Phát";
	GotoXY(D2_X_ABOUT + 49, D2_Y_ABOUT + 14);
	wcout << L"22120262";

	GotoXY(D2_X_ABOUT + 25, D2_Y_ABOUT + 16);
	wcout << L"Võ Hoàng Nguyên";
	GotoXY(D2_X_ABOUT + 49, D2_Y_ABOUT + 16);
	wcout << L"22120241";

	GotoXY(D2_X_ABOUT + 25, D2_Y_ABOUT + 18);
	wcout << L"Nguyễn Trọng Nhân";
	GotoXY(D2_X_ABOUT + 49, D2_Y_ABOUT + 18);
	wcout << L"22120248";

	GotoXY(D2_X_ABOUT + 25, D2_Y_ABOUT + 20);
	wcout << L"Nguyễn Minh Nguyên";
	GotoXY(D2_X_ABOUT + 49, D2_Y_ABOUT + 20);
	wcout << L"22120238";

	GotoXY(D2_X_ABOUT + 26, D2_Y_ABOUT + 22);
	wcout << D2_HCMUS_1;
	GotoXY(D2_X_ABOUT + 26, D2_Y_ABOUT + 23);
	wcout << D2_HCMUS_2;
	GotoXY(D2_X_ABOUT + 26, D2_Y_ABOUT + 24);
	wcout << D2_HCMUS_3;
	GotoXY(D2_X_ABOUT + 26, D2_Y_ABOUT + 25);
	wcout << D2_HCMUS_4;
	GotoXY(D2_X_ABOUT + 26, D2_Y_ABOUT + 26);
	wcout << D2_HCMUS_5;
	CurrentMode = _setmode(_fileno(stdout), OldMode);

	GotoXY(D2_X_ABOUT + 24, D2_Y_ABOUT + 28);
	cout << "Press Enter to return to Main Menu";

	return 0x0000;
}

void HandleKeyForAbout(int X, int Y, KEY_EVENT_RECORD key) {
	if (key.bKeyDown && key.wVirtualKeyCode == VK_RETURN) {
		if (D2_INGAME_MUSIC) PlaySound(TEXT("sounds//select.wav"), NULL, SND_FILENAME | SND_ASYNC);
		_KEYPRESSED = 1;
		_MENU = 0;
		_CURRENT_MENU = 0;
		system("cls");
	}
}
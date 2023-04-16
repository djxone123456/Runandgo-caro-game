#include "Settings.h"

void HandleKeyForSettings(int x, int y, KEY_EVENT_RECORD key) {
	if (key.bKeyDown) //Key pressed
		switch (key.wVirtualKeyCode) {
		case VK_RETURN: //Enter
			if (D2_INGAME_MUSIC) PlaySound(TEXT("sounds//select.wav"), NULL, SND_FILENAME | SND_ASYNC);
			system("cls");
			D2_WHICH_SETTING = 0;
			ExportSettings();
			_KEYPRESSED = 1;
			_MENU = 0;
			_CURRENT_MENU = 0;
			system("cls");
			break;
		case VK_LEFT: case 0x41: //Left arrow
			if (D2_INGAME_MUSIC) PlaySound(TEXT("sounds//switch-selection.wav"), NULL, SND_FILENAME | SND_ASYNC);
			if (D2_WHICH_SETTING == 0) {
				GotoXY(D2_X_SETTING + 53, D2_Y_SETTING + 5);
				TextColor(8);
				cout << D2_SELECT_LEFT;
				Sleep(150);
				GotoXY(D2_X_SETTING + 53, D2_Y_SETTING + 5);
				TextColor(0);
				cout << D2_SELECT_LEFT;
				D2_BACKGROUND_MUSIC--;
				if (D2_BACKGROUND_MUSIC < 0) D2_BACKGROUND_MUSIC = 1;
				GotoXY(D2_X_SETTING + 57, D2_Y_SETTING + 5);
				cout << D2_ON_OFF[D2_BACKGROUND_MUSIC];
				BackgroundMusic();
			}
			else {
				GotoXY(D2_X_SETTING + 53, D2_Y_SETTING + 7);
				TextColor(8);
				cout << D2_SELECT_LEFT;
				Sleep(150);
				GotoXY(D2_X_SETTING + 53, D2_Y_SETTING + 7);
				TextColor(0);
				cout << D2_SELECT_LEFT;
				D2_INGAME_MUSIC--;
				if (D2_INGAME_MUSIC < 0) D2_INGAME_MUSIC = 1;
				GotoXY(D2_X_SETTING + 57, D2_Y_SETTING + 7);
				cout << D2_ON_OFF[D2_INGAME_MUSIC];
			}
			break;
		case VK_RIGHT: case 0x44: //Right arrow
			if (D2_INGAME_MUSIC) PlaySound(TEXT("sounds//switch-selection.wav"), NULL, SND_FILENAME | SND_ASYNC);
			if (D2_WHICH_SETTING == 0) {
				GotoXY(D2_X_SETTING + 62, D2_Y_SETTING + 5);
				TextColor(8);
				cout << D2_SELECT_RIGHT;
				Sleep(150);
				GotoXY(D2_X_SETTING + 62, D2_Y_SETTING + 5);
				TextColor(0);
				cout << D2_SELECT_RIGHT;
				D2_BACKGROUND_MUSIC++;
				if (D2_BACKGROUND_MUSIC > 1) D2_BACKGROUND_MUSIC = 0;
				GotoXY(D2_X_SETTING + 57, D2_Y_SETTING + 5);
				cout << D2_ON_OFF[D2_BACKGROUND_MUSIC];
				BackgroundMusic();
			}
			else {
				GotoXY(D2_X_SETTING + 62, D2_Y_SETTING + 7);
				TextColor(8);
				cout << D2_SELECT_RIGHT;
				Sleep(150);
				GotoXY(D2_X_SETTING + 62, D2_Y_SETTING + 7);
				TextColor(0);
				cout << D2_SELECT_RIGHT;
				D2_INGAME_MUSIC++;
				if (D2_INGAME_MUSIC > 1) D2_INGAME_MUSIC = 0;
				GotoXY(D2_X_SETTING + 57, D2_Y_SETTING + 7);
				cout << D2_ON_OFF[D2_INGAME_MUSIC];
			}
			break;
		case VK_DOWN: case 0x53: //Down arrow
			if (D2_INGAME_MUSIC) PlaySound(TEXT("sounds//switch-selection.wav"), NULL, SND_FILENAME | SND_ASYNC);
			D2_WHICH_SETTING++;
			if (D2_WHICH_SETTING > 1) D2_WHICH_SETTING = 0;
			if (D2_WHICH_SETTING == 0) {
				GotoXY(D2_X_SETTING + 53, D2_Y_SETTING + 7);
				cout << " ";
				GotoXY(D2_X_SETTING + 62, D2_Y_SETTING + 7);
				cout << " ";
				GotoXY(D2_X_SETTING + 53, D2_Y_SETTING + 5);
				printf("%c", D2_SELECT_LEFT);
				GotoXY(D2_X_SETTING + 62, D2_Y_SETTING + 5);
				printf("%c", D2_SELECT_RIGHT);
			}
			else {
				GotoXY(D2_X_SETTING + 53, D2_Y_SETTING + 5);
				cout << " ";
				GotoXY(D2_X_SETTING + 62, D2_Y_SETTING + 5);
				cout << " ";
				GotoXY(D2_X_SETTING + 53, D2_Y_SETTING + 7);
				printf("%c", D2_SELECT_LEFT);
				GotoXY(D2_X_SETTING + 62, D2_Y_SETTING + 7);
				printf("%c", D2_SELECT_RIGHT);
			}
			break;
		case VK_UP: case 0x57: //Up arrow
			if (D2_INGAME_MUSIC) PlaySound(TEXT("sounds//switch-selection.wav"), NULL, SND_FILENAME | SND_ASYNC);
			D2_WHICH_SETTING--;
			if (D2_WHICH_SETTING < 0) D2_WHICH_SETTING = 1;
			if (D2_WHICH_SETTING == 0) {
				GotoXY(D2_X_SETTING + 53, D2_Y_SETTING + 7);
				cout << " ";
				GotoXY(D2_X_SETTING + 62, D2_Y_SETTING + 7);
				cout << " ";
				GotoXY(D2_X_SETTING + 53, D2_Y_SETTING + 5);
				printf("%c", D2_SELECT_LEFT);
				GotoXY(D2_X_SETTING + 62, D2_Y_SETTING + 5);
				printf("%c", D2_SELECT_RIGHT);
			}
			else {
				GotoXY(D2_X_SETTING + 53, D2_Y_SETTING + 5);
				cout << " ";
				GotoXY(D2_X_SETTING + 62, D2_Y_SETTING + 5);
				cout << " ";
				GotoXY(D2_X_SETTING + 53, D2_Y_SETTING + 7);
				printf("%c", D2_SELECT_LEFT);
				GotoXY(D2_X_SETTING + 62, D2_Y_SETTING + 7);
				printf("%c", D2_SELECT_RIGHT);
			}
			break;
		}
}

int Setting() {
	ShowCur(0);
	int OldMode = _setmode(_fileno(stdout), _O_WTEXT);
	int _pos_x = D2_X_SETTING + 9;
	for (int i = 0; i < D2_SETTINGS_1.size() - 1 - i; i += 2) {
		GotoXY(_pos_x + i, D2_Y_SETTING - 10);
		wcout << D2_SETTINGS_1[i] << D2_SETTINGS_1[i + 1];
		GotoXY(_pos_x + i, D2_Y_SETTING - 9);
		wcout << D2_SETTINGS_2[i] << D2_SETTINGS_2[i + 1];
		GotoXY(_pos_x + i, D2_Y_SETTING - 8);
		wcout << D2_SETTINGS_3[i] << D2_SETTINGS_3[i + 1];
		GotoXY(_pos_x + i, D2_Y_SETTING - 7);
		wcout << D2_SETTINGS_4[i] << D2_SETTINGS_4[i + 1];
		GotoXY(_pos_x + i, D2_Y_SETTING - 6);
		wcout << D2_SETTINGS_5[i] << D2_SETTINGS_5[i + 1];
		GotoXY(_pos_x + i, D2_Y_SETTING - 5);
		wcout << D2_SETTINGS_6[i] << D2_SETTINGS_6[i + 1];

		GotoXY(_pos_x + int(D2_SETTINGS_1.size()) - i - 2, D2_Y_SETTING - 10);
		wcout << D2_SETTINGS_1[D2_SETTINGS_1.size() - 2 - i] << D2_SETTINGS_1[D2_SETTINGS_1.size() - 1 - i];
		GotoXY(_pos_x + int(D2_SETTINGS_1.size()) - i - 2, D2_Y_SETTING - 9);
		wcout << D2_SETTINGS_2[D2_SETTINGS_1.size() - 2 - i] << D2_SETTINGS_2[D2_SETTINGS_1.size() - 1 - i];
		GotoXY(_pos_x + int(D2_SETTINGS_1.size()) - i - 2, D2_Y_SETTING - 8);
		wcout << D2_SETTINGS_3[D2_SETTINGS_1.size() - 2 - i] << D2_SETTINGS_3[D2_SETTINGS_1.size() - 1 - i];
		GotoXY(_pos_x + int(D2_SETTINGS_1.size()) - i - 2, D2_Y_SETTING - 7);
		wcout << D2_SETTINGS_4[D2_SETTINGS_1.size() - 2 - i] << D2_SETTINGS_4[D2_SETTINGS_1.size() - 1 - i];
		GotoXY(_pos_x + int(D2_SETTINGS_1.size()) - i - 2, D2_Y_SETTING - 6);
		wcout << D2_SETTINGS_5[D2_SETTINGS_1.size() - 2 - i] << D2_SETTINGS_5[D2_SETTINGS_1.size() - 1 - i];
		GotoXY(_pos_x + int(D2_SETTINGS_1.size()) - i - 2, D2_Y_SETTING - 5);
		wcout << D2_SETTINGS_6[D2_SETTINGS_1.size() - 2 - i] << D2_SETTINGS_6[D2_SETTINGS_1.size() - 1 - i];

		Sleep(10);
	}
	int CurrentMode = _setmode(_fileno(stdout), OldMode);

	for (int i = 0; i < 82; i += 2) {
		GotoXY(D2_X_SETTING + i, D2_Y_SETTING);
		cout << D2_LOWER_FRAME << D2_LOWER_FRAME;
		GotoXY(D2_X_SETTING + 80 - i, D2_Y_SETTING + 19);
		cout << D2_UPPER_FRAME << D2_UPPER_FRAME;
		Sleep(10);
	}

	for (int i = 1; i < 19; i += 2) {
		GotoXY(D2_X_SETTING + 81, D2_Y_SETTING + i);
		cout << D2_VERTICAL_FRAME;
		GotoXY(D2_X_SETTING + 81, D2_Y_SETTING + i + 1);
		cout << D2_VERTICAL_FRAME;
		GotoXY(D2_X_SETTING, D2_Y_SETTING + 19 - i);
		cout << D2_VERTICAL_FRAME;
		GotoXY(D2_X_SETTING, D2_Y_SETTING + 19 - i - 1);
		cout << D2_VERTICAL_FRAME;
		Sleep(10);
	}

	GotoXY(D2_X_SETTING + 18, D2_Y_SETTING + 5);
	printf("Background Music:");
	GotoXY(D2_X_SETTING + 18, D2_Y_SETTING + 7);
	printf("Ingame Sound:");

	GotoXY(D2_X_SETTING + 53, D2_Y_SETTING + 5);
	cout << D2_SELECT_LEFT;
	cout << "        ";
	cout << D2_SELECT_RIGHT;

	GotoXY(D2_X_SETTING + 57, D2_Y_SETTING + 5);
	cout << D2_ON_OFF[D2_BACKGROUND_MUSIC];
	GotoXY(D2_X_SETTING + 57, D2_Y_SETTING + 7);
	cout << D2_ON_OFF[D2_INGAME_MUSIC];

	GotoXY(D2_X_SETTING + 24, D2_Y_SETTING + 17);
	printf("Press Enter to apply your settings");

	return 0x0000; //Setting succeeded
}

void BackgroundMusic() {
	if (D2_BACKGROUND_MUSIC)
		mciSendString(L"play \"sounds//background-music.mp3\" repeat", NULL, 0, 0);
	else
		mciSendString(L"pause \"sounds//background-music.mp3\"", NULL, 0, 0);
}

int ExportSettings() {
	ofstream _setting_out("settings.json", ios::out);
	if (!_setting_out) return ErrorPopUp(0x0020); //Setting file not found
	_setting_out << D2_BACKGROUND_MUSIC << "\n" << D2_INGAME_MUSIC;
	_setting_out.close();
	return 0x0000; //Setting file is successfully opened
}

int ImportSettings() {
	ifstream _setting_in("settings.json", ios::in);
	if (!_setting_in) return ErrorPopUp(0x0020); //Setting file not found
	_setting_in >> D2_BACKGROUND_MUSIC >> D2_INGAME_MUSIC;
	_setting_in.close();
	return 0x0000; //Setting file is successfully opened
}
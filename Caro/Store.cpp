#include "Store.h"

//Input player name
static void D2_InputPlayerName(string& name) {
	while (1) {
		getline(cin, name);
		if (name.size() != 0) {
			ShowCur(0);
			GotoXY(D2_X_NEWGAME + 23, D2_Y_NEWGAME + 12);
			for (size_t i = 0; i < 36; i++) cout << " ";
			GotoXY(D2_X_NEWGAME + 23, D2_Y_NEWGAME + 13);
			for (size_t i = 0; i < 36; i++) cout << " ";
			while (name.size() > 12) name.pop_back();
			GotoXY(D2_X_NEWGAME + 4, D2_Y_NEWGAME + 2);
			printf("Welcome ");
			cout << name;
			if (D2_INGAME_MUSIC) PlaySound(TEXT("sounds//select.wav"), NULL, SND_FILENAME | SND_ASYNC);
			printf(", please choose your character!");
			break;
		}
		else GotoXY(D2_X_NEWGAME + 24, D2_Y_NEWGAME + 13);
	}
}

static void D2_ClearCharacter(int _x, int _y, int _range) {
	for (int i = 0; i < _range; i += 2) {
		GotoXY(_x + i, _y);
		cout << "  ";
		GotoXY(_x + i, _y + 1);
		cout << "  ";
		GotoXY(_x + i, _y + 2);
		cout << "  ";
		GotoXY(_x + i, _y + 3);
		cout << "  ";
		GotoXY(_x + i, _y + 4);
		cout << "  ";
	}
}

//Type name and choose character
int Store() {
	ShowCur(0);
	int OldMode = _setmode(_fileno(stdout), _O_WTEXT);
	if (D2_PLAYER == 1) {
		int _pos_x = D2_X_NEWGAME + 8;
		for (int i = 0; i < D2_PLAYER01_1.size() - 1 - i; i += 2) {
			GotoXY(_pos_x + i, D2_Y_NEWGAME - 8);
			wcout << D2_PLAYER01_1[i] << D2_PLAYER01_1[i + 1];
			GotoXY(_pos_x + i, D2_Y_NEWGAME - 7);
			wcout << D2_PLAYER01_2[i] << D2_PLAYER01_2[i + 1];
			GotoXY(_pos_x + i, D2_Y_NEWGAME - 6);
			wcout << D2_PLAYER01_3[i] << D2_PLAYER01_3[i + 1];
			GotoXY(_pos_x + i, D2_Y_NEWGAME - 5);
			wcout << D2_PLAYER01_4[i] << D2_PLAYER01_4[i + 1];
			GotoXY(_pos_x + i, D2_Y_NEWGAME - 4);
			wcout << D2_PLAYER01_5[i] << D2_PLAYER01_5[i + 1];
			GotoXY(_pos_x + i, D2_Y_NEWGAME - 3);
			wcout << D2_PLAYER01_6[i] << D2_PLAYER01_6[i + 1];

			GotoXY(_pos_x + int(D2_PLAYER01_1.size()) - i - 2, D2_Y_NEWGAME - 8);
			wcout << D2_PLAYER01_1[D2_PLAYER01_1.size() - 2 - i] << D2_PLAYER01_1[D2_PLAYER01_1.size() - 1 - i];
			GotoXY(_pos_x + int(D2_PLAYER01_1.size()) - i - 2, D2_Y_NEWGAME - 7);
			wcout << D2_PLAYER01_2[D2_PLAYER01_1.size() - 2 - i] << D2_PLAYER01_2[D2_PLAYER01_1.size() - 1 - i];
			GotoXY(_pos_x + int(D2_PLAYER01_1.size()) - i - 2, D2_Y_NEWGAME - 6);
			wcout << D2_PLAYER01_3[D2_PLAYER01_1.size() - 2 - i] << D2_PLAYER01_3[D2_PLAYER01_1.size() - 1 - i];
			GotoXY(_pos_x + int(D2_PLAYER01_1.size()) - i - 2, D2_Y_NEWGAME - 5);
			wcout << D2_PLAYER01_4[D2_PLAYER01_1.size() - 2 - i] << D2_PLAYER01_4[D2_PLAYER01_1.size() - 1 - i];
			GotoXY(_pos_x + int(D2_PLAYER01_1.size()) - i - 2, D2_Y_NEWGAME - 4);
			wcout << D2_PLAYER01_5[D2_PLAYER01_1.size() - 2 - i] << D2_PLAYER01_5[D2_PLAYER01_1.size() - 1 - i];
			GotoXY(_pos_x + int(D2_PLAYER01_1.size()) - i - 2, D2_Y_NEWGAME - 3);
			wcout << D2_PLAYER01_6[D2_PLAYER01_1.size() - 2 - i] << D2_PLAYER01_6[D2_PLAYER01_1.size() - 1 - i];

			Sleep(10);
		}
	}
	else {
		int _pos_x = D2_X_NEWGAME + 6;
		for (int i = 0; i < D2_PLAYER02_1.size() - 1 - i; i += 2) {
			GotoXY(_pos_x + i, D2_Y_NEWGAME - 8);
			wcout << D2_PLAYER02_1[i] << D2_PLAYER02_1[i + 1];
			GotoXY(_pos_x + i, D2_Y_NEWGAME - 7);
			wcout << D2_PLAYER02_2[i] << D2_PLAYER02_2[i + 1];
			GotoXY(_pos_x + i, D2_Y_NEWGAME - 6);
			wcout << D2_PLAYER02_3[i] << D2_PLAYER02_3[i + 1];
			GotoXY(_pos_x + i, D2_Y_NEWGAME - 5);
			wcout << D2_PLAYER02_4[i] << D2_PLAYER02_4[i + 1];
			GotoXY(_pos_x + i, D2_Y_NEWGAME - 4);
			wcout << D2_PLAYER02_5[i] << D2_PLAYER02_5[i + 1];
			GotoXY(_pos_x + i, D2_Y_NEWGAME - 3);
			wcout << D2_PLAYER02_6[i] << D2_PLAYER02_6[i + 1];

			GotoXY(_pos_x + int(D2_PLAYER02_1.size()) - i - 2, D2_Y_NEWGAME - 8);
			wcout << D2_PLAYER02_1[D2_PLAYER02_1.size() - 2 - i] << D2_PLAYER02_1[D2_PLAYER02_1.size() - 1 - i];
			GotoXY(_pos_x + int(D2_PLAYER02_1.size()) - i - 2, D2_Y_NEWGAME - 7);
			wcout << D2_PLAYER02_2[D2_PLAYER02_1.size() - 2 - i] << D2_PLAYER02_2[D2_PLAYER02_1.size() - 1 - i];
			GotoXY(_pos_x + int(D2_PLAYER02_1.size()) - i - 2, D2_Y_NEWGAME - 6);
			wcout << D2_PLAYER02_3[D2_PLAYER02_1.size() - 2 - i] << D2_PLAYER02_3[D2_PLAYER02_1.size() - 1 - i];
			GotoXY(_pos_x + int(D2_PLAYER02_1.size()) - i - 2, D2_Y_NEWGAME - 5);
			wcout << D2_PLAYER02_4[D2_PLAYER02_1.size() - 2 - i] << D2_PLAYER02_4[D2_PLAYER02_1.size() - 1 - i];
			GotoXY(_pos_x + int(D2_PLAYER02_1.size()) - i - 2, D2_Y_NEWGAME - 4);
			wcout << D2_PLAYER02_5[D2_PLAYER02_1.size() - 2 - i] << D2_PLAYER02_5[D2_PLAYER02_1.size() - 1 - i];
			GotoXY(_pos_x + int(D2_PLAYER02_1.size()) - i - 2, D2_Y_NEWGAME - 3);
			wcout << D2_PLAYER02_6[D2_PLAYER02_1.size() - 2 - i] << D2_PLAYER02_6[D2_PLAYER02_1.size() - 1 - i];

			Sleep(10);
		}
	}
	int CurrentMode = _setmode(_fileno(stdout), OldMode);

	for (int i = 0; i < 82; i += 2) {
		GotoXY(D2_X_NEWGAME + i, D2_Y_NEWGAME);
		cout << D2_LOWER_FRAME << D2_LOWER_FRAME;
		GotoXY(D2_X_NEWGAME + 80 - i, D2_Y_NEWGAME + 25);
		cout << D2_UPPER_FRAME << D2_UPPER_FRAME;
		Sleep(10);
	}

	for (int i = 1; i < 25; i += 2) {
		GotoXY(D2_X_NEWGAME + 81, D2_Y_NEWGAME + i);
		cout << D2_VERTICAL_FRAME;
		GotoXY(D2_X_NEWGAME + 81, D2_Y_NEWGAME + i + 1);
		cout << D2_VERTICAL_FRAME;
		GotoXY(D2_X_NEWGAME, D2_Y_NEWGAME + 25 - i);
		cout << D2_VERTICAL_FRAME;
		GotoXY(D2_X_NEWGAME, D2_Y_NEWGAME + 25 - i - 1);
		cout << D2_VERTICAL_FRAME;
		Sleep(10);
	}

	GotoXY(D2_X_NEWGAME + 23, D2_Y_NEWGAME + 12);
	printf("Type your name (less than 12 chars)");
	GotoXY(D2_X_NEWGAME + 23, D2_Y_NEWGAME + 13);
	cout << D2_CONSOLE_INPUT;
	ShowCur(1);
	if (D2_PLAYER == 1) D2_InputPlayerName(D2_PLAYER01_NAME);
	else D2_InputPlayerName(D2_PLAYER02_NAME);

	PrintCharacter(1, D2_X_NEWGAME + 44, D2_Y_NEWGAME + 10);

	GotoXY(D2_X_NEWGAME + 16, D2_Y_NEWGAME + 12);
	printf("%c", D2_SELECT_LEFT);
	wcout << L"   " << D2_CHAR_NAME[1] << L"   ";
	printf("%c", D2_SELECT_RIGHT);

	GotoXY(D2_X_NEWGAME + 24, D2_Y_NEWGAME + 23);
	printf("Press Enter to confirm your choice");

	return 0x0000;   //Store succeeded
}


void PrintCharacter(int code, int _x, int _y) {
	int OldMode = _setmode(_fileno(stdout), _O_WTEXT);
	switch (code) {
	case 0: {
		GotoXY(_x, _y);
		wcout << D2_COMPUTER_1;
		GotoXY(_x, _y + 1);
		wcout << D2_COMPUTER_2;
		GotoXY(_x, _y + 2);
		wcout << D2_COMPUTER_3;
		GotoXY(_x, _y + 3);
		wcout << D2_COMPUTER_4;
		GotoXY(_x, _y + 4);
		wcout << D2_COMPUTER_5;
		break;
	}
	case 1: {
		GotoXY(_x, _y);
		wcout << D2_BEAR_1;
		GotoXY(_x, _y + 1);
		wcout << D2_BEAR_2;
		GotoXY(_x, _y + 2);
		wcout << D2_BEAR_3;
		GotoXY(_x, _y + 3);
		wcout << D2_BEAR_4;
		GotoXY(_x, _y + 4);
		wcout << D2_BEAR_5;
		break;
	}
	case 2: {
		GotoXY(_x, _y);
		wcout << D2_ROBOT_1;
		GotoXY(_x, _y + 1);
		wcout << D2_ROBOT_2;
		GotoXY(_x, _y + 2);
		wcout << D2_ROBOT_3;
		GotoXY(_x, _y + 3);
		wcout << D2_ROBOT_4;
		GotoXY(_x, _y + 4);
		wcout << D2_ROBOT_5;
		break;
	}
	case 3: {
		GotoXY(_x, _y);
		wcout << D2_CAT_1;
		GotoXY(_x, _y + 1);
		wcout << D2_CAT_2;
		GotoXY(_x, _y + 2);
		wcout << D2_CAT_3;
		GotoXY(_x, _y + 3);
		wcout << D2_CAT_4;
		GotoXY(_x, _y + 4);
		wcout << D2_CAT_5;
		break;
	}
	case 4: {
		GotoXY(_x, _y);
		wcout << D2_ALIEN_1;
		GotoXY(_x, _y + 1);
		wcout << D2_ALIEN_2;
		GotoXY(_x, _y + 2);
		wcout << D2_ALIEN_3;
		GotoXY(_x, _y + 3);
		wcout << D2_ALIEN_4;
		GotoXY(_x, _y + 4);
		wcout << D2_ALIEN_5;
		break;
	}
	case 5: {
		GotoXY(_x, _y);
		wcout << D2_LION_1;
		GotoXY(_x, _y + 1);
		wcout << D2_LION_2;
		GotoXY(_x, _y + 2);
		wcout << D2_LION_3;
		GotoXY(_x, _y + 3);
		wcout << D2_LION_4;
		GotoXY(_x, _y + 4);
		wcout << D2_LION_5;
		break;
	}
	case 6: {
		GotoXY(_x, _y);
		wcout << D2_CROCODILE_1;
		GotoXY(_x, _y + 1);
		wcout << D2_CROCODILE_2;
		GotoXY(_x, _y + 2);
		wcout << D2_CROCODILE_3;
		GotoXY(_x, _y + 3);
		wcout << D2_CROCODILE_4;
		GotoXY(_x, _y + 4);
		wcout << D2_CROCODILE_5;
		break;
	}
	case 7: {
		GotoXY(_x, _y);
		wcout << D2_SNAKE_1;
		GotoXY(_x, _y + 1);
		wcout << D2_SNAKE_2;
		GotoXY(_x, _y + 2);
		wcout << D2_SNAKE_3;
		GotoXY(_x, _y + 3);
		wcout << D2_SNAKE_4;
		GotoXY(_x, _y + 4);
		wcout << D2_SNAKE_5;
		break;
	}
	case 8: {
		GotoXY(_x, _y);
		wcout << D2_CRAB_1;
		GotoXY(_x, _y + 1);
		wcout << D2_CRAB_2;
		GotoXY(_x, _y + 2);
		wcout << D2_CRAB_3;
		GotoXY(_x, _y + 3);
		wcout << D2_CRAB_4;
		GotoXY(_x, _y + 4);
		wcout << D2_CRAB_5;
		break;
	}
	case 9: {
		GotoXY(_x, _y);
		wcout << D2_TURTLE_1;
		GotoXY(_x, _y + 1);
		wcout << D2_TURTLE_2;
		GotoXY(_x, _y + 2);
		wcout << D2_TURTLE_3;
		GotoXY(_x, _y + 3);
		wcout << D2_TURTLE_4;
		GotoXY(_x, _y + 4);
		wcout << D2_TURTLE_5;
		break;
	}
	case 10: {
		GotoXY(_x, _y);
		wcout << D2_WHALE_1;
		GotoXY(_x, _y + 1);
		wcout << D2_WHALE_2;
		GotoXY(_x, _y + 2);
		wcout << D2_WHALE_3;
		GotoXY(_x, _y + 3);
		wcout << D2_WHALE_4;
		GotoXY(_x, _y + 4);
		wcout << D2_WHALE_5;
		break;
	}
	}
	int CurrentMode = _setmode(_fileno(stdout), OldMode);
}

static void ClearCharacterName(int _x, int _y, int range) {
	GotoXY(_x, _y);
	for (int i = 0; i < range; i += 2)
		cout << "  ";
}

static void D2_VK_RIGHT_CASE(int& _player_char) {
	GotoXY(D2_X_NEWGAME + 34, D2_Y_NEWGAME + 12);
	TextColor(8);
	cout << D2_SELECT_RIGHT;
	Sleep(150);
	GotoXY(D2_X_NEWGAME + 34, D2_Y_NEWGAME + 12);
	TextColor(0);
	cout << D2_SELECT_RIGHT;
	_player_char++;
	if (_player_char == 11) _player_char = 1;
	ClearCharacterName(D2_X_NEWGAME + 17, D2_Y_NEWGAME + 12, 16);
	switch (_player_char) {
	case 1: case 2: case 7: case 9: case 10: {
		GotoXY(D2_X_NEWGAME + 20, D2_Y_NEWGAME + 12);
		wcout << D2_CHAR_NAME[_player_char];
		break;
	}
	case 3: case 5: case 8: {
		GotoXY(D2_X_NEWGAME + 21, D2_Y_NEWGAME + 12);
		wcout << D2_CHAR_NAME[_player_char];
		break;
	}
	default: {
		GotoXY(D2_X_NEWGAME + 19, D2_Y_NEWGAME + 12);
		wcout << D2_CHAR_NAME[_player_char];
		break;
	}
	}
	D2_ClearCharacter(D2_X_NEWGAME + 44, D2_Y_NEWGAME + 10, 30);
	PrintCharacter(_player_char, D2_X_NEWGAME + 44, D2_Y_NEWGAME + 10);
}


static void D2_VK_LEFT_CASE(int& _player_char) {
	GotoXY(D2_X_NEWGAME + 16, D2_Y_NEWGAME + 12);
	TextColor(8);
	cout << D2_SELECT_LEFT;
	Sleep(150);
	GotoXY(D2_X_NEWGAME + 16, D2_Y_NEWGAME + 12);
	TextColor(0);
	cout << D2_SELECT_LEFT;
	_player_char--;
	if (_player_char == 0) _player_char = 10;
	ClearCharacterName(D2_X_NEWGAME + 17, D2_Y_NEWGAME + 12, 16);
	switch (_player_char) {
	case 1: case 2: case 7: case 9: case 10: {
		GotoXY(D2_X_NEWGAME + 20, D2_Y_NEWGAME + 12);
		wcout << D2_CHAR_NAME[_player_char];
		break;
	}
	case 3: case 5: case 8: {
		GotoXY(D2_X_NEWGAME + 21, D2_Y_NEWGAME + 12);
		wcout << D2_CHAR_NAME[_player_char];
		break;
	}
	default: {
		GotoXY(D2_X_NEWGAME + 19, D2_Y_NEWGAME + 12);
		wcout << D2_CHAR_NAME[_player_char];
		break;
	}
	}
	D2_ClearCharacter(D2_X_NEWGAME + 44, D2_Y_NEWGAME + 10, 30);
	PrintCharacter(_player_char, D2_X_NEWGAME + 44, D2_Y_NEWGAME + 10);
}


void HandleKeyForChoosingChar(int x, int y, KEY_EVENT_RECORD key) {
	if (key.bKeyDown) //Key pressed
		switch (key.wVirtualKeyCode) {
		case VK_RETURN: //Enter
			if (D2_INGAME_MUSIC) PlaySound(TEXT("sounds//select.wav"), NULL, SND_FILENAME | SND_ASYNC);
			system("cls");
			if (D2_PLAYER == 1) {
				if (D3_GameMode == 0) {
					D2_PLAYER02_CHARACTER = 0;
					StartGame();
				}
				else {
					D2_PLAYER = 2;

					system("cls");
					Store();
				}

			}
			else {
				StartGame();
			}
			break;
		case VK_LEFT: case 0x41: //Left arrow
			if (D2_INGAME_MUSIC) PlaySound(TEXT("sounds//switch-selection.wav"), NULL, SND_FILENAME | SND_ASYNC);
			if (D2_PLAYER == 1) D2_VK_LEFT_CASE(D2_PLAYER01_CHARACTER);
			else D2_VK_LEFT_CASE(D2_PLAYER02_CHARACTER);
			break;
		case VK_RIGHT: case 0x44: //Right arrow
			if (D2_INGAME_MUSIC) PlaySound(TEXT("sounds//switch-selection.wav"), NULL, SND_FILENAME | SND_ASYNC);
			if (D2_PLAYER == 1) D2_VK_RIGHT_CASE(D2_PLAYER01_CHARACTER);
			else D2_VK_RIGHT_CASE(D2_PLAYER02_CHARACTER);
			break;
		}
}
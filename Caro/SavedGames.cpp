#include "Control.h"

void DrawSavedBoard()
{
	ShowCur(0);
	int OldMode = _setmode(_fileno(stdout), _O_WTEXT);
	wstring l1 = L"███████╗ █████╗ ██╗   ██╗███████╗██████╗      ██████╗  █████╗ ███╗   ███╗███████╗  \n";
	wstring l2 = L"██╔════╝██╔══██╗██║   ██║██╔════╝██╔══██╗    ██╔════╝ ██╔══██╗████╗ ████║██╔════╝  \n";
	wstring l3 = L"███████╗███████║██║   ██║█████╗  ██║  ██║    ██║  ███╗███████║██╔████╔██║█████╗    \n";
	wstring l4 = L"╚════██║██╔══██║╚██╗ ██╔╝██╔══╝  ██║  ██║    ██║   ██║██╔══██║██║╚██╔╝██║██╔══╝    \n";
	wstring l5 = L"███████║██║  ██║ ╚████╔╝ ███████╗██████╔╝    ╚██████╔╝██║  ██║██║ ╚═╝ ██║███████╗  \n";
	wstring l6 = L"╚══════╝╚═╝  ╚═╝  ╚═══╝  ╚══════╝╚═════╝      ╚═════╝ ╚═╝  ╚═╝╚═╝     ╚═╝╚══════╝  \n";

	int x = 45, y = 4, x_last = 45 + int(l1.size());
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

		Sleep(3);
	}
	int CurrentMode = _setmode(_fileno(stdout), OldMode);
	for (int i = 0; i <= HMax_i; i += 2) {
		GotoXY(HLeft + i, 11);
		cout << Lower_Vertical << Lower_Vertical;
		GotoXY(HMax_i + HLeft - i, HMax_j);
		cout << Upper_Vertical << Upper_Vertical;
		Sleep(5);
	}

	for (int i = 1; i < HMax_j - 11; i += 2) {
		GotoXY(HMax_i + HLeft + 1, 11 + i);
		cout << Horizontal_Line;
		GotoXY(HMax_i + HLeft + 1, 11 + i + 1);
		cout << Horizontal_Line;
		GotoXY(HLeft, HMax_j - i);
		cout << Horizontal_Line;
		GotoXY(HLeft, HMax_j - i - 1);
		cout << Horizontal_Line;
		Sleep(5);
	}

}

// ESC Button + Load Button
void DrawButton()
{
	ShowCur(0);
	int OldMode = _setmode(_fileno(stdout), _O_WTEXT);
	wstring b1 = L"╔═══════╗/n";
	wstring b2 = L"║       ║/n";
	wstring b3 = L"╚═══════╝/n";

	GotoXY(45, 33);
	for (int j = 0; j < 9; j++)
		wcout << b1[j];
	GotoXY(45, 34);
	for (int j = 0; j < 9; j++)
		wcout << b2[j];
	GotoXY(45, 35);
	for (int j = 0; j < 9; j++)
		wcout << b3[j];

	GotoXY(116, 33);
	for (int j = 0; j < 9; j++)
		wcout << b1[j];
	GotoXY(116, 34);
	for (int j = 0; j < 9; j++)
		wcout << b2[j];
	GotoXY(116, 35);
	for (int j = 0; j < 9; j++)
		wcout << b3[j];

	int CurrentMode = _setmode(_fileno(stdout), OldMode);

	GotoXY(48, 34);
	cout << "ESC";
	GotoXY(55, 34);
	cout << "BACK";

	GotoXY(111, 34);
	cout << "LOAD";
	GotoXY(118, 34);
	cout << "ENTER";
	//(43 - 126)/2 = 41 -> mid 84
}

void DrawScore(int i, int x, int y)
{
	wstring Zero[3];
	Zero[0] = L"█▀▀█";
	Zero[1] = L"█▄▀█";
	Zero[2] = L"█▄▄█";
	wstring One[3];
	One[0] = L"▄█ ";
	One[1] = L" █ ";
	One[2] = L"▄█▄";

	wstring Two[3];
	Two[0] = L"█▀█";
	Two[1] = L" ▄▀";
	Two[2] = L"█▄▄";

	wstring Three[3];
	Three[0] = L"█▀▀█";
	Three[1] = L"  ▀▄";
	Three[2] = L"█▄▄█";

	wstring Four[3];
	Four[0] = L" █▀█";
	Four[1] = L"█▄▄█▄";
	Four[2] = L"   █";

	wstring Five[3];
	Five[0] = L"█▀▀";
	Five[1] = L"▀▀▄";
	Five[2] = L"▄▄▀";

	wstring Six[3];
	Six[0] = L"▄▀▀▄";
	Six[1] = L"█▄▄ ";
	Six[2] = L"▀▄▄▀";

	wstring Seven[3];
	Seven[0] = L"▀▀▀█";
	Seven[1] = L"  █";
	Seven[2] = L" ▐▌";

	wstring Eight[3];
	Eight[0] = L"▄▀▀▄";
	Eight[1] = L"▄▀▀▄";
	Eight[2] = L"▀▄▄▀";

	wstring Nine[3];
	Nine[0] = L"▄▀▀▄";
	Nine[1] = L"▀▄▄█";
	Nine[2] = L" ▄▄▀";

	int OldMode = _setmode(_fileno(stdout), _O_WTEXT);
	for (int j = 0; j < 3; j++)
	{
		GotoXY(x, y);
		if (i == 0)
			wcout << Zero[j];
		if (i == 1)
			wcout << One[j];
		if (i == 2)
			wcout << Two[j];
		if (i == 3)
			wcout << Three[j];
		if (i == 4)
			wcout << Four[j];
		if (i == 5)
			wcout << Five[j];
		if (i == 6)
			wcout << Six[j];
		if (i == 7)
			wcout << Seven[j];
		if (i == 8)
			wcout << Eight[j];
		if (i == 9)
			wcout << Nine[j];
		y++;
	}
	int CurrentMode = _setmode(_fileno(stdout), OldMode);
}

void PrintFileInfo(int x, int y, string Name)
{
	if (Name != "")
	{
		int i = 0;
		string str;
		ifstream FileName;
		FileName.open("SavedFiles\\" + Name, ios::in);
		getline(FileName, str);// Name Player 1
		GotoXY(Info_X + 18 - int(str.size()/2.0f), 16);
		cout << str;
		getline(FileName, str);// Name Player 2
		GotoXY(Info_X + 39 - int(str.size() / 2.0f), 16);
		cout << str;
		FileName >> i;
		DrawScore(i, Info_X + 16, 19);
		FileName >> i;
		DrawScore(i, Info_X + 37, 19);
		GotoXY(Info_X + 21, 24);
		cout << "Draw Point: ";
		GotoXY(Info_X + 34, 24);
		FileName >> i;//Draw point
		cout << i;
		FileName.close();
		wstring Line = L"▀▀▀";
		int OldMode = _setmode(_fileno(stdout), _O_WTEXT);
		GotoXY(Info_X + 27, 20);
		wcout << Line;
		int CurrentMode = _setmode(_fileno(stdout), OldMode);
	}
}

void PrintFileName(string Name[])// array of file name
{
	ifstream FileName;
	FileName.open("SavedFiles\\fileLoad.json", ios::in);
	int y = Name_Y;//postion x, y of name
	if (FileName.fail())
	{
		//error file 
	}
	string str;
	int i = 0;
	getline(FileName, str);
	if (str == "")
		cout << "No file found !";
	else
	{
		GotoXY(Name_X - 3, Name_Y);
		cout << D2_SELECT_RIGHT;
		Name[0] = str;

		PrintFileInfo(Info_X, Info_Y, Name[0]);

		GotoXY(Name_X, y);
		cout << str << endl;
		y = y + 2; i++;
		while (getline(FileName, str))
		{
			if (i == 9 || str == "\n") break;
			Name[i] = str;
			GotoXY(Name_X, y);
			cout << str << endl;
			y = y + 2; i++;
		}
		Numb_of_file = i;
	}
	FileName.close();
}

Load File;

void LoadGame(Load& File, string Name)
{
	string str;
	ifstream FileName;
	FileName.open("SavedFiles\\" + Name, ios::in);
	getline(FileName, str);
	File.NamePL1 = str;
	getline(FileName, str);
	File.NamePL2 = str;
	FileName >> File.Point_1;
	FileName >> File.Point_2;
	FileName >> File.Draw;
	FileName >> File.Character_1;
	FileName >> File.Character_2;
	FileName >> File.Result;
	FileName >> File.Turn;
	FileName.ignore();
	for (int j = 0; j < 18 * 18; j++)
		FileName >> File.Table[j];
	FileName.close();
}

void ConvertData(Load File) //Goto game play
{
	system("cls");
	D2_PLAYER01_NAME = File.NamePL1;
	D2_PLAYER02_NAME = File.NamePL2;
	Score1 = File.Point_1;
	Score2 = File.Point_2;
	Draw = File.Draw;
	D2_PLAYER01_CHARACTER = File.Character_1;
	D2_PLAYER02_CHARACTER = File.Character_2;
	Turn = File.Turn;
	Finish = File.Result;
	int cnt = 0;
	if (Finish == 1) {
		ClearMatrix();
	}
	else if (Finish == 0) {
		for (int i = 0; i < BOARD_SIZE; i++) {
			for (int j = 0; j < BOARD_SIZE; j++) {
				_MATRIX[i][j] = File.Table[cnt];
				cnt++;
				if (_MATRIX[i][j] != '-') Count++;
			}
		}
	}
}

void DeleteInfo()
{
	for (int i = 0; i < 9; i++)
	{
		GotoXY(Info_X, 16 + i);
		
		for (int j = 0; j <= HLeft + 1; j++)
			cout << " ";

	}
}

void HandleKeyForLoad(int x, int y, KEY_EVENT_RECORD key)
{
	if (key.bKeyDown) //Key pressed
		switch (key.wVirtualKeyCode) {
		case VK_RETURN: //Enter
			if (D2_INGAME_MUSIC) PlaySound(TEXT("Sounds//select.wav"), NULL, SND_FILENAME | SND_ASYNC);
			LoadGame(File, Name[Locate - 1]);
			isLoadFile = 1;
			loadedFileName = Name[Locate - 1];
			for (int i = 0; i < 4; i++) loadedFileName.pop_back();
			system("cls");
			ConvertData(File);
			if (D2_PLAYER02_NAME == "Mega Roboto") D3_GameMode = 0;
			else D3_GameMode = 1;
			StartGame();
			Locate = 1;
			_CURRENT_MENU = 9;
			break;
			//Then load data from struct Load to play board
		case VK_DOWN: case 0x53:
			GotoXY(Name_X - 3, Name_Y + 2 * Locate - 2);
			cout << " ";
			if (D2_INGAME_MUSIC) PlaySound(TEXT("Sounds//switch-selection.wav"), NULL, SND_FILENAME | SND_ASYNC);
			Locate++;
			if (Locate == Numb_of_file + 1)
				Locate = 1;
			GotoXY(Name_X - 3, Name_Y + 2 * Locate - 2);
			cout << D2_SELECT_RIGHT;
			DeleteInfo();
			PrintFileInfo(Info_X, Info_Y, Name[Locate - 1]);
			break;
		case VK_UP: case 0x57:
			GotoXY(Name_X - 3, Name_Y + 2 * Locate - 2);
			cout << " ";
			if (D2_INGAME_MUSIC) PlaySound(TEXT("Sounds//switch-selection.wav"), NULL, SND_FILENAME | SND_ASYNC);
			Locate--;
			if (Locate == 0)
				Locate = Numb_of_file;
			GotoXY(Name_X - 3, Name_Y + 2 * Locate - 2);
			cout << D2_SELECT_RIGHT;
			DeleteInfo();
			PrintFileInfo(Info_X, Info_Y, Name[Locate - 1]);
			break;
		case VK_ESCAPE: //Esc
			if (D2_INGAME_MUSIC) PlaySound(TEXT("Sounds//select.wav"), NULL, SND_FILENAME | SND_ASYNC);
			Locate = 1;
			_KEYPRESSED = 1;
			_MENU = 0;
			_CURRENT_MENU = 0;
			break;
		}
}
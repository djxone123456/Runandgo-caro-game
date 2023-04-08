#include "SavedGames.h"

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

	int x = 45, y = 4, x_last = 45 + l1.size();
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

void PrintFileName(string Name[])// mang Name luu ten cac file de lay thong tin
{
	GotoXY(Name_X - 3, Name_Y);
	cout << D2_SELECT_RIGHT;
	ifstream FileName;
	FileName.open("SavedFiles\\fileLoad.json", ios::in);
	int y = Name_Y;//toa do ten 
	if (FileName.fail())
	{
		//error file 
	}
	string str;
	int i = 0;
	FileName >> Numb_of_file;
	getline(FileName, str);
	while (getline(FileName, str))
	{
		Name[i] = str;
		GotoXY(Name_X, y);
		cout << str << endl;
		y = y + 2; i++;
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
	FileName.ignore();
	getline(FileName, str);
	File.Character_1 = str;
	getline(FileName, str);
	File.Character_2 = str;
	FileName >> File.Result;
	FileName.ignore();
	getline(FileName, str);
	File.Turn = str;
	for (int j = 0; j < 16 * 16; j++)
		FileName >> File.Table[j];
	FileName.close();
	//Load Data from struct Load File
	//GameBoard()
}

void PrintData(Load File) //Goto game play
{
	system("cls");
	GotoXY(0, 0);
	cout << File.NamePL1 << endl;
	cout << File.NamePL2 << endl;
	cout << File.Point_1 << endl;
	cout << File.Point_2 << endl;
	cout << File.Draw << endl;
	cout << File.Character_1 << endl;
	cout << File.Character_1 << endl;
	cout << File.Result << endl;
	cout << File.Turn << endl;
	int i = 0;
	while (cout << File.Table[i])
	{
		i++;
		if ((i) % 16 == 0)
			cout << endl;
		if (i + 1 == 16 * 16)
			break;
	}

}

void PrintFileInfo(int x, int y, string Name)
{
	int i = 0;
	string str;
	ifstream FileName;
	FileName.open("SavedFiles\\" + Name, ios::in);
	//GotoXY(87, 14);
	//cout << "PLAYER 1";
	//GotoXY(107, 14);
	//cout << "PLAYER 2";
	//GotoXY(Info_X, 16);
	//cout << "Name: ";
	GotoXY(Info_X + 13, 16);
	getline(FileName, str);// Name Player 1
	cout << str;
	GotoXY(Info_X + 33, 16);
	getline(FileName, str);// Name Player 2
	cout << str;
	/*GotoXY(Info_X, 20);
	cout << "Point: ";*/
	//GotoXY(Info_X + 18, 20);
	//getline(FileName, str);//Point player 1
	//cout << str;
	FileName >> i;
	DrawScore(i, Info_X + 16, 19);
	//GotoXY(Info_X + 38, 20);
	//getline(FileName, str);//Point player 2
	//cout << str;
	FileName >> i;
	DrawScore(i, Info_X + 37, 19);
	GotoXY(Info_X + 21, 24);
	cout << "Draw Point: ";
	GotoXY(Info_X + 34, 24);
	FileName >> i;//Draw point
	cout << i;
	//GotoXY(Info_X, 18);
	//cout << "Character: ";
	//GotoXY(Info_X + 13, 18);
	//getline(FileName, str);//Character 1
	//cout << str;
	//GotoXY(Info_X + 33, 18);
	//getline(FileName, str);//Character 2
	//cout << str;
	//GotoXY(Info_X, 24);
	//cout << "Turn: ";
	//getline(FileName, str);//end or not
	//getline(FileName, str);//Player turn
	//cout << str;
	FileName.close();
	wstring Line = L"▀▀▀";
	int OldMode = _setmode(_fileno(stdout), _O_WTEXT);
	GotoXY(Info_X + 27, 20);
	wcout << Line;
	int CurrentMode = _setmode(_fileno(stdout), OldMode);
}

void PrintFirstFileInfo()
{
	PrintFileInfo(Info_X, Info_Y, Name[Locate - 1]);
}

void DeleteInfo()
{
	for (int i = 0; i < 8; i++)
	{
		GotoXY(85, 16 + i);
		cout << "                                        ";

	}
}

void HandleKeyForLoad(int x, int y, KEY_EVENT_RECORD key)
{
	if (key.bKeyDown) //Key pressed
		switch (key.wVirtualKeyCode) {
		case VK_RETURN: //Enter
			PlaySound(TEXT("Sounds//select.wav"), NULL, SND_FILENAME | SND_ASYNC);
			LoadGame(File, Name[Locate - 1]);
			system("cls");
			PrintData(File);
			break;
			//Then load data from struct Load to play board
		case VK_DOWN: case 0x53:
			GotoXY(Name_X - 3, Name_Y + 2 * Locate - 2);
			cout << " ";
			PlaySound(TEXT("Sounds//select.wav"), NULL, SND_FILENAME | SND_ASYNC);
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
			PlaySound(TEXT("Sounds//select.wav"), NULL, SND_FILENAME | SND_ASYNC);
			Locate--;
			if (Locate == 0)
				Locate = Numb_of_file;
			GotoXY(Name_X - 3, Name_Y + 2 * Locate - 2);
			cout << D2_SELECT_RIGHT;
			DeleteInfo();
			PrintFileInfo(Info_X, Info_Y, Name[Locate - 1]);
			break;
		case VK_ESCAPE: //Esc
			_KEYPRESSED = 1;
			_MENU = 0;
			_CURRENT_MENU = 0;
			break;
		}
}

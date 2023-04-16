#include "Error.h"

int ErrorPopUp(const int ErrorCommand)
{
	ShowCur(0);
	CreateFrame(65, 16, 105, 26);
	int OldMode = _setmode(_fileno(stdout), _O_WTEXT);
	GotoXY(70, 19);
	TextColor(4);

	AllignCenterWString(D1_POINT(67, 17, L"▄▄▄▄▄▄▄▄▄", 94 - 67 + 1));
	AllignCenterWString(D1_POINT(67, 18, L"▌▄▌▄▐▐▌██", 94 - 67 + 1));
	AllignCenterWString(D1_POINT(67, 19, L"▌▄▌▄▐▐▌▀█", 94 - 67 + 1));
	AllignCenterWString(D1_POINT(67, 20, L"▀▀▀▀▀▀▀▀▀", 94 - 67 + 1));

	TextColor(0);
	int CurrentMode = _setmode(_fileno(stdout), OldMode);

	AllignCenterString(D1_POINT(67, 21, "Error " + to_string(ErrorCommand) + ":", 104 - 67 + 1));

	switch (ErrorCommand)
	{
		case 0x0001:
		AllignCenterString(D1_POINT(67, 22, "Unable to load fileLoad.json", 104 - 67 + 1));
			break;
		case 0x0015:
			AllignCenterString(D1_POINT(67, 22, "Allocate memory unsuccessfully", 104 - 67 + 1));
			break;
		case 0x0020:
			AllignCenterString(D1_POINT(67, 22, "Setting file not found", 104 - 67 + 1));
			break;
		default:
			AllignCenterString(D1_POINT(67, 22, "Undetermined error", 104 - 67 + 1));
			break;
	}

	AllignCenterString(D1_POINT(67, 24, "Press any key to exit", 104 - 67 + 1));

	while (true)
	{
		HandleEvent(0, 0, HandleKeyForError);
	}
	return 0;
}

static void AllignCenterWString(const D1_POINT Param)
{
	GotoXY(Param.x, Param.y);
	int Space = max(0, (Param.width - (int)Param.Name.size()) / 2);

	for (int i = 0; i < Space; i++) wcout << L" ";
	for (int i = 0; i < min(Param.width, (int)Param.WName.size()); i++)
		wcout << Param.WName[i];
}

static void AllignCenterString(const D1_POINT Param)
{
	GotoXY(Param.x, Param.y);
	int Space = max(0, (Param.width - (int)Param.Name.size()) / 2);

	for (int i = 0; i < Space; i++) cout << " ";
	for (int i = 0; i < min(Param.width, (int)Param.Name.size()); i++)
		cout << Param.Name[i];
}

static void CreateFrame(int TopLeftX, int TopLeftY, int BottomRightX, int BottomRightY)
{
	DeleteFrame(TopLeftX, TopLeftY, BottomRightX, BottomRightY);

	TextColor(1);
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
	TextColor(0);
}

static void DeleteFrame(int TopLeftX, int TopLeftY, int BottomRightX, int BottomRightY)
{
	for (int j = TopLeftY; j <= BottomRightY; j++)
	{
		GotoXY(TopLeftX, j);
		for (int i = TopLeftX; i <= BottomRightX; i++)
			cout << ' ';
	}
}

void HandleKeyForError(int x, int y, KEY_EVENT_RECORD key)
{
	if (key.bKeyDown) //Key pressed
	{
		system("cls");
		exit(0);
	}
}
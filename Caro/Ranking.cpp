#include "Ranking.h"

int Ranking()
{
	TopRanking* arr = new TopRanking[5];

	#ifdef DEBUG_RANKING
		Init(arr);  
	#endif

	InitRankingFile(L"SavedFiles//", L"fileLoad.json", arr);

	//InitRankingFile(ExePath() + L"//SavedFiles//", L"fileLoad.json", arr);
	TopPlayerLogo(21, 13);
	CreateRankingStep(22, 18, 20, 10, 7, 4, arr);
	CreateRankingTable(22, 29, arr);

	return 0x0000;
}

static wstring ExePath() {
	TCHAR buffer[MAX_PATH] = { 0 };
	GetModuleFileName(NULL, buffer, MAX_PATH);
	wstring::size_type pos = std::wstring(buffer).find_last_of(L"\\/");
	wstring dis = wstring(buffer).substr(0, pos);

	if (dis.substr(dis.size() - 5, 5) == L"Debug") dis.erase(dis.size() - 6, 6);
	return dis;
} 

static void CreateBar(int x, int y, int width, int height)
{
	int OldMode = _setmode(_fileno(stdout), _O_WTEXT);
	
	for (int i = 0; i < width; i++)
	{
		GotoXY(x + i, y);
		wcout << DarkSquareBox;
	}

	for (int i = 1; i < height - 1; i++)
	{
		GotoXY(x, y + i);
		wcout << DarkSquareBox;
		wcout << DarkSquareBox;
		for (int j = 2; j < width - 2; j++)
			wcout << GraySquareBox;
		wcout << DarkSquareBox;
		wcout << DarkSquareBox;
	}

	for (int i = 0; i < width; i++)
	{
		GotoXY(x + i, y + height - 1);
		wcout << DarkSquareBox;
	}
	int CurrentMode = _setmode(_fileno(stdout), OldMode);
}

static void TopPlayerLogo(int x, int y)
{
	int OldMode = _setmode(_fileno(stdout), _O_WTEXT);
	GotoXY(x, y);
	wcout << D1_TOPPLAYERS_1;
	GotoXY(x, y + 1);
	wcout << D1_TOPPLAYERS_2;
	GotoXY(x, y + 2);
	wcout << D1_TOPPLAYERS_3;
	int CurrentMode = _setmode(_fileno(stdout), OldMode);
}

static void CreateRankingStep(int x, int y, int width, int Top1_height, int Top2_height, int Top3_height, TopRanking* arr)
{
	//Init frame
	CreateBar(x, y + (Top1_height - Top3_height), width + 2, Top3_height);
	CreateBar(x + width, y, width, Top1_height);
	CreateBar(x + 2 * width - 2, y + (Top1_height - Top2_height), width + 2, Top2_height);

	//Display data
	AllignCenter(D1_POINT(x, y + (Top1_height - Top3_height) - 1, (arr + 2)->Name, width));
	AllignCenter(D1_POINT(x + width, y - 1, (arr + 0)->Name, width));
	AllignCenter(D1_POINT(x + 2 * width, y + (Top1_height - Top2_height) - 1, (arr + 1)->Name, width));
}

static void AllignCenter(const D1_POINT Param) // Need to change
{
	GotoXY(Param.x, Param.y);
	int Space = max(0, (Param.width - (int)Param.Name.size()) / 2);
	
	for (int i = 0; i < Space; i++) cout << " ";
	for (int i = 0; i < min(Param.width, (int)Param.Name.size()); i++)
		cout << Param.Name[i];
}

static void SplittingLine(int x, int y)
{
	for (int i = 1; i < 8; i++)
	{
		GotoXY(x, y + i); 
		cout << VERTICAL_LINE_LIGHT;
	}

	GotoXY(x, y);
	cout << T_SHAPE_DOWN_LIGHT;
	GotoXY(x, y + 2);
	cout << CROSS_LIGHT;
	GotoXY(x, y + 8);
	cout << T_SHAPE_UP_LIGHT;
}

static void CreateRankingTable(int x, int y, TopRanking* arr)
{
	GotoXY(x, y);
	cout << LEFT_TOP_LIGHT;
	for (int i = x; i < x + 59; i++)
		cout << HORIZONTAL_LINE_LIGHT;
	cout << RIGHT_TOP_LIGHT;

	GotoXY(x, y + 1); cout << VERTICAL_LINE_LIGHT;
	GotoXY(x + 60, y + 1); cout << VERTICAL_LINE_LIGHT;

	GotoXY(x, y + 2); 
	cout << T_SHAPE_RIGHT_LIGHT;
	for (int i = x; i < x + 59; i++)
		cout << HORIZONTAL_LINE_LIGHT;
	cout << T_SHAPE_LEFT_LIGHT;
	
	for (int Y = y + 3; Y < y + 8; Y++)
	{
		GotoXY(x, Y); cout << VERTICAL_LINE_LIGHT;
		GotoXY(x + 60, Y); cout << VERTICAL_LINE_LIGHT;
	}
	
	GotoXY(x, y + 8);
	cout << LEFT_BOTTOM_LIGHT;
	for (int i = x; i < x + 59; i++)
		cout << HORIZONTAL_LINE_LIGHT;
	cout << RIGHT_BOTTOM_LIGHT;

	SplittingLine(x + 6, y);
	SplittingLine(x + 36, y);
	SplittingLine(x + 44, y);
	SplittingLine(x + 52, y);

	AllignCenter(D1_POINT(x + 1, y + 1, "Pos", 5));
	AllignCenter(D1_POINT(x + 7, y + 1, "Name", 30));
	AllignCenter(D1_POINT(x + 37, y + 1, "Wins", 44 - 37));
	AllignCenter(D1_POINT(x + 45, y + 1, "Draws", 52 - 45));
	AllignCenter(D1_POINT(x + 53, y + 1, "Loses", 59 - 52));

	//Display data
	for (int i = 1; i <= 5; i++)
	{
		AllignCenter(D1_POINT(x + 1, y + 2 + i, to_string(i), 5));
		AllignCenter(D1_POINT(x + 37, y + 2 + i, to_string((arr + i - 1)->Wins), 44 - 37));
		AllignCenter(D1_POINT(x + 45, y + 2 + i, to_string((arr + i - 1)->Draws), 52 - 45));
		AllignCenter(D1_POINT(x + 53, y + 2 + i, to_string((arr + i - 1)->Loses), 59 - 52));
		GotoXY(x + 7, y + 2 + i);
		cout << (arr + i - 1)->Name;
	}
}

#ifdef DEBUG_RANKING
static void Init(TopRanking* arr) //DEBUG
{
	for (int i = 0; i < 5; i++)
	{
		arr[i] = TopRanking("Lmao", 10);
	}
}
#endif

static void UpdatePlayer(const string Name, int Wins, int Loses, int Draws = 0) // Have to change
{
	TopRanking tmp = RankMap[Name];
	tmp.Name = Name;
	tmp.Draws += Draws;
	tmp.Wins += Wins;
	tmp.Loses += Loses;
	RankMap[Name] = tmp;
}

static int StringToInt(const string& n)
{
	int val = 0;
	for (char i : n)
		if (i >= '0' && i <= '9') val = val * 10 + ((int)i - '0');
	return val;
}

static int InitRankingFile(const wstring dir, const wstring SystemFileName, TopRanking*& arr)
{
	RankMap.clear();
	RankSet.clear();
	ifstream input;
	input.open(dir + SystemFileName);
	if (input.fail()) return ErrorPopUp(0x0001);
	
	/*int nItem;
	input >> nItem;*/
	
	string FileDir;
	while (getline(input, FileDir))
	{
		ifstream FileInput;

		wstring wsTmp(FileDir.begin(), FileDir.end());
		FileInput.open(dir + wsTmp);

		if (FileInput.fail()) {
			FileInput.close();
			continue; // If any files are error, don't waste time to try
		}

		string Player[2];
		string PlayerPoint[2];
		
		for (int i = 0; i < 2; i++)
			getline(FileInput, Player[i]);

		if (FileInput.eof()) continue;

		for (int i = 0; i < 2; i++)
			FileInput >> PlayerPoint[i];

		for (int i = 0; i < 2; i++)
		{
			UpdatePlayer(Player[i], StringToInt(PlayerPoint[i]), StringToInt(PlayerPoint[1 - i]));
		}

		FileInput.close();
	}

	input.close();

	for (auto val : RankMap)
	{
		RankSet.push_back(val.second);
	}

	sort(RankSet.begin(), RankSet.end(), Compare);

	for (int i = 0; i < min(RankSet.size(), 5); i++)
		arr[i] = RankSet[i];

	return 0x0000;
}
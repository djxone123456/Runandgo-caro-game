#pragma once
#ifndef RANKING_H
#define RANKING_H
//#define DEBUG_RANKING

#include "Control.h"
#include "View.h"
#include "Data.h"
#include "Error.h"

using namespace std;

//DEFINES
struct TopRanking
{
	string Name;
	int Wins, Loses, Draws;
	TopRanking(string _Name = "<NO DATA>", int _Wins = 0, int _Draws = 0, int _Loses = 0) //Set default
	{
		Name = _Name;
		Wins = _Wins;
		Loses = _Loses;
		Draws = _Draws;
		if (Name.empty()) Name = "<NO DATA>";
	}
};

static bool Compare(TopRanking i, TopRanking j) { return (i.Wins > j.Wins); }

const wstring GraySquareBox = L"▓";
const wstring DarkSquareBox = L"█";
const wstring DarkBottomHalf = L"▄";
const wstring DarkTopHalf = L"▀";

//VARIABLES

static map <string, TopRanking> RankMap; //Ranking guarantee: -> Number -> Name -> TopRanking(Data) 
static vector <TopRanking> RankSet;

//DEBUG
#ifdef DEBUG_RANKING
static void Init(TopRanking* arr);

#endif

//FUNCTIONS HERE
static wstring ExePath();
static int StringToInt(const string&);
static void UpdatePlayer(const string, int, int, int);
static int InitRankingFile(const wstring, const wstring, TopRanking*&);
static void AllignCenter(const D1_POINT);
static void SplittingLine(int, int);
static void TopPlayerLogo(int, int);
static void CreateBar(int, int, int, int);
static void CreateRankingStep(int, int, int, int, int, int, TopRanking*);
static void CreateRankingTable(int, int, TopRanking*);
int Ranking();

#endif
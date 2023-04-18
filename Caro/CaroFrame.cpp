#include "view.h"
#include "Control.h"
#include "D5_data.h"
#include "D2_data.h"
#include "Data.h"

void ClearMatrix() {
	for (int i = 0; i < BOARD_SIZE; i++) {
		for (int j = 0; j < BOARD_SIZE; j++) {
			_MATRIX[i][j] = '-';
		}
	}
}

//Usage: Check if there are 5 continuous <symbol>. If true return 1 (win), else return 0 (not win)
bool Check_Win(const char symbol, const int x_pos, const int y_pos) {
	int cur_row = y_pos / 2 - int(FIRST_CELL_Y) / 2;
	int cur_col = x_pos / 4 - int(FIRST_CELL_X) / 4;

	int vertical_01 = 0;
	int vertical_02 = 0;

	int horizontal_01 = 0;
	int horizontal_02 = 0;

	int main_cross_01 = 0;
	int main_cross_02 = 0;

	int sub_cross_01 = 0;
	int sub_cross_02 = 0;

	//Horizontal check
	for (int i = cur_col + 1; i < BOARD_SIZE; i++) {
		if (_MATRIX[cur_row][i] != symbol) break;
		horizontal_01++;
	}

	for (int i = cur_col - 1; i >= 0; i--) {
		if (_MATRIX[cur_row][i] != symbol) break;
		horizontal_02++;
	}

	if ((horizontal_01 + horizontal_02) >= 4) {
		ShowCur(0);
		for (int k = 0; k < 20; k++) {
			for (int i = 0; i < (horizontal_01 + horizontal_02) + 1; i++) {
				GotoXY(x_pos - horizontal_02 * 4 + 4 * i, y_pos);
				if (k % 2 == 0) PrintTextColor_Char(toupper(symbol), 4);
				else PrintTextColor_Char(toupper(symbol), 6);
			}
			Sleep(50);
		}
		return 1; //Win
	}

	//Vertical check
	for (int i = cur_row + 1; i < BOARD_SIZE; i++) {
		if (_MATRIX[i][cur_col] != symbol) break;
		vertical_01++;
	}

	for (int i = cur_row - 1; i >= 0; i--) {
		if (_MATRIX[i][cur_col] != symbol) break;
		vertical_02++;
	}

	if ((vertical_01 + vertical_02) >= 4) {
		ShowCur(0);
		for (int k = 0; k < 20; k++) {
			for (int i = 0; i < (vertical_01 + vertical_02) + 1; i++) {
				GotoXY(x_pos, y_pos - vertical_02 * 2 + 2 * i);
				if (k % 2 == 0) PrintTextColor_Char(toupper(symbol), 4);
				else PrintTextColor_Char(toupper(symbol), 6);
			}
			Sleep(50);
		}
		return 1; //Win
	}

	//Main cross check
	for (int i = cur_row + 1, j = cur_col + 1; i < BOARD_SIZE && j < BOARD_SIZE; i++, j++) {
		if (_MATRIX[i][j] != symbol) break;
		main_cross_01++;
	}

	for (int i = cur_row - 1, j = cur_col - 1; i >= 0 && j >= 0; i--, j--) {
		if (_MATRIX[i][j] != symbol) break;
		main_cross_02++;
	}

	if ((main_cross_01 + main_cross_02) >= 4) {
		ShowCur(0);
		for (int k = 0; k < 20; k++) {
			for (int i = 0; i < (main_cross_01 + main_cross_02) + 1; i++) {
				GotoXY(x_pos - main_cross_02 * 4 + 4 * i, y_pos - main_cross_02 * 2 + 2 * i);
				if (k % 2 == 0) PrintTextColor_Char(toupper(symbol), 4);
				else PrintTextColor_Char(toupper(symbol), 6);
			}
			Sleep(50);
		}
		return 1; //Win
	}

	//Sub cross check
	for (int i = cur_row - 1, j = cur_col + 1; i >= 0 && j < BOARD_SIZE; i--, j++) {
		if (_MATRIX[i][j] != symbol) break;
		sub_cross_01++;
	}

	for (int i = cur_row + 1, j = cur_col - 1; i < BOARD_SIZE && j >= 0; i++, j--) {
		if (_MATRIX[i][j] != symbol) break;
		sub_cross_02++;
	}

	if ((sub_cross_01 + sub_cross_02) >= 4) {
		ShowCur(0);
		for (int k = 0; k < 20; k++) {
			for (int i = 0; i < (sub_cross_01 + sub_cross_02) + 1; i++) {
				GotoXY(x_pos - sub_cross_02 * 4 + 4 * i, y_pos + sub_cross_02 * 2 - 2 * i);
				if (k % 2 == 0) PrintTextColor_Char(toupper(symbol), 4);
				else PrintTextColor_Char(toupper(symbol), 6);
			}
			Sleep(50);
		}
		return 1; //Win
	}

	return 0; //Not Win
}

void HandleKeyForBoard(int x, int y, KEY_EVENT_RECORD key) {
	Finish = 0;
	if (Turn % 2 == 0) DrawTurn(1);
	else DrawTurn(0);
	GotoXY(_X, _Y);
	if (key.bKeyDown) //Key pressed
	{
		switch (key.wVirtualKeyCode)
		{
		case VK_RETURN: case VK_SPACE: //Enter & Space
			if (D2_INGAME_MUSIC) PlaySound(TEXT("Sounds//put-x-o.wav"), NULL, SND_FILENAME | SND_ASYNC);
			//Check Turn
			if (_MATRIX[_Y / 2 - int(FIRST_CELL_Y) / 2][_X / 4 - int(FIRST_CELL_X) / 4] == 'x' || _MATRIX[_Y / 2 - int(FIRST_CELL_Y) / 2][_X / 4 - int(FIRST_CELL_X) / 4] == 'o') {
				return;
			}
			Count++;
			if (Turn % 2 == 0) {
				Turn++;
				_MATRIX[_Y / 2 - int(FIRST_CELL_Y) / 2][_X / 4 - int(FIRST_CELL_X) / 4] = 'x';
				PrintTextColor_Char('X', 1);
				//cout << "X";
				if (Check_Win('x', _X, _Y)) {
					Turn = 0; Score1++;
					DrawScore(Score1, Score2);
					DrawWin(-1);
					Finish = 1;
					ShowCur(0);
					DrawSaveAndContinue();
					_CURRENT_MENU = 8;

				}
			}
			else if (Turn % 2 == 1) {
				Turn++;
				_MATRIX[_Y / 2 - int(FIRST_CELL_Y) / 2][_X / 4 - int(FIRST_CELL_X) / 4] = 'o';
				PrintTextColor_Char('O', 2);
				//cout << "O";
				if (Check_Win('o', _X, _Y)) {
					Turn = 0; Score2++;
					DrawScore(Score1, Score2);
					DrawWin(1);
					Finish = 1;
					ShowCur(0);
					DrawSaveAndContinue();
					_CURRENT_MENU = 8;
				}
			}
			if (Count == BOARD_SIZE * BOARD_SIZE) {
				Turn = 0; Draw++;
				Finish = 1;
				DrawWin(0);
				ShowCur(0);
				DrawSaveAndContinue();
				_CURRENT_MENU = 8;
			}
			break;
		case VK_ESCAPE: //Esc
			if (D2_INGAME_MUSIC) PlaySound(TEXT("sounds//select.wav"), NULL, SND_FILENAME | SND_ASYNC);
			ShowCur(0);
			DrawSaveAndContinue();
			_CURRENT_MENU = 10;
			break;
		case VK_LEFT: case 0x41: //Left arrow
			if (D2_INGAME_MUSIC) PlaySound(TEXT("sounds//move-in-board.wav"), NULL, SND_FILENAME | SND_ASYNC);
			if (_X == FIRST_CELL_X) {
				_X += (BOARD_SIZE - 1) * x;
				GotoXY(_X, _Y);
			}
			else {
				GotoXY(_X - x, _Y);
				_X -= x;
			}
			break;
		case VK_RIGHT: case 0x44: //Right arrow
			if (D2_INGAME_MUSIC) PlaySound(TEXT("sounds//move-in-board.wav"), NULL, SND_FILENAME | SND_ASYNC);
			if (_X == FIRST_CELL_X + (BOARD_SIZE - 1) * x) {
				_X = FIRST_CELL_X;
				GotoXY(_X, _Y);
			}
			else {
				GotoXY(_X + x, _Y);
				_X += x;
			}
			break;
		case VK_DOWN: case 0x53: //Down arrow
			if (D2_INGAME_MUSIC) PlaySound(TEXT("sounds//move-in-board.wav"), NULL, SND_FILENAME | SND_ASYNC);
			if (_Y == FIRST_CELL_Y + (BOARD_SIZE - 1) * y) {
				_Y = FIRST_CELL_Y;
				GotoXY(_X, _Y);
			}
			else {
				GotoXY(_X, _Y + y);
				_Y += y;
			}
			break;
		case VK_UP: case 0x57: //Up arrow
			if (D2_INGAME_MUSIC) PlaySound(TEXT("sounds//move-in-board.wav"), NULL, SND_FILENAME | SND_ASYNC);
			if (_Y == FIRST_CELL_Y) {
				_Y += (BOARD_SIZE - 1) * y;
				GotoXY(_X, _Y);
			}
			else {
				GotoXY(_X, _Y - y);
				_Y -= y;
			}
			break;
		default:
			break;
		}
	}
}

int bot_x, bot_y;

void BotRandom(char _MATRIX[BOARD_SIZE][BOARD_SIZE]) {

	int r_mat = 0;
	int c_mat = 0;

	int cur_row = _Y / 2 - int(FIRST_CELL_Y) / 2;
	int cur_col = _X / 4 - int(FIRST_CELL_X) / 4;

	int vertical_01 = 0;
	int vertical_02 = 0;

	int horizontal_01 = 0;
	int horizontal_02 = 0;

	int main_cross_01 = 0;
	int main_cross_02 = 0;

	int sub_cross_01 = 0;
	int sub_cross_02 = 0;

	//Horizontal check
	for (int i = cur_col + 1; i < BOARD_SIZE; i++) {
		if (_MATRIX[cur_row][i] != 'x') break;
		horizontal_01++;
	}

	for (int i = cur_col - 1; i >= 0; i--) {
		if (_MATRIX[cur_row][i] != 'x') break;
		horizontal_02++;
	}

	//Vertical check
	for (int i = cur_row + 1; i < BOARD_SIZE; i++) {
		if (_MATRIX[i][cur_col] != 'x') break;
		vertical_01++;
	}

	for (int i = cur_row - 1; i >= 0; i--) {
		if (_MATRIX[i][cur_col] != 'x') break;
		vertical_02++;
	}

	//Main cross check
	for (int i = cur_row + 1, j = cur_col + 1; i < BOARD_SIZE && j < BOARD_SIZE; i++, j++) {
		if (_MATRIX[i][j] != 'x') break;
		main_cross_01++;
	}

	for (int i = cur_row - 1, j = cur_col - 1; i >= 0 && j >= 0; i--, j--) {
		if (_MATRIX[i][j] != 'x') break;
		main_cross_02++;
	}

	//Sub cross check
	for (int i = cur_row - 1, j = cur_col + 1; i >= 0 && j < BOARD_SIZE; i--, j++) {
		if (_MATRIX[i][j] != 'x') break;
		sub_cross_01++;
	}

	for (int i = cur_row + 1, j = cur_col - 1; i < BOARD_SIZE && j >= 0; i++, j--) {
		if (_MATRIX[i][j] != 'x') break;
		sub_cross_02++;
	}

	int whichOne[4] = { 1, 2, 3, 4 };
	int order[4] = { vertical_01 + vertical_02, horizontal_01 + horizontal_02, main_cross_01 + main_cross_02, sub_cross_01 + sub_cross_02 };
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3 - i; j++)
			if (order[j] < order[j + 1]) {
				int tmp = order[j];
				order[j] = order[j + 1];
				order[j + 1] = tmp;
				tmp = whichOne[j];
				whichOne[j] = whichOne[j + 1];
				whichOne[j + 1] = tmp;
			}
	for (int i = 0; i < 4; i++)
		if (whichOne[i] == 1) {
			if ((vertical_01 + vertical_02) >= 0) {
				bot_x = _X;
				bot_y = _Y - vertical_02 * 2 - 2;
				r_mat = (bot_y / 2 - int(FIRST_CELL_Y) / 2);
				c_mat = (bot_x / 4 - int(FIRST_CELL_X) / 4);
				if (r_mat >= 0)
					if (_MATRIX[r_mat][c_mat] != 'x' && _MATRIX[r_mat][c_mat] != 'o') {
						_MATRIX[r_mat][c_mat] = 'o';
						GotoXY(bot_x, bot_y);
						//cout << "O";
						PrintTextColor_Char('O', 2);
						return;
					}
				bot_y = _Y + vertical_01 * 2 + 2;
				r_mat = (bot_y / 2 - int(FIRST_CELL_Y) / 2);
				if (r_mat < BOARD_SIZE)
					if (_MATRIX[r_mat][c_mat] != 'x' && _MATRIX[r_mat][c_mat] != 'o') {
						_MATRIX[r_mat][c_mat] = 'o';
						GotoXY(bot_x, bot_y);
						//cout << "O";
						PrintTextColor_Char('O', 2);
						return;
					}
			}
		}
		else if (whichOne[i] == 3) {
			if ((main_cross_01 + main_cross_02) >= 0) {
				bot_x = _X - main_cross_02 * 4 - 4;
				bot_y = _Y - main_cross_02 * 2 - 2;
				r_mat = (bot_y / 2 - int(FIRST_CELL_Y) / 2);
				c_mat = (bot_x / 4 - int(FIRST_CELL_X) / 4);
				if (r_mat >= 0 && c_mat >= 0)
					if (_MATRIX[r_mat][c_mat] != 'x' && _MATRIX[r_mat][c_mat] != 'o') {
						_MATRIX[r_mat][c_mat] = 'o';
						GotoXY(bot_x, bot_y);
						//cout << "O";
						PrintTextColor_Char('O', 2);
						return;
					}
				bot_x = _X + main_cross_01 * 4 + 4;
				bot_y = _Y + main_cross_01 * 2 + 2;
				r_mat = (bot_y / 2 - int(FIRST_CELL_Y) / 2);
				c_mat = (bot_x / 4 - int(FIRST_CELL_X) / 4);
				if (r_mat < BOARD_SIZE && c_mat < BOARD_SIZE)
					if (_MATRIX[r_mat][c_mat] != 'x' && _MATRIX[r_mat][c_mat] != 'o') {
						_MATRIX[r_mat][c_mat] = 'o';
						GotoXY(bot_x, bot_y);
						//cout << "O";
						PrintTextColor_Char('O', 2);
						return;
					}
			}
		}
		else if (whichOne[i] == 4) {
			if ((sub_cross_01 + sub_cross_02) >= 0) {
				bot_x = _X - sub_cross_02 * 4 - 4;
				bot_y = _Y + sub_cross_02 * 2 + 2;
				r_mat = (bot_y / 2 - int(FIRST_CELL_Y) / 2);
				c_mat = (bot_x / 4 - int(FIRST_CELL_X) / 4);
				if (c_mat >= 0 && r_mat < BOARD_SIZE)
					if (_MATRIX[r_mat][c_mat] != 'x' && _MATRIX[r_mat][c_mat] != 'o') {
						_MATRIX[r_mat][c_mat] = 'o';
						GotoXY(bot_x, bot_y);
						//cout << "O";
						PrintTextColor_Char('O', 2);
						return;
					}
				bot_x = _X + sub_cross_01 * 4 + 4;
				bot_y = _Y - sub_cross_01 * 2 - 2;
				r_mat = (bot_y / 2 - int(FIRST_CELL_Y) / 2);
				c_mat = (bot_x / 4 - int(FIRST_CELL_X) / 4);
				if (r_mat >= 0 && c_mat < BOARD_SIZE)
					if (_MATRIX[r_mat][c_mat] != 'x' && _MATRIX[r_mat][c_mat] != 'o') {
						_MATRIX[r_mat][c_mat] = 'o';
						GotoXY(bot_x, bot_y);
						//cout << "O";
						PrintTextColor_Char('O', 2);
						return;
					}
			}
		}
		else {
			if ((horizontal_01 + horizontal_02) >= 0) {
				bot_x = _X - horizontal_02 * 4 - 4;
				bot_y = _Y;
				r_mat = (bot_y / 2 - int(FIRST_CELL_Y) / 2);
				c_mat = (bot_x / 4 - int(FIRST_CELL_X) / 4);
				if (c_mat >= 0)
					if (_MATRIX[r_mat][c_mat] != 'x' && _MATRIX[r_mat][c_mat] != 'o') {
						_MATRIX[r_mat][c_mat] = 'o';
						GotoXY(bot_x, bot_y);
						//cout << "O";
						PrintTextColor_Char('O', 2);
						return;
					}
				bot_x = _X + horizontal_01 * 4 + 4;
				c_mat = (bot_x / 4 - int(FIRST_CELL_X) / 4);
				if (c_mat < BOARD_SIZE)
					if (_MATRIX[r_mat][c_mat] != 'x' && _MATRIX[r_mat][c_mat] != 'o') {
						_MATRIX[r_mat][c_mat] = 'o';
						GotoXY(bot_x, bot_y);
						//cout << "O";
						PrintTextColor_Char('O', 2);
						return;
					}
			}
		}

	srand(unsigned int(time(NULL)));
	while (1) {
		bot_x = rand() % BOARD_SIZE + 0;
		bot_y = rand() % BOARD_SIZE + 0;
		if (_MATRIX[bot_x][bot_y] != 'x' && _MATRIX[bot_x][bot_y] != 'o') {
			GotoXY(4 * bot_y + int(FIRST_CELL_X), 2 * bot_x + int(FIRST_CELL_Y));
			_MATRIX[bot_x][bot_y] = 'o';
			//cout << "O";
			PrintTextColor_Char('O', 2);
			return;
		}
	}
}

void HandleKeyForBoardBot(int x, int y, KEY_EVENT_RECORD key) {
	Finish = 0;
	if (Turn % 2 == 0) DrawTurn(1);
	else DrawTurn(0);
	GotoXY(_X, _Y);

	//Bot
	if (Turn % 2 == 1) {
		Count++;
		Turn++;
		BotRandom(_MATRIX);
		GotoXY(_X, _Y);
		if (Check_Win('o', bot_x, bot_y)) {
			Turn = 0; Score2++;
			DrawScore(Score1, Score2);
			DrawWin(1);
			Finish = 1;
			ShowCur(0);
			DrawSaveAndContinue();
			_CURRENT_MENU = 8;
		}
	}

	if (Count == BOARD_SIZE * BOARD_SIZE) {
		Turn = 0; Draw++;
		Finish = 1;
		DrawWin(0);
		ShowCur(0);
		DrawSaveAndContinue();
		_CURRENT_MENU = 8;
	}

	if (key.bKeyDown) //Key pressed
	{
		switch (key.wVirtualKeyCode)
		{
		case VK_RETURN: case VK_SPACE: //Enter & Space
			//Check Turn
			if (_MATRIX[_Y / 2 - int(FIRST_CELL_Y) / 2][_X / 4 - int(FIRST_CELL_X) / 4] == 'x' || _MATRIX[_Y / 2 - int(FIRST_CELL_Y) / 2][_X / 4 - int(FIRST_CELL_X) / 4] == 'o') {
				return;
			}
			if (D2_INGAME_MUSIC) PlaySound(TEXT("sounds//put-x-o.wav"), NULL, SND_FILENAME | SND_ASYNC);
			Count++;
			if (Turn % 2 == 0) {
				Turn++;
				_MATRIX[_Y / 2 - int(FIRST_CELL_Y) / 2][_X / 4 - int(FIRST_CELL_X) / 4] = 'x';
				//cout << "X";
				PrintTextColor_Char('X', 1);
				if (Check_Win('x', _X, _Y)) {
					Turn = 0; Score1++;
					DrawScore(Score1, Score2);
					DrawWin(-1);
					Finish = 1;
					ShowCur(0);
					DrawSaveAndContinue();
					_CURRENT_MENU = 8;
				}
			}
			if (Count == BOARD_SIZE * BOARD_SIZE) {
				Turn = 0; Draw++;
				Finish = 1;
				DrawWin(0);
				ShowCur(0);
				DrawSaveAndContinue();
				_CURRENT_MENU = 8;
			}
			break;
		case VK_ESCAPE: //Esc
			if (D2_INGAME_MUSIC) PlaySound(TEXT("Sounds//select.wav"), NULL, SND_FILENAME | SND_ASYNC);
			ShowCur(0);
			DrawSaveAndContinue();
			_CURRENT_MENU = 10;
			break;
		case VK_LEFT: case 0x41: //Left arrow
			if (D2_INGAME_MUSIC) PlaySound(TEXT("sounds//move-in-board.wav"), NULL, SND_FILENAME | SND_ASYNC);
			if (_X == FIRST_CELL_X) {
				_X += (BOARD_SIZE - 1) * x;
				GotoXY(_X, _Y);
			}
			else {
				GotoXY(_X - x, _Y);
				_X -= x;
			}
			break;
		case VK_RIGHT: case 0x44: //Right arrow
			if (D2_INGAME_MUSIC) PlaySound(TEXT("sounds//move-in-board.wav"), NULL, SND_FILENAME | SND_ASYNC);
			if (_X == FIRST_CELL_X + (BOARD_SIZE - 1) * x) {
				_X = FIRST_CELL_X;
				GotoXY(_X, _Y);
			}
			else {
				GotoXY(_X + x, _Y);
				_X += x;
			}
			break;
		case VK_DOWN: case 0x53: //Down arrow
			if (D2_INGAME_MUSIC) PlaySound(TEXT("sounds//move-in-board.wav"), NULL, SND_FILENAME | SND_ASYNC);
			if (_Y == FIRST_CELL_Y + (BOARD_SIZE - 1) * y) {
				_Y = FIRST_CELL_Y;
				GotoXY(_X, _Y);
			}
			else {
				GotoXY(_X, _Y + y);
				_Y += y;
			}
			break;
		case VK_UP: case 0x57: //Up arrow
			if (D2_INGAME_MUSIC) PlaySound(TEXT("sounds//move-in-board.wav"), NULL, SND_FILENAME | SND_ASYNC);
			if (_Y == FIRST_CELL_Y) {
				_Y += (BOARD_SIZE - 1) * y;
				GotoXY(_X, _Y);
			}
			else {
				GotoXY(_X, _Y - y);
				_Y -= y;
			}
			break;
		default:
			break;
		}
	}
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

		Sleep(25);
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


//Draw Infor Frame
void DrawInforFrame() {
	ShowCur(false);

	for (int i = 0; i <= FMax_i; i += 2) {
		GotoXY(FLeft + i, FTop);
		cout << Lower_Vertical << Lower_Vertical;
		GotoXY(FMax_i + FLeft - i, FMax_j);
		cout << Upper_Vertical << Upper_Vertical;
		Sleep(5);
	}

	for (int i = 1; i < FMax_j - FTop; i += 2) {
		GotoXY(FMax_i + FLeft + 1, FTop + i);
		cout << Horizontal_Line;
		GotoXY(FMax_i + FLeft + 1, FTop + i + 1);
		cout << Horizontal_Line;
		GotoXY(FLeft, FMax_j - i);
		cout << Horizontal_Line;
		GotoXY(FLeft, FMax_j - i - 1);
		cout << Horizontal_Line;
		Sleep(5);
	}

}


//ClearBoard
void ClearBoard(int pSize) {
	int Max_i = pSize * 2;
	int Max_j = pSize * 4;
	for (int i = 0; i <= Max_i; i++) {
		GotoXY(LEFT, TOP + i);
		for (int j = 0; j <= Max_j; j++) {
			cout << " ";
		}
	}
}

//Draw Logo Frame
void DrawLogoFrame() {
	ShowCur(false);

	for (int i = 0; i <= LMax_i; i += 2) {
		GotoXY(LLeft + i, LTop);
		cout << Lower_Vertical << Lower_Vertical;
		GotoXY(LMax_i + LLeft - i, LMax_j);
		cout << Upper_Vertical << Upper_Vertical;
		Sleep(5);
	}

	for (int i = 1; i < LMax_j - LTop; i += 2) {
		GotoXY(LMax_i + LLeft + 1, LTop + i);
		cout << Horizontal_Line;
		GotoXY(LMax_i + LLeft + 1, LTop + i + 1);
		cout << Horizontal_Line;
		GotoXY(LLeft, LMax_j - i);
		cout << Horizontal_Line;
		GotoXY(LLeft, LMax_j - i - 1);
		cout << Horizontal_Line;
		Sleep(5);
	}

}


//Remove Logo Frame
void RemoveLogoFrame() {
	GotoXY(LLeft + 1, LTop + 1);
	for (int i = 1; i < LMax_j - LTop; i++)
	{
		GotoXY(LLeft + 1, LTop + i);
		for (int i = 0; i < LMax_i; i++) {
			printf(" ");
		}
	}
}

//Draw HCMUS And Log
void DrawLogoHcmus() {
	ShowCur(0);
	RemoveLogoFrame();
	int OldMode = _setmode(_fileno(stdout), _O_WTEXT);
	wstring Logo[5];
	Logo[0] = (L" ▄ .▄ ▄▄· • ▌ ▄ ·. ▄• ▄▌.▄▄ ·		");
	Logo[1] = (L"██▪▐█▐█ ▌▪·██ ▐███▪█▪██▌▐█ ▀.	    ");
	Logo[2] = (L"██▀▀███ ▄▄▐█ ▌▐▌▐█·█▌▐█▌▄▀▀▀█▄ 	");
	Logo[3] = (L"██▌▐▀▐███▌██ ██▌▐█▌▐█▄█▌▐█▄▪▐█	    ");
	Logo[4] = (L"▀▀▀ ··▀▀▀ ▀▀  █▪▀▀▀ ▀▀▀  ▀▀▀▀		");

	for (int i = 0; i < 5; i++)
	{
		GotoXY(LLeft + 28, LTop + 4 + i);
		wcout << Logo[i];
	}
	int CurrentMode = _setmode(_fileno(stdout), OldMode);
	GotoXY(LLeft + 32, LTop + 11);
	cout << "Press ESC to Save Game";

}

//Draw Win (-1: X Win / 0: Draw / 1: O Win)
void DrawWin(int n) {
	RemoveLogoFrame();
	int OldMode = _setmode(_fileno(stdout), _O_WTEXT);
	ShowCur(0);
	wstring XWin[6];
	XWin[0] = L"██╗  ██╗     ██╗    ██╗██╗███╗   ██╗";
	XWin[1] = L"╚██╗██╔╝     ██║    ██║██║████╗  ██║";
	XWin[2] = L" ╚███╔╝      ██║ █╗ ██║██║██╔██╗ ██║";
	XWin[3] = L" ██╔██╗      ██║███╗██║██║██║╚██╗██║";
	XWin[4] = L"██╔╝ ██╗     ╚███╔███╔╝██║██║ ╚████║";
	XWin[5] = L"╚═╝  ╚═╝      ╚══╝╚══╝ ╚═╝╚═╝  ╚═══╝";

	wstring Draw[6];
	Draw[0] = L"██████╗ ██████╗  █████╗ ██╗    ██╗";
	Draw[1] = L"██╔══██╗██╔══██╗██╔══██╗██║    ██║";
	Draw[2] = L"██║  ██║██████╔╝███████║██║ █╗ ██║";
	Draw[3] = L"██║  ██║██╔══██╗██╔══██║██║███╗██║";
	Draw[4] = L"██████╔╝██║  ██║██║  ██║╚███╔███╔╝";
	Draw[5] = L"╚═════╝ ╚═╝  ╚═╝╚═╝  ╚═╝ ╚══╝╚══╝ ";

	wstring OWin[6];
	OWin[0] = L" ██████╗     ██╗    ██╗██╗███╗   ██╗";
	OWin[1] = L"██╔═══██╗    ██║    ██║██║████╗  ██║";
	OWin[2] = L"██║   ██║    ██║ █╗ ██║██║██╔██╗ ██║";
	OWin[3] = L"██║   ██║    ██║███╗██║██║██║╚██╗██║";
	OWin[4] = L"╚██████╔╝    ╚███╔███╔╝██║██║ ╚████║";
	OWin[5] = L" ╚═════╝      ╚══╝╚══╝ ╚═╝╚═╝  ╚═══╝";

	if (D2_INGAME_MUSIC) PlaySound(TEXT("sounds//win.wav"), NULL, SND_FILENAME | SND_ASYNC);
	int Color[3] = { RED, GREEN, BLUE };
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 6; j++)
		{
			TextColor(Color[i]);
			GotoXY(LLeft + 25, LTop + 4 + j);
			if (n == -1) wcout << XWin[j];
			if (n == 0) wcout << Draw[j];
			if (n == 1) wcout << OWin[j];
			Sleep(200);

		}
		Sleep(200);
		for (int j = 0; j < 6; j++)
		{
			GotoXY(LLeft + 25, LTop + 4 + j);
			wcout << "                                    ";
			Sleep(100);

		}
	}
	TextColor(0);
	int CurrentMode = _setmode(_fileno(stdout), OldMode);
	ShowCur(1);
}

//Draw Avatar In Battle
//Function PrintCharacter of D2 (Player1: (FLeft + 5, FTop + 3) / Player2: FLeft + 60, FTop + 3)
void DrawAvatarBattle(int player1, int player2) {
	PrintCharacter(player1, FLeft + 5, FTop + 3);
	PrintCharacter(player2, FLeft + 58, FTop + 3);

	GotoXY(FLeft + 16 - int(D2_PLAYER01_NAME.size() / 2.0f), FTop + 9);
	cout << D2_PLAYER01_NAME;
	GotoXY(FLeft + 69 - int(D2_PLAYER02_NAME.size() / 2.0f), FTop + 9);
	cout << D2_PLAYER02_NAME;
}


void RemoveScore() {
	//Remove Score 1
	for (int i = 0; i < 3; i++) {
		GotoXY(FLeft + 35, FTop + 8 + i);
		wcout << "      ";
	}
	//Remove Score 2
	for (int i = 0; i < 3; i++) {
		GotoXY(FLeft + 48, FTop + 8 + i);
		wcout << "      ";
	}
}
//Draw Score (Player1 and Player2)
void DrawScore(int player1, int player2) {
	int OldMode = _setmode(_fileno(stdout), _O_WTEXT);

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

	wstring Line = L"▀▀▀";
	RemoveScore();
	//Score 1
	for (int i = 0; i < 3; i++) {
		GotoXY(FLeft + 35, FTop + 8 + i);
		if (player1 == 0) wcout << Zero[i];
		if (player1 == 1) wcout << One[i];
		if (player1 == 2) wcout << Two[i];
		if (player1 == 3) wcout << Three[i];
		if (player1 == 4) wcout << Four[i];
		if (player1 == 5) wcout << Five[i];
		if (player1 == 6) wcout << Six[i];
		if (player1 == 7) wcout << Seven[i];
		if (player1 == 8) wcout << Eight[i];
		if (player1 == 9) wcout << Nine[i];
	}
	//Line
	GotoXY(FLeft + 41, FTop + 9);
	wcout << Line;
	//Score 2
	for (int i = 0; i < 3; i++) {
		GotoXY(FLeft + 48, FTop + 8 + i);
		if (player2 == 0) wcout << Zero[i];
		if (player2 == 1) wcout << One[i];
		if (player2 == 2) wcout << Two[i];
		if (player2 == 3) wcout << Three[i];
		if (player2 == 4) wcout << Four[i];
		if (player2 == 5) wcout << Five[i];
		if (player2 == 6) wcout << Six[i];
		if (player2 == 7) wcout << Seven[i];
		if (player2 == 8) wcout << Eight[i];
		if (player2 == 9) wcout << Nine[i];
	}
	int CurrentMode = _setmode(_fileno(stdout), OldMode);
}

//Draw Turn (1: X Turn / 0: O Turn)
void DrawTurn(int n) {
	ShowCur(0);
	int OldMode = _setmode(_fileno(stdout), _O_WTEXT);
	wstring X[6];
	X[0] = L"██╗  ██╗";
	X[1] = L"╚██╗██╔╝";
	X[2] = L" ╚███╔╝";
	X[3] = L" ██╔██╗";
	X[4] = L"██╔╝ ██╗";
	X[5] = L"╚═╝  ╚═╝";

	wstring O[6];
	O[0] = L" ██████╗";
	O[1] = L"██╔═══██╗";
	O[2] = L"██║   ██║";
	O[3] = L"██║   ██║";
	O[4] = L"╚██████╔╝";
	O[5] = L" ╚═════╝";

	//int n = 1: X Turn / n=0: Y Turn
	if (n == 1) {
		TextColor(12);
		for (int i = 0; i < 6; i++) {
			GotoXY(FLeft + 12, FTop + 13 + i);
			wcout << X[i];
		}
		TextColor(8);
		for (int i = 0; i < 6; i++) {
			GotoXY(FLeft + 65, FTop + 13 + i);
			wcout << O[i];
		}
		TextColor(0);
	}
	else if (n == 0) {
		TextColor(12);
		for (int i = 0; i < 6; i++) {
			GotoXY(FLeft + 65, FTop + 13 + i);
			wcout << O[i];
		}
		TextColor(8);
		for (int i = 0; i < 6; i++) {
			GotoXY(FLeft + 12, FTop + 13 + i);
			wcout << X[i];
		}
		TextColor(0);
	}
	int CurrentMode = _setmode(_fileno(stdout), OldMode);
	ShowCur(1);
}

void DrawSaveAndContinue() {
	RemoveLogoFrame();
	GotoXY(LLeft + 32, LTop + 5);
	cout << "Do you want to continue?";
	GotoXY(LLeft + 18, LTop + 8);
	cout << D2_SELECT_RIGHT;
	GotoXY(LLeft + 20, LTop + 8);
	cout << "YES";
	GotoXY(LLeft + 65, LTop + 8);
	cout << "NO";
}

int Choose = 1;

void HandleKeyForSaveGame(int x, int y, KEY_EVENT_RECORD key)
{
	ShowCur(0);
	if (key.bKeyDown) //Key pressed
		switch (key.wVirtualKeyCode) {
		case VK_RETURN: //Enter
			if (D2_INGAME_MUSIC) PlaySound(TEXT("Sounds//select.wav"), NULL, SND_FILENAME | SND_ASYNC);
			if (Choose == 1) {
				ClearMatrix();
				ClearBoard(BOARD_SIZE);
				DrawLogoHcmus();
				DrawBoard(BOARD_SIZE);
				_X = FIRST_CELL_X;
				_Y = FIRST_CELL_Y;
				_CURRENT_MENU = 9;
			}
			if (Choose == 0) {
				if (isLoadFile) {
					SaveInforFile(loadedFileName);
					isLoadFile = 0;
				}
				else {
					SaveNameFile();
					SaveInforFile(FileName);
				}
				_KEYPRESSED = 1;
				_MENU = 0;
				_CURRENT_MENU = 0;
				_X = FIRST_CELL_X;
				_Y = FIRST_CELL_Y;
				Choose = 1;
				Score1 = Score2 = Draw = 0;
				ClearMatrix();
				InitGame();
			}
			break;
		case VK_LEFT: case 0x41: //Left arrow
			if (D2_INGAME_MUSIC) PlaySound(TEXT("Sounds//switch-selection.wav"), NULL, SND_FILENAME | SND_ASYNC);
			GotoXY(LLeft + 63, LTop + 8);
			cout << " ";
			GotoXY(LLeft + 18, LTop + 8);
			cout << D2_SELECT_RIGHT;
			Choose = 1;
			break;
		case VK_RIGHT: case 0x44: //Right arrow
			if (D2_INGAME_MUSIC) PlaySound(TEXT("Sounds//switch-selection.wav"), NULL, SND_FILENAME | SND_ASYNC);
			GotoXY(LLeft + 18, LTop + 8);
			cout << " ";
			GotoXY(LLeft + 63, LTop + 8);
			cout << D2_SELECT_RIGHT;
			Choose = 0;
			break;
		}
}

void HandleKeyForSaveGame_ESC(int x, int y, KEY_EVENT_RECORD key)
{
	ShowCur(0);
	if (key.bKeyDown) //Key pressed
		switch (key.wVirtualKeyCode) {
		case VK_RETURN: //Enter
			if (D2_INGAME_MUSIC) PlaySound(TEXT("Sounds//select.wav"), NULL, SND_FILENAME | SND_ASYNC);
			if (Choose == 1) {
				DrawLogoHcmus();
				GotoXY(_X, _Y);
				_CURRENT_MENU = 9;
			}
			if (Choose == 0) {
				if (isLoadFile) {
					SaveInforFile(loadedFileName);
					isLoadFile = 0;
				}
				else {
					SaveNameFile();
					SaveInforFile(FileName);
				}
				_KEYPRESSED = 1;
				_MENU = 0;
				_CURRENT_MENU = 0;
				_X = FIRST_CELL_X;
				_Y = FIRST_CELL_Y;
				Choose = 1;
				Score1 = Score2 = Draw = 0;
				ClearMatrix();
				InitGame();
			}
			break;
		case VK_LEFT: case 0x41: //Left arrow
			if (D2_INGAME_MUSIC) PlaySound(TEXT("sounds//switch-selection.wav"), NULL, SND_FILENAME | SND_ASYNC);
			//ShowCur(0);
			GotoXY(LLeft + 63, LTop + 8);
			cout << " ";
			GotoXY(LLeft + 18, LTop + 8);
			cout << D2_SELECT_RIGHT;
			Choose = 1;
			break;
		case VK_RIGHT: case 0x44: //Right arrow
			if (D2_INGAME_MUSIC) PlaySound(TEXT("sounds//switch-selection.wav"), NULL, SND_FILENAME | SND_ASYNC);
			//ShowCur(0);
			GotoXY(LLeft + 18, LTop + 8);
			cout << " ";
			GotoXY(LLeft + 63, LTop + 8);
			cout << D2_SELECT_RIGHT;
			Choose = 0;
			break;
		case VK_ESCAPE: //Esc
			if (D2_INGAME_MUSIC) PlaySound(TEXT("sounds//select.wav"), NULL, SND_FILENAME | SND_ASYNC);
			DrawLogoHcmus();
			GotoXY(_X, _Y);
			_CURRENT_MENU = 9;
			break;
		}
}


void SaveNameFile() {
	RemoveLogoFrame();
	GotoXY(LLeft + 32, LTop + 5);
	cout << "Type Your File Name: ";
	GotoXY(LLeft + 32, LTop + 7);
	cout << "=> ";
	ShowCur(1);
	getline(cin, FileName);
	if(FileName.size() > 15) //If more than 15 characters, resize it
		FileName.resize(15);
	if (D2_INGAME_MUSIC) PlaySound(TEXT("sounds//select.wav"), NULL, SND_FILENAME | SND_ASYNC);
	ofstream File;
	File.open("SavedFiles\\fileLoad.json", ios::app);
	File << FileName <<".txt" << "\n";
	return;
}

void SaveInforFile(string FileName) {
	ofstream File;
	File.open("SavedFiles\\" + FileName + ".txt", ios::out);
	File << D2_PLAYER01_NAME << endl;
	if (D3_GameMode == 0) File << "Mega Roboto" << endl;
	else File << D2_PLAYER02_NAME << endl;
	File << Score1 << endl;
	File << Score2 << endl;
	File << Draw << endl;
	File << D2_PLAYER01_CHARACTER << endl;
	File << D2_PLAYER02_CHARACTER << endl;
	File << Finish << endl;
	File << Turn << endl;
	for (int i = 0; i < BOARD_SIZE; i++) {
		for (int j = 0; j < BOARD_SIZE; j++) {
			File << _MATRIX[i][j] << " ";
		}
		File << endl;
	}
	File.close();
}

void PrintDataBoard() {
	if (Finish == 1) {
		ClearMatrix();
		return;
	}
	else if (Finish == 0) {
		for (int i = 0; i < BOARD_SIZE; i++) {
			for (int j = 0; j < BOARD_SIZE; j++) {
				if (_MATRIX[i][j] == '-') continue;
				else {
					GotoXY(4 * j + int(FIRST_CELL_X), 2 * i + int(FIRST_CELL_Y));
					if (_MATRIX[i][j] == 'x') PrintTextColor_Char('X', 1);
					else PrintTextColor_Char('O', 2);
					//cout << char(_MATRIX[i][j] - 32);
				}
			}
		}
	}
}
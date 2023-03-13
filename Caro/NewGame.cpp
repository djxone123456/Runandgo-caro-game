#include "Control.h"
#include "View.h"
#include "NewGame.h"

//Control Menu:
//0: Main Menu
//1: New Game
//2: Load game
//3: Settings
//4: Help
//5: Info
//6: Exit
void ControlMenu() {
	while (1) {
		if (_KEYPRESSED) {
			switch (_MENU) {
			case 1:
				_KEYPRESSED = 0;
				//New game
				break;
			case 2:
				_KEYPRESSED = 0;
				//Load game
				break;
			case 3:
				_KEYPRESSED = 0;
				_CURRENT_MENU = 3;
				//Settings
				system("cls");

				break;
			case 4:
				_CURRENT_MENU = 4;
				_KEYPRESSED = 0;
				system("cls");
				//Help
				break;
			case 5:
				_KEYPRESSED = 0;
				_CURRENT_MENU = 5;
				system("cls");
				//Info
				break;
			case 6:
				system("cls");
				//Say goodbye and exit
				Sleep(1000);
				Exit();
				break;
			}
		}
		switch (_CURRENT_MENU) {
		case 0:
			HandleEvent(80, 22, HandleKeyForMainMenu);
			break;
		case 1:
			break;
		case 2:
			break;
		case 3:
			HandleEvent(90, STop + 5, HandleKeyForSetting);
			break;
		case 4:
			HandleEvent(80, 22, HandleKeyForHelp);
			break;
		case 5:
			HandleEvent(80, 22, HandleKeyForInfo);
			break;
		}
	}
}
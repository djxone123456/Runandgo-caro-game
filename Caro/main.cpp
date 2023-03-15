#include "View.h"
#include "Control.h"
#include "Data.h"
#include "Model.h"

#include "Error.h"
#include "Help.h"
#include "Settings.h"
#include "MainMenu.h"  // This is the main header for Dev 1
#include "Store.h"  // This is the main header for Dev 2
#include "NewGame.h" // This is the main header for Dev 3
#include "SavedGames.h"  // This is the main header for Dev 4
#include "CaroFrame.h" // This is the main header for Dev 5
#include "About.h"

int main() {
	/*CreateConsoleWindow(WIDTH, HEIGHT);
	int OldMode = _setmode(_fileno(stdout), _O_WTEXT);*/
	
	//Do something here




	CreateConsoleWindow(WIDTH, HEIGHT);
	ImportSettings();
	BackgroundMusic();
	/*Store();
	while (1)
		HandleEvent(0, 0, HandleKeyForChoosingChar);*/
	/*Setting();
	while (1)
		HandleEvent(0, 0, HandleKeyForSettings);*/
	/*_CURRENT_MENU = 1;
	NewGame();*/
	/*while(1)
		HandleEvent(D3_NewGame_Box_Left + 26, D3_NewGame_Box_Top + 7, HandleKeyForNewGame);
	cin.get();*/
	ControlMenu();
	/*About();
	while (1)
		HandleEvent(0, 0, HandleKeyForAbout);*/
	return 0;
}

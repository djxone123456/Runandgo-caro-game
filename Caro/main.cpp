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
#include "Ranking.h"
#include "About.h"

int main() {
	CreateConsoleWindow(WIDTH, HEIGHT);
	
	//Do something here
	

	ImportSettings();
	BackgroundMusic();
	
	_KEYPRESSED = 1;
	_MENU = 0;
	_CURRENT_MENU = 0;

	ControlMenu();

	return 0;
}


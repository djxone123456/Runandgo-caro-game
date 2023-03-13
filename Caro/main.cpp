#include "Variables.h"
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

int main() {
	CreateConsoleWindow(WIDTH, HEIGHT);
	int OldMode = _setmode(_fileno(stdout), _O_WTEXT);
	
	//Do something here

	return 0;
}

#include "Control.h"

int main() {
	CreateConsoleWindow(WIDTH, HEIGHT);
	ImportSettings();
	BackgroundMusic();
	_KEYPRESSED = 1;
	_MENU = 0;
	_CURRENT_MENU = 0;
	ControlMenu();
	return 0;
}

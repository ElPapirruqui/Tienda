#pragma once
#include "IMenu.h"

class MainMenu : public IMenu {
public:
	int ID = 4;
	MainMenu(View* NewAppView);
	~MainMenu();
	void ShowMenuBody();
	void ProcessInputAction();
};
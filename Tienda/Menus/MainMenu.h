#pragma once
#include "IMenu.h"

class MainMenu : public IMenu {
public:
	MainMenu(View* NewAppView);
	~MainMenu();
	void ShowMenuBody();
	void ProcessInputAction();
};
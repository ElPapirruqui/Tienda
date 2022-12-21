#pragma once
#include "IMenu.h"

class HistorialMenu : public IMenu {
public:
	HistorialMenu(View* NewAppView);
	~HistorialMenu();
	void ShowMenuBody();
	void ProcessInputAction();
};
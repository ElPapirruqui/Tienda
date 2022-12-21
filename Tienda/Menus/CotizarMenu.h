#pragma once
#include "IMenu.h"

class CotizarMenu : public IMenu {
public:
	int ID = 1;
	CotizarMenu(View* NewAppView);
	~CotizarMenu();
	void ShowMenuBody();
	void ProcessInputAction();
};
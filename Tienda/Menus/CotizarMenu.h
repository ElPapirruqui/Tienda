#pragma once
#include "IMenu.h"

class CotizarMenu : public IMenu {
public:
	CotizarMenu(View* NewAppView);
	~CotizarMenu();
	void ShowMenuBody();
	void ProcessInputAction();
};
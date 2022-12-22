#pragma once
#include "IMenu.h"

class CotizarMenu : public IMenu {
public:
	int ID = 1;
	CotizarMenu(Presenter* NewAppPresenter);
	~CotizarMenu();
	void ShowMenuBody();
	void ProcessInputAction();
};
#pragma once
#include "IMenu.h"
#include<string>

using namespace std;

class ErrorMenu : public IMenu {
public:
	int ID = 2;
	ErrorMenu(View* NewAppView, IMenu* PrevMenu, string ErrorMsg);
	~ErrorMenu();
	void ShowMenuBody();
	void ProcessInputAction();
private:
	IMenu* PreviousMenu;
	string ErrorMessage;
};
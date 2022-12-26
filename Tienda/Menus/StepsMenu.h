#pragma once
#include "IMenu.h"
#include<vector>

struct SPrendaChoice;

class StepsMenu : public IMenu {
public:
	int ID = 5;
	StepsMenu(Presenter* NewAppView);
	~StepsMenu();
	void ShowMenuBody();
	void UpdateBody();
	void UpdateBody(SPrendaChoice* NewStep);
protected:
	void ProcessInputAction();
private:
	const int STEP_OFFSET = 2;
	SPrendaChoice* Step;
};
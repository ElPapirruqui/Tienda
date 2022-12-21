#pragma once
#include "IMenu.h"
#include "../Prendas/SPrendaChoice.h"
#include<vector>

//struct SPrendaChoice;

class StepsMenu : public IMenu {
public:
	int ID = 5;
	StepsMenu(View* NewAppView);
	~StepsMenu();
	void ShowMenuBody();
protected:
	void ProcessInputAction();
private:
	const int STEP_OFFSET = 2;
	SPrendaChoice Step;
	int CurrentStep = 0;
};
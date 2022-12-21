#pragma once
#include "IMenu.h"
#include<vector>

struct SPrendaChoice;

class StepsMenu : public IMenu {
public:
	StepsMenu(View* NewAppView);
	~StepsMenu();
	void ShowMenuBody();
protected:
	void ProcessInputAction();
private:
	const int STEP_OFFSET = 2;
	std::vector<SPrendaChoice> Choices;
	int CurrentStep;
};
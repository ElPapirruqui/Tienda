#pragma once
#include<string>

enum class EPrendaType;
enum class EMenu { Main, History, Cotizar, Steps, Price, Quantity};

class View;

class IMenu {
public:
	IMenu(View* NewAppView);
	virtual ~IMenu();
	void ShowMenu();
	virtual void ShowMenuBody() = 0;
protected:
	View* AppView;
	void PrintText(std::string Text);
	void Break();
	void PrintRow();
	void GetInput();
	void ProcessInput();
	virtual void ProcessInputAction() = 0;
	virtual void OpenMenu(EMenu NewMenu);
	virtual void SetNewPrenda(EPrendaType NewPrendaType);
	virtual void Exit();
	int MenuOption = 0;
	bool QuitMenu = false;
};
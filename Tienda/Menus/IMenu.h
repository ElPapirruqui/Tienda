#pragma once
#include<string>

using namespace std;

enum class EPrendaType;
enum class EMenu { Main, History, Cotizar, Steps, Error};

class View;

class IMenu {
public:
	int ID = 0;
	IMenu(View* NewAppView);
	virtual ~IMenu();
	void ShowMenu();
	virtual void ShowMenuBody() = 0;
	void Close();
protected:
	View* AppView;
	void PrintText(std::string Text, bool bIsEndOfLine = true);
	void Break();
	void PrintRow();
	void GetInput();
	void ProcessInput();
	virtual void ProcessInputAction() = 0;
	virtual void OpenMenu(EMenu NewMenu);
	virtual void SetNewPrenda(EPrendaType NewPrendaType);
	int MenuOption = 0;
	bool QuitMenu = false;
	string ErrorMessage;
};
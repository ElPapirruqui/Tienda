#pragma once
#include<string>

using namespace std;

enum class EPrendaType;
enum class EMenu { Main, History, Cotizar, Steps, Error};

class Presenter;

class IMenu {
public:
	int ID = 0;
	IMenu(Presenter* NewAppPresenter);
	virtual ~IMenu();
	void ShowMenu();
	virtual void ShowMenuBody() = 0;
	void Close();
protected:
	Presenter* AppPresenter;
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
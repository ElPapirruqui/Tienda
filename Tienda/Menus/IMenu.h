#pragma once
#include<string>

using namespace std;

enum class EPrendaType;
enum class EMenu;

class Presenter;

class IMenu {
public:
	int ID = 0;
	IMenu(Presenter* NewAppPresenter);
	virtual ~IMenu();
	void ShowMenu();
	void SetError(string NewError);
	void ShowError();
	virtual void ShowMenuBody() = 0;
	void Close();
	virtual void UpdateBody() = 0;
protected:
	Presenter* AppPresenter;
	void PrintText(std::string Text, bool bIsEndOfLine = true);
	void Break();
	void PrintRow();
	void GetInput();
	void ProcessInput();
	bool IsNumber(int Number);
	virtual void ProcessInputAction() = 0;
	virtual void OpenMenu(EMenu NewMenu);	
	int MenuOption = 0;
	bool QuitMenu = false;
	string ErrorMessage;
	bool bShowError = false;
	string Title;
	bool bIsMainMenu = false;
};
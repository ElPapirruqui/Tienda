#include "../Presenter/Presenter.h"
#include "IMenu.h"
#include<iostream>

using namespace std;

IMenu::IMenu(Presenter* NewAppPresenter):AppPresenter(NewAppPresenter) {

}

IMenu::~IMenu() {
	Close();
	cout << "IMenu Destructor" << endl;
}

void IMenu::ShowMenu() {
    while (!QuitMenu)
    {
		if (AppPresenter == nullptr) {
			cout << "Null Presenter. Abort" << endl;
			return;
		};
        std::system("CLS");
		if (bShowError) {
			Break();
			PrintRow();
			PrintText("ERROR: " + ErrorMessage);
			PrintRow();
			Break();
			bShowError = false;
		}
		PrintText("COTIZADOR EXPRESS - " + Title);
		PrintRow();
		if (!bIsMainMenu) {
			PrintText("Presiona 3 para volver al menu principal");
			PrintRow();
		}
		ShowMenuBody();
        GetInput();
        ProcessInput();
    }
}

void IMenu::SetError(string NewError) {
	ErrorMessage = NewError;
}

void IMenu::ShowError() {
	bShowError = true;
}

void IMenu::PrintText(string Text, bool bIsEndOfLine) {
	cout << Text;
	if (bIsEndOfLine) {
		cout << endl;
	}
}

void IMenu::Break() {
	cout << "" << endl;
}

void IMenu::PrintRow() {
	cout << "------------------------------------------------" << endl;
}

void IMenu::GetInput() {
	cin >> MenuOption;
}

void IMenu::ProcessInput() {
	if (!std::cin.good() || !IsNumber(MenuOption)) {
		std::cin.clear();
		std::cin.ignore(numeric_limits<streamsize>::max(), '\n');
		ShowError();
		return;
	};
	ProcessInputAction();
	MenuOption = 0;
}

void IMenu::OpenMenu(EMenu NewMenu) {
	MenuOption = 0;
	AppPresenter->RenderMenu(NewMenu);
}

void IMenu::Close() {
	QuitMenu = true;
}

bool IMenu::IsNumber(int Number) {
	string StrNumber = to_string(MenuOption);
	auto LenghtOne = strspn(StrNumber.c_str(), "0123456789");
	auto LenghtTwo = StrNumber.length();
	bool Result = LenghtOne == LenghtTwo;

	return Result;
}
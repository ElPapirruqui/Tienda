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
		if (!ErrorMessage.empty()) {
			Break();
			PrintRow();
			PrintText("ERROR: " + ErrorMessage);
			PrintRow();
			Break();
			ErrorMessage = "";
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

void IMenu::ShowError(string NewError) {
	ErrorMessage = NewError;
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
	if (!std::cin.good()) {
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		return;
	};
	ProcessInputAction();
}

void IMenu::OpenMenu(EMenu NewMenu) {
	MenuOption = 0;
	AppPresenter->RenderMenu(NewMenu);
}

void IMenu::Close() {
	QuitMenu = true;
}
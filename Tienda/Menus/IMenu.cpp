#include "../Prendas/EPrendaType.h"
#include "../View/View.h"
#include "IMenu.h"
#include<iostream>

using namespace std;

IMenu::IMenu(View* NewAppView):AppView(NewAppView) {

}

IMenu::~IMenu() {
	Close();
	cout << "IMenu Destructor" << endl;
}

void IMenu::ShowMenu() {
    while (!QuitMenu)
    {
		if (AppView == nullptr) {
			cout << "ERROR" << endl;
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
		ShowMenuBody();
        GetInput();
        ProcessInput();
    }
}

void IMenu::PrintText(string Text, bool bIsEndOfLine) {
	cout << Text;
	if (bIsEndOfLine) {
		cout << endl;
	}
}

void IMenu::Break() {
	cout << "\n" << endl;
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
	AppView->RenderMenu(NewMenu);
}

void IMenu::SetNewPrenda(EPrendaType NewPrendaType) {
	MenuOption = 0;
	AppView->SetNewPrenda(NewPrendaType);
}

void IMenu::Close() {
	QuitMenu = true;
}
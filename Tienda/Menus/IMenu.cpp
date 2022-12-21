#include "../Prendas/EPrendaType.h"
#include "../View/View.h"
#include "IMenu.h"
#include<iostream>

using namespace std;

IMenu::IMenu(View* NewAppView):AppView(NewAppView) {

}

IMenu::~IMenu() {
	cout << "IMenu Destructor" << endl;
}

void IMenu::ShowMenu() {
    while (!QuitMenu)
    {
        std::system("CLS");
		ShowMenuBody();
        GetInput();
        ProcessInput();
    }
}

void IMenu::PrintText(string Text) {
	cout << Text << endl;
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
	AppView->RenderMenu(NewMenu);
	MenuOption = 0;
}

void IMenu::SetNewPrenda(EPrendaType NewPrendaType) {
	AppView->SetNewPrenda(NewPrendaType);
	MenuOption = 0;
}

void IMenu::Exit() {
	QuitMenu = true;
}
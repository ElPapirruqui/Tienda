#include<iostream>
#include "../Presenter/Presenter.h"
#include "../Enum/EMenu.h"
#include "ErrorMenu.h"

using namespace std;

ErrorMenu::ErrorMenu(Presenter* NewAppPresenter, IMenu* PrevMenu, string ErrorMsg) :IMenu(NewAppPresenter), PreviousMenu(PrevMenu), ErrorMessage(ErrorMsg) {
    QuitMenu = false;
    Title = "ERROR";
}

ErrorMenu::~ErrorMenu() {
    cout << "ErrorMenu Destructor" << endl;
}

void ErrorMenu::ShowMenuBody() {
    Break();
    PrintText(ErrorMessage);
}

void ErrorMenu::ProcessInputAction() {
    switch (MenuOption)
    {
    case 3:
        OpenMenu(EMenu::Main);
        break;
    }
}

void ErrorMenu::UpdateBody() {}
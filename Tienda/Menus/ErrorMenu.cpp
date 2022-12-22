#include<iostream>
#include "../Presenter/Presenter.h"
#include "ErrorMenu.h"

using namespace std;

ErrorMenu::ErrorMenu(Presenter* NewAppPresenter, IMenu* PrevMenu, string ErrorMsg) :IMenu(NewAppPresenter), PreviousMenu(PrevMenu), ErrorMessage(ErrorMsg) {}

ErrorMenu::~ErrorMenu() {
    cout << "ErrorMenu Destructor" << endl;
}

void ErrorMenu::ShowMenuBody() {
    PrintText("COTIZADOR EXPRESS - ERROR");
    PrintRow();
    PrintText("Presiona 3 para volver");
    PrintRow();
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
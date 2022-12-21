#include<iostream>
#include "../View/View.h"
#include "ErrorMenu.h"

using namespace std;

ErrorMenu::ErrorMenu(View* NewAppView, IMenu* PrevMenu, string ErrorMsg) :IMenu(NewAppView), PreviousMenu(PrevMenu), ErrorMessage(ErrorMsg) {}

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
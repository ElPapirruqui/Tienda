#include<iostream>
#include "../Prendas/EPrendaType.h"
#include "../View/View.h"
#include "CotizarMenu.h"

using namespace std;

CotizarMenu::CotizarMenu(View* NewAppView) :IMenu(NewAppView) {
}

CotizarMenu::~CotizarMenu() {
    cout << "CotizarMenu Destructor" << endl;
}

void CotizarMenu::ShowMenuBody() {
    PrintText("COTIZADOR EXPRESS - COTIZAR");
    PrintRow();
    PrintText("Presiona 3 para volver al menu principal");
    PrintRow();
    PrintText("PASO 1: Selecciana la prenda a cotizar : ");
    PrintText("1) Camisa");
    PrintText("2) Pantalon");
    PrintRow();
}

void CotizarMenu::ProcessInputAction() {
    switch (MenuOption)
    {
        case 1:
            SetNewPrenda(EPrendaType::Camisa);
            OpenMenu(EMenu::Steps);
        break;
        case 2:
            SetNewPrenda(EPrendaType::Pantalon);
            OpenMenu(EMenu::Steps);
        break;
        case 3:
            OpenMenu(EMenu::Main);
        break;
    }
}
#include<iostream>
#include "../Enum/EPrendaType.h"
#include "../Enum/EMenu.h"
#include "../Presenter/Presenter.h"
#include "CotizarMenu.h"

using namespace std;

CotizarMenu::CotizarMenu(Presenter* NewAppPresenter) :IMenu(NewAppPresenter) {
    QuitMenu = false;
    Title = "COTIZAR";
}

CotizarMenu::~CotizarMenu() {
    cout << "CotizarMenu Destructor" << endl;
}

void CotizarMenu::ShowMenuBody() {
    PrintText("PASO 1: Selecciana la prenda a cotizar : ");
    PrintText("1) Camisa");
    PrintText("2) Pantalon");
    PrintRow();
}

void CotizarMenu::ProcessInputAction() {
    switch (MenuOption)
    {
        case 1:
            AppPresenter->SetNewPrenda(EPrendaType::Camisa);
        break;
        case 2:
            AppPresenter->SetNewPrenda(EPrendaType::Pantalon);
        break;
        case 3:
            OpenMenu(EMenu::Main);
        break;
    }
}

void CotizarMenu::UpdateBody() {}
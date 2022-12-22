#include<iostream>
#include "../Presenter/Presenter.h"
#include "MainMenu.h"

using namespace std;

MainMenu::MainMenu(Presenter* NewAppPresenter):IMenu(NewAppPresenter) {
    QuitMenu = false;
    bIsMainMenu = true;
    Title = "MENU PRINCIPAL";
}

MainMenu::~MainMenu() {
	cout << "MainMenu Destructor" << endl;
}

void MainMenu::ShowMenuBody() { 
        PrintText(StoreName+" | "+StoreAddress);
        PrintRow();
        PrintText(VendorFullName+" | "+VendorID);
        PrintRow();
        Break();
        PrintText("SELECCIONE UNA OPCION DEL MENU :");
        Break();
        PrintText("1) Historial de Cotizaciones");
        PrintText("2) Realizar Cotizacion");
        PrintText("3) Salir");
}

void MainMenu::ProcessInputAction() {
    switch (MenuOption)
    {
        case 1:
            OpenMenu(EMenu::History);
        break;
        case 2:
            OpenMenu(EMenu::Cotizar);
        break;
        case 3:
            Close();
        break;
    }    
}

void MainMenu::SetStoreAndVendorInfo(string NewStoreName, string NewStoreAddress, string NewVendorFullName, string NewVendorID) {
    StoreName = NewStoreName;
    StoreAddress = NewStoreAddress;
    VendorFullName = NewVendorFullName;
    VendorID = NewVendorID;
}

void MainMenu::UpdateBody() {}
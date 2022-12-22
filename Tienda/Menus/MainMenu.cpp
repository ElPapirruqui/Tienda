#include<iostream>
#include "../Presenter/Presenter.h"
#include "MainMenu.h"

using namespace std;

MainMenu::MainMenu(Presenter* NewAppPresenter):IMenu(NewAppPresenter) {
}

MainMenu::~MainMenu() {
	cout << "MainMenu Destructor" << endl;
}

void MainMenu::ShowMenuBody() {    
        PrintText("COTIZADOR EXPRESS - MENU PRINCIPAL");
        PrintRow();
        PrintText("Nombre de la tienda | Direccion de la tienda");
        PrintRow();
        PrintText("Nombre y Apellido del vendedor | Código del vendedor");
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
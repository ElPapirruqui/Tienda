#include<iostream>
#include "../View/View.h"
#include "HistorialMenu.h"

using namespace std;

HistorialMenu::HistorialMenu(View* NewAppView):IMenu(NewAppView) {
}

HistorialMenu::~HistorialMenu() {
    cout << "HistorialMenu Destructor" << endl;
}

void HistorialMenu::ShowMenuBody() {
    PrintText("COTIZADOR EXPRESS - HISTORIAL DE COTIZACIONES");
    PrintRow();
    PrintText("Presiona 3 para volver al men� principal");
    PrintRow();
    PrintText("N�mero de identificaci�n : 001");
    PrintText("Fecha y Hora de la cotizaci�n : 18 / 01 / 2022 15 : 30");
    PrintText("C�digo del Vendedor : 001");
    PrintText("Prenda cotizada : Camisa - Manga corta - Premium Precio unitario : $xx, xx");
    PrintText("Cantidad de unidades cotizadas : 17");
    PrintText("Precio Final : $xx, xx");
    Break();
    PrintText("N�mero de identificaci�n : 002");
    PrintText("Fecha y Hora de la cotizaci�n : 20 / 01 / 2022 12 : 10");
    PrintText("C�digo del Vendedor : 001");
    PrintText("Prenda cotizada : Pantal�n - Standard Precio unitario : $xx, xx ");
    PrintText("Cantidad de unidades cotizadas : 8");
    PrintText("Precio Final : $xx, xx");
    PrintRow();
    PrintText("Presiona 3 para volver al men� principal");
}

void HistorialMenu::ProcessInputAction() {    
    switch (MenuOption)
    {
        case 3:
            OpenMenu(EMenu::Main);
        break;
    }
}
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
    PrintText("Presiona 3 para volver al menú principal");
    PrintRow();
    PrintText("Número de identificación : 001");
    PrintText("Fecha y Hora de la cotización : 18 / 01 / 2022 15 : 30");
    PrintText("Código del Vendedor : 001");
    PrintText("Prenda cotizada : Camisa - Manga corta - Premium Precio unitario : $xx, xx");
    PrintText("Cantidad de unidades cotizadas : 17");
    PrintText("Precio Final : $xx, xx");
    Break();
    PrintText("Número de identificación : 002");
    PrintText("Fecha y Hora de la cotización : 20 / 01 / 2022 12 : 10");
    PrintText("Código del Vendedor : 001");
    PrintText("Prenda cotizada : Pantalón - Standard Precio unitario : $xx, xx ");
    PrintText("Cantidad de unidades cotizadas : 8");
    PrintText("Precio Final : $xx, xx");
    PrintRow();
    PrintText("Presiona 3 para volver al menú principal");
}

void HistorialMenu::ProcessInputAction() {    
    switch (MenuOption)
    {
        case 3:
            OpenMenu(EMenu::Main);
        break;
    }
}
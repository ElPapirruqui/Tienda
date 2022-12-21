#include<iostream>
#include "../View/View.h"
#include "HistorialMenu.h"
#include <iomanip>

using namespace std;

HistorialMenu::HistorialMenu(View* NewAppView):IMenu(NewAppView){}

HistorialMenu::~HistorialMenu() {
    cout << "HistorialMenu Destructor" << endl;
}

void HistorialMenu::SetHistoryData(SHistoryData& NewHistoryData) {
    HistoryData = &NewHistoryData;
}

void HistorialMenu::SetHistoryData(vector<SHistoryData>& NewHistoryData) {
    HistoryDataVector = &NewHistoryData;
}

void HistorialMenu::ShowMenuBody() {
    PrintText("COTIZADOR EXPRESS - HISTORIAL DE COTIZACIONES");
    PrintRow();
    PrintText("Presiona 3 para volver al menú principal");
    PrintRow();
    if (HistoryDataVector != nullptr) {
        for (int i = 0; i < HistoryDataVector->size(); i++) {
            ShowHistoryItems(&HistoryDataVector->at(i));
            Break();
        }
    }
    else if(HistoryData != nullptr){
        ShowHistoryItems(HistoryData);
    }
}

void HistorialMenu::ShowHistoryItems(SHistoryData* HistoryItem) {
    PrintText("Número de identificación : " + HistoryItem->ID);
    PrintText("Fecha y Hora de la cotización : " + HistoryItem->Date);
    PrintText("Código del Vendedor : " + HistoryItem->VendorID);
    PrintText("Prenda cotizada : " + HistoryItem->PrendaProperties);
    PrintText("Precio unitario : $", false);
    cout << fixed << setprecision(2) << HistoryItem->UnitPrice << endl;
    PrintText("Cantidad de unidades cotizadas : " + to_string(HistoryItem->Quantity));
    PrintText("Precio Final : $", false);
    cout << fixed << setprecision(2) << HistoryItem->FinalPrice << endl;
}

void HistorialMenu::ProcessInputAction() {    
    switch (MenuOption)
    {
        case 3:
            OpenMenu(EMenu::Main);
        break;
    }
}
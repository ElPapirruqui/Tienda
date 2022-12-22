#include<iostream>
#include "../Presenter/Presenter.h"
#include "../Enum/EMenu.h"
#include "HistorialMenu.h"
#include <iomanip>

using namespace std;

HistorialMenu::HistorialMenu(Presenter* NewAppPresenter):IMenu(NewAppPresenter){
    QuitMenu = false;
    Title = "HISTORIAL DE COTIZACIONES";
}

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
    PrintText("Numero de identificacion : " + HistoryItem->ID);
    PrintText("Fecha y Hora de la cotizacion : " + HistoryItem->Date);
    PrintText("Codigo del Vendedor : " + HistoryItem->VendorID);
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

void HistorialMenu::UpdateBody() {}
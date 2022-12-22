#include<iostream>
#include "../Presenter/Presenter.h"

#include "StepsMenu.h"
#include<string>
#include <limits>

using namespace std;

StepsMenu::StepsMenu(Presenter* AppPresenter) :IMenu(AppPresenter) {
    Step = AppPresenter->GetNextStep(CurrentStep);
}

StepsMenu::~StepsMenu() {
    cout << "StepsMenu Destructor" << endl;
}

void StepsMenu::ShowMenuBody() {
    PrintText("COTIZADOR EXPRESS - COTIZAR");
    PrintRow();
    PrintText("Presiona 3 para volver al menu principal");
    PrintRow();
    if (!Step.Info.empty()) {
        Break();
        PrintText(Step.Info);
        Break();
    }
    vector<EPrendaType> CurrentChoices = Step.Choices;
    string Title = "PASO " + to_string(CurrentStep+STEP_OFFSET) + ": " + Step.Message;
    PrintText(Title);
    int ItemNumber = 1;
    for (EPrendaType Choice : CurrentChoices) {
        string ItemText = to_string(ItemNumber) + ") " + PrendaType::TypeNames[Choice];
        PrintText(ItemText);
        ItemNumber++;
    }
    PrintRow();
}

void StepsMenu::ProcessInputAction() {
    vector<EPrendaType> CurrentChoices = Step.Choices;
    switch (MenuOption)
    {
        case 3:
            OpenMenu(EMenu::Main);
        break;
        default:
            switch (Step.StepType) {
                case EStepType::Choice:
                    if (MenuOption > 0 && MenuOption <= CurrentChoices.size()) {
                        CurrentStep++;
                        AppPresenter->AddPropertyToCurrentPrenda(CurrentChoices[MenuOption - 1]);
                        Step = AppPresenter->GetNextStep(CurrentStep);
                    }
                break;
                case EStepType::Price:
                    CurrentStep++;
                    AppPresenter->SetPriceToCurrentPrenda(MenuOption);
                    Step = AppPresenter->GetNextStep(CurrentStep);
                break;
                case EStepType::Quantity:
                    bool bIsAvailable = AppPresenter->SetQuantityToCurrentPrenda(MenuOption);
                    if (bIsAvailable) {
                        AppPresenter->NewHistoryRecord();
                    }
                    else {
                        ErrorMessage = "La cantidad seleccionada es mayor a la disponible en stock.";
                    }                    
                break;
            }
        break;
    }
}
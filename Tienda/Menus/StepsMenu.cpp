#include<iostream>
#include "../View/View.h"
#include "../Prendas/SPrendaChoice.h"
#include "StepsMenu.h"
#include<string>
#include <limits>

using namespace std;

StepsMenu::StepsMenu(View* NewAppView) :IMenu(NewAppView) {
    Choices = AppView->GetCotizacionSteps();
}

StepsMenu::~StepsMenu() {
    cout << "StepsMenu Destructor" << endl;
}

void StepsMenu::ShowMenuBody() {
    PrintText("COTIZADOR EXPRESS - COTIZAR");
    PrintRow();
    PrintText("Presiona 3 para volver al mend principal");
    PrintRow();
    if (CurrentStep < Choices.size()) {
        vector<EPrendaType> CurrentChoices = Choices[CurrentStep].Choices;
        string Title = "PASO " + to_string(CurrentStep+STEP_OFFSET) + ": " + Choices[CurrentStep].Message;
        PrintText(Title);
        int ItemNumber = 1;
        for (EPrendaType Choice : CurrentChoices) {
            string ItemText = to_string(ItemNumber) + ") " + PrendaType::TypeNames[Choice];
            PrintText(ItemText);
            ItemNumber++;
        }
    }
    PrintRow();
}

void StepsMenu::ProcessInputAction() {
    if (CurrentStep >= Choices.size()) return;
    SPrendaChoice Step = Choices[CurrentStep];
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
                        AppView->AddPropertyToCurrentPrenda(CurrentChoices[MenuOption - 1]);
                        CurrentStep++;
                    }
                break;
                case EStepType::Price:
                    AppView->SetPriceToCurrentPrenda(MenuOption);
                    CurrentStep++;
                break;
                case EStepType::Quantity:
                    CurrentStep++;
                break;
            }
        break;
    }
    if (CurrentStep >= Choices.size()) {
        AppView->NewHistoryRecord();
        OpenMenu(EMenu::History);
    }
}
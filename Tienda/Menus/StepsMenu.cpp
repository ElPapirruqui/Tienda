#include<iostream>
#include "../Presenter/Presenter.h"
#include "../Structs/SPrendaChoice.h"
#include "../Enum/EPrendaType.h"
#include "../Enum/EMenu.h"
#include "StepsMenu.h"
#include<string>
#include <limits>

using namespace std;

StepsMenu::StepsMenu(Presenter* AppPresenter) :IMenu(AppPresenter) {
    Title = "COTIZAR";
}

StepsMenu::~StepsMenu() {
    cout << "StepsMenu Destructor" << endl;
}

void StepsMenu::ShowMenuBody() {
    if (!Step->Info.empty()) {
        Break();
        PrintText(Step->Info);
        Break();
    }
    vector<EPrendaType> CurrentChoices = Step->Choices;
    string Title = "PASO " + to_string(Step->Iteration+STEP_OFFSET) + ": " + Step->Message;
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
    switch (MenuOption)
    {
        case 3:
            OpenMenu(EMenu::Main);
        break;
        default:
            AppPresenter->ProcessStepChoice(MenuOption, Step);
        break;
    }
}

void StepsMenu::UpdateBody() {}

void StepsMenu::UpdateBody(SPrendaChoice* NewStep) {
    Step = NewStep;
}
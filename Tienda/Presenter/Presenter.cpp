#include "../Prendas/PrendaFactory.h"
#include "../Store/Store.h"
#include "../Store/Vendedor.h"
#include "../Store/History.h"
#include "../Menus/IMenu.h"
#include "../Menus/MainMenu.h"
#include "../Menus//HistorialMenu.h"
#include "../Menus/CotizarMenu.h"
#include "../Menus/StepsMenu.h"
#include "../Structs/SHistoryData.h"
#include "../Enum/EMenu.h"
#include "../Enum/EStepType.h"
#include "../Prendas/IPrenda.h"
#include<iostream>
#include <iomanip>
#include <chrono>
#include <ctime>
#include "Presenter.h"


using namespace std;

Presenter::Presenter() {
	StoreUP = make_unique<Store>();
	StorePtr = StoreUP.get();
	PrendaFactoryUP = make_unique<PrendaFactory>();
	PrendaFactoryPtr = PrendaFactoryUP.get();
	
}

Presenter::~Presenter() {
	cout << "Presenter Destructor" << endl;
}

SPrendaChoice* Presenter::GetNextStep(int NextStep) {
	SPrendaChoice* PrendaStep = nullptr;
	IPrenda* CurrentPrenda = PrendaFactoryPtr->GetCurrentPrenda();
	if (CurrentPrenda == nullptr) return PrendaStep;
	EPrendaType Type = CurrentPrenda->GetType();
	PrendaStep = &PrendaFactoryPtr->GetCotizacionStep(Type, NextStep);
	PrendaStep->Iteration = NextStep;
	if (PrendaStep->StepType == EStepType::Quantity) {
		SPrendaData* PrendaData = StorePtr->FindPrenda(CurrentPrenda->GetPrendaData());
		if (PrendaData != nullptr) {
			PrendaFactoryPtr->UpdateStepQuantity(PrendaStep, PrendaData->Count);
		}
	}
	return PrendaStep;
}

void Presenter::Start() {
	RenderMenu(EMenu::Main);
}

void Presenter::RenderMenu(EMenu NewMenu) {
	if(CurrentMenuPtr != nullptr) CurrentMenuPtr->Close();
	switch (NewMenu) {
		case EMenu::Main:
			RenderMainMenu();
		break;
		case EMenu::History:
			ShowHistoryRecords();
		break;
		case EMenu::Cotizar:
			CurrentMenuUP = make_unique<CotizarMenu>(this);
			CurrentMenuPtr = CurrentMenuUP.get();
			CurrentMenuPtr->ShowMenu();
		break;
		case EMenu::Steps:
			RenderStepsMenu();
		break;
	}
}

void Presenter::RenderMainMenu() {
	CurrentMenuUP = make_unique<MainMenu>(this);
	CurrentMenuPtr = CurrentMenuUP.get();
	static_cast<MainMenu*>(CurrentMenuPtr)->SetStoreAndVendorInfo(StorePtr->GetName(), StorePtr->GetAddress(), StorePtr->GetCurrentVendedor()->GetFullName(), StorePtr->GetCurrentVendedor()->GetID());
	CurrentMenuPtr->ShowMenu();
}

void Presenter::RenderStepsMenu() {
	CurrentMenuUP = make_unique<StepsMenu>(this);
	CurrentMenuPtr = CurrentMenuUP.get();
	UpdateStepBody(0);
	CurrentMenuPtr->ShowMenu();
}

void Presenter::RenderHistoryMenu(SHistoryData& History) {
	CurrentMenuUP = make_unique<HistorialMenu>(this);
	CurrentMenuPtr = CurrentMenuUP.get();
	static_cast<HistorialMenu*>(CurrentMenuPtr)->SetHistoryData(History);
	CurrentMenuPtr->ShowMenu();
}

void Presenter::RenderHistoryMenu(vector<SHistoryData>& History) {
	CurrentMenuUP = make_unique<HistorialMenu>(this);
	CurrentMenuPtr = CurrentMenuUP.get();
	static_cast<HistorialMenu*>(CurrentMenuPtr)->SetHistoryData(History);
	CurrentMenuPtr->ShowMenu();
}

void Presenter::SetNewPrenda(EPrendaType NewPrendaType) {
	PrendaFactoryPtr->SetCurrentPrenda(NewPrendaType);
	RenderMenu(EMenu::Steps);
}

void Presenter::ProcessStepChoice(int MenuOption, SPrendaChoice* Step) {
	vector<EPrendaType>& CurrentChoices = Step->Choices;
	switch (Step->StepType) {
	case EStepType::Choice:
		if (MenuOption > 0 && MenuOption <= CurrentChoices.size()) {
			AddPropertyToCurrentPrenda(CurrentChoices[MenuOption - 1]);
			UpdateStepBody(Step->Iteration + 1);
		}
		break;
	case EStepType::Price:
		SetPriceToCurrentPrenda(MenuOption);
		UpdateStepBody(Step->Iteration + 1);
		break;
	case EStepType::Quantity:
		bool bIsAvailable = SetQuantityToCurrentPrenda(MenuOption);
		if (bIsAvailable) {
			CurrentMenuPtr->Close();
			NewHistoryRecord();
		}
		else {
			CurrentMenuPtr->ShowError("La cantidad seleccionada es mayor a la disponible en stock.");
		}
		break;
	}
}

void Presenter::AddPropertyToCurrentPrenda(EPrendaType PrendaProperty) {
	PrendaFactoryPtr->AddPrendaProperty(PrendaProperty);
}

void Presenter::SetPriceToCurrentPrenda(int NewPrice) {
	PrendaFactoryPtr->SetNewPrice(NewPrice);
}

void Presenter::UpdateStepBody(int NextStep) {
	static_cast<StepsMenu*>(CurrentMenuPtr)->UpdateBody(GetNextStep(NextStep));
}

bool Presenter::SetQuantityToCurrentPrenda(int NewQuantity) {
	bool bIsAvailable = StorePtr->CheckStock(NewQuantity);
	if (bIsAvailable) {
		PrendaFactoryPtr->SetNewQuantity(NewQuantity);
		StorePtr->UpdateStock(NewQuantity);
		return true;
	}
	else {
		return false;
	}
}

void Presenter::NewHistoryRecord() {
	IPrenda* CurrentPrenda = PrendaFactoryPtr->GetCurrentPrenda();
	float NewPrice = CurrentPrenda->GetFinalPrice();
	Vendedor* Vendedor = StorePtr->GetCurrentVendedor();
	History* History = Vendedor->GetHistory();
	SHistoryData& LastHistory = History->AddToHistory(CurrentDateTime(), Vendedor->GetID(), CurrentPrenda->GetPropertiesAsString(), CurrentPrenda->GetBasePrice(), CurrentPrenda->GetPrendaData().Count, CurrentPrenda->GetFinalPrice());
	RenderHistoryMenu(LastHistory);
}

void Presenter::ShowHistoryRecords() {
	Vendedor* Vendedor = StorePtr->GetCurrentVendedor();
	History* History = Vendedor->GetHistory();
	vector<SHistoryData>& HistoryRecords = History->GetHistoryData();
	RenderHistoryMenu(HistoryRecords);
}

string Presenter::CurrentDateTime() {
	time_t     now = time(0);
	struct tm  tstruct;
	char       buf[80];
	localtime_s(&tstruct, &now);	
	strftime(buf, sizeof(buf), "%d/%m/%Y %R", &tstruct);

	return buf;
}
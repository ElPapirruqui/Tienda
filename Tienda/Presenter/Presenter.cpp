#include "../Prendas/PrendaFactory.h"
#include "../Store/Store.h"
#include "../Store/Vendedor.h"
#include "../Menus/IMenu.h"
#include "../Menus/MainMenu.h"
#include "../Menus//HistorialMenu.h"
#include "../Menus/CotizarMenu.h"
#include "../Menus/StepsMenu.h"
#include "../Store/SHistoryData.h"
#include<iostream>
#include <iomanip>
#include <chrono>
#include <ctime>
#include "Presenter.h"


using namespace std;

Presenter::Presenter() {
	StoreUP = std::make_unique<Store>();
	StorePtr = StoreUP.get();
	PrendaFactoryUP = std::make_unique<PrendaFactory>();
	PrendaFactoryPtr = PrendaFactoryUP.get();
	VendedorUP = std::make_unique<Vendedor>();
	VendedorPtr = VendedorUP.get();
}

Presenter::~Presenter() {
	cout << "Presenter Destructor" << endl;
}

std::vector<SPrendaChoice> Presenter::GetCotizacionSteps() {
	vector<SPrendaChoice> PrendaChoices;
	IPrenda* CurrentPrenda = PrendaFactoryPtr->GetCurrentPrenda();
	if (CurrentPrenda == nullptr) return PrendaChoices;
	EPrendaType Type = CurrentPrenda->GetType();
	PrendaChoices = PrendaFactoryPtr->GetCotizacionSteps(Type);
	return PrendaChoices;
}

SPrendaChoice Presenter::GetNextStep(int NextStep) {
	SPrendaChoice PrendaStep;
	IPrenda* CurrentPrenda = PrendaFactoryPtr->GetCurrentPrenda();
	if (CurrentPrenda == nullptr) return PrendaStep;
	EPrendaType Type = CurrentPrenda->GetType();
	PrendaStep = PrendaFactoryPtr->GetCotizacionStep(Type, NextStep);
	if (PrendaStep.StepType == EStepType::Quantity) {
		SPrendaData* PrendaData = StorePtr->FindPrenda(CurrentPrenda);
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
	switch (NewMenu) {
	case EMenu::Main:
		CurrentMenuUP = std::make_unique<MainMenu>(this);
		CurrentMenuPtr = CurrentMenuUP.get();
		break;
	case EMenu::History:
		ShowHistoryRecords();
		break;
	case EMenu::Cotizar:
		CurrentMenuUP = std::make_unique<CotizarMenu>(this);
		CurrentMenuPtr = CurrentMenuUP.get();
		break;
	case EMenu::Steps:
		CurrentMenuUP = std::make_unique<StepsMenu>(this);
		CurrentMenuPtr = CurrentMenuUP.get();

		break;
	}
	CurrentMenuPtr->ShowMenu();
}

void Presenter::RenderHistoryMenu(SHistoryData& History) {
	CurrentMenuUP = std::make_unique<HistorialMenu>(this);
	CurrentMenuPtr = CurrentMenuUP.get();
	static_cast<HistorialMenu*>(CurrentMenuPtr)->SetHistoryData(History);
	CurrentMenuPtr->ShowMenu();
}

void Presenter::RenderHistoryMenu(vector<SHistoryData>& History) {
	CurrentMenuUP = std::make_unique<HistorialMenu>(this);
	CurrentMenuPtr = CurrentMenuUP.get();
	static_cast<HistorialMenu*>(CurrentMenuPtr)->SetHistoryData(History);
	CurrentMenuPtr->ShowMenu();
}

void Presenter::SetNewPrenda(EPrendaType NewPrendaType) {
	PrendaFactoryPtr->SetCurrentPrenda(NewPrendaType);
}

void Presenter::AddPropertyToCurrentPrenda(EPrendaType PrendaProperty) {
	PrendaFactoryPtr->AddPrendaProperty(PrendaProperty);
}

void Presenter::SetPriceToCurrentPrenda(int NewPrice) {
	PrendaFactoryPtr->SetNewPrice(NewPrice);
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
	SHistoryData& LastHistory = StorePtr->AddToHistory(CurrentPrenda, CurrentDateTime(), VendedorPtr->GetID());
	RenderHistoryMenu(LastHistory);
}

void Presenter::ShowHistoryRecords() {
	vector<SHistoryData>& HistoryRecords = StorePtr->GetHistory();
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
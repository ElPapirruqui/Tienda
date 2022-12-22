#include<iostream>
#include "../Prendas/PrendaFactory.h"
#include "../Store/Store.h"
#include "../Store/Vendedor.h"
#include "../View/View.h"
#include "../Menus/IMenu.h"
#include "../Store/SHistoryData.h"
#include <iomanip>
#include <chrono>
#include <ctime>
#include "Presenter.h"


using namespace std;

Presenter::Presenter() {}

Presenter::Presenter(View* NewView):ViewPtr(NewView) {
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
	ViewPtr->RenderHistoryMenu(LastHistory);
}

void Presenter::ShowHistoryRecords() {
	vector<SHistoryData>& HistoryRecords = StorePtr->GetHistory();
	ViewPtr->RenderHistoryMenu(HistoryRecords);
}

std::string Presenter::CurrentDateTime() {
	time_t     now = time(0);
	struct tm  tstruct;
	char       buf[80];
	localtime_s(&tstruct, &now);	
	strftime(buf, sizeof(buf), "%d/%m/%Y %R", &tstruct);

	return buf;
}
#include<iostream>
#include "../Prendas/PrendaFactory.h"
#include "../Store/Store.h"
#include "Presenter.h"

using namespace std;

Presenter::Presenter() {
	StoreUP = std::make_unique<Store>();
	StorePtr = StoreUP.get();
	PrendaFactoryUP = std::make_unique<PrendaFactory>();
	PrendaFactoryPtr = PrendaFactoryUP.get();
}

Presenter::~Presenter() {
	cout << "Presenter Destructor" << endl;
}

std::vector<SPrendaChoice> Presenter::GetCotizacionSteps() {
	std::vector<SPrendaChoice> PrendaChoices;
	IPrenda* CurrentPrenda = PrendaFactoryPtr->GetCurrentPrenda();
	if (CurrentPrenda == nullptr) return PrendaChoices;
	EPrendaType Type = CurrentPrenda->GetType();
	PrendaChoices = PrendaFactoryPtr->GetCotizacionSteps(Type);
	return PrendaChoices;
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

void Presenter::NewHistoryRecord() {
	IPrenda* CurrentPrenda = PrendaFactoryPtr->GetCurrentPrenda();
	float NewPrice = CurrentPrenda->GetFinalPrice();
	int option = 0;
	while (option == 0) {
		cout << "NewPrice: " + to_string(NewPrice) << endl;
		cin >> option;
	}
}
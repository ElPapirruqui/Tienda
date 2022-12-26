#include<iostream>
#include "../Prendas/IPrenda.h"
#include "../Prendas/Camisa.h"
#include "../Prendas/Pantalon.h"
#include "../Prendas/Decorators/Chupin.h"
#include "../Prendas/Decorators/MangaCorta.h"
#include "../Prendas/Decorators/CuelloMao.h"
#include "../Prendas/Decorators/Premium.h"
#include "../Enum/EPrendaType.h"
#include "../Structs/SPrendaChoice.h"
#include "PrendaFactory.h"

using namespace std;

PrendaFactory::PrendaFactory() {}

PrendaFactory::~PrendaFactory() {
	cout << "PrendaFactory Destructor" << endl;
}

SPrendaChoice& PrendaFactory::GetCotizacionStep(EPrendaType PrendaType, int NextStep) {
	return GetCurrentPrenda()->PrendaChoices[NextStep];
}

void PrendaFactory::SetCurrentPrenda(EPrendaType PrendaType) {
	switch (PrendaType) {
		case EPrendaType::Camisa:
			PrendaUP = std::make_unique<Camisa>();
			PrendaPtr = PrendaUP.get();
		break;
		case EPrendaType::Pantalon:
			PrendaUP = std::make_unique<Pantalon>();
			PrendaPtr = PrendaUP.get();
		break;
	}
}

IPrenda* PrendaFactory::GetCurrentPrenda() {
	return PrendaPtr;
}

void PrendaFactory::AddPrendaProperty(EPrendaType PrendaProperty) {
	IPrenda* CurrentPrenda = GetCurrentPrenda();
	if (CurrentPrenda == nullptr) return;
	CurrentPrenda->AddProperty(PrendaProperty);
	std::unique_ptr<PrendaDecorator> NewPrendaUP;
	switch (PrendaProperty) {
		case EPrendaType::Chupin:
			NewPrendaUP = std::make_unique<Chupin>(PrendaPtr);
			PrendaPtr->Decorators.push_back(std::move(NewPrendaUP));
		break;
		case EPrendaType::MangaCorta:
			NewPrendaUP = std::make_unique<MangaCorta>(PrendaPtr);
			PrendaPtr->Decorators.push_back(std::move(NewPrendaUP));
		break;
		case EPrendaType::CuelloMao:
			NewPrendaUP = std::make_unique<CuelloMao>(PrendaPtr);
			PrendaPtr->Decorators.push_back(std::move(NewPrendaUP));
		break;
		case EPrendaType::Premium:
			NewPrendaUP = std::make_unique<Premium>(PrendaPtr);
			PrendaPtr->Decorators.push_back(std::move(NewPrendaUP));
		break;
	}
}

void PrendaFactory::SetNewPrice(int NewPrice) {
	PrendaPtr->SetPrice(NewPrice);
}

void PrendaFactory::SetNewQuantity(int NewQuantity) {
	PrendaPtr->SetQuantity(NewQuantity);
}

void PrendaFactory::UpdateStepQuantity(SPrendaChoice* CurrentStep, int Quantity) {
	CurrentStep->Info = "INFORMACION:\nEXISTE " + to_string(Quantity) + " CANTIDAD DE UNIDADES EN STOCK DE LA PRENDA SELECCIONADA";
}
#include<iostream>
#include "../Prendas/IPrenda.h"
#include "../Prendas/Camisa.h"
#include "../Prendas/Pantalon.h"
#include "../Prendas/Decorators/Chupin.h"
#include "../Prendas/Decorators/MangaCorta.h"
#include "../Prendas/Decorators/CuelloMao.h"
#include "../Prendas/Decorators/Premium.h"
#include "PrendaFactory.h"

using namespace std;

PrendaFactory::PrendaFactory() {}

PrendaFactory::~PrendaFactory() {
	cout << "PrendaFactory Destructor" << endl;
}

vector<SPrendaChoice>& PrendaFactory::GetCotizacionSteps(EPrendaType PrendaType) {
	if (PrendaChoices.empty()) {
		switch (PrendaType) {
			case EPrendaType::Camisa:
				PrendaChoices.push_back({ "Tipo de manga de la camisa", {EPrendaType::MangaCorta, EPrendaType::MangaLarga } });
				PrendaChoices.push_back({ "Tipo de cuello de la camisa", {EPrendaType::CuelloComun, EPrendaType::CuelloMao } });
				PrendaChoices.push_back({ "Calidad de la camisa", {EPrendaType::Standard, EPrendaType::Premium } });
			break;
			case EPrendaType::Pantalon:
				PrendaChoices.push_back({ "Tipo de pantalon", {EPrendaType::Chupin, EPrendaType::Clasico } });
				PrendaChoices.push_back({ "Calidad del pantalon", {EPrendaType::Standard, EPrendaType::Premium } });
			break;
		}
		PrendaChoices.push_back({ "Ingrese el precio unitario de la prenda a cotizar", {}, EStepType::Price});
		PrendaChoices.push_back({ "Ingrese la cantidad de unidades a cotizar", {}, EStepType::Quantity, "" });
	}
	return PrendaChoices;
}

SPrendaChoice& PrendaFactory::GetCotizacionStep(EPrendaType PrendaType, int NextStep) {
	return GetCotizacionSteps(PrendaType)[NextStep];
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

void PrendaFactory::ClearChoices() {
	PrendaChoices.clear();
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
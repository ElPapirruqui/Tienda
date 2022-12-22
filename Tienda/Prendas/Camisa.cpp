#include<iostream>
#include "Decorators/PrendaDecorator.h"
#include "../Enum/EPrendaType.h"
#include "../Structs/SPrendaChoice.h"
#include "Camisa.h"

using namespace std;

Camisa::Camisa() {
	PrendaData.PrendaType = EPrendaType::Camisa;
	PrendaData.PrendaProperties.push_back(EPrendaType::Camisa);	
	PrendaChoices.push_back({ "Tipo de manga de la camisa", {EPrendaType::MangaCorta, EPrendaType::MangaLarga } });
	PrendaChoices.push_back({ "Tipo de cuello de la camisa", {EPrendaType::CuelloComun, EPrendaType::CuelloMao } });
	AddFinalChoices();
}

Camisa::~Camisa() {
	cout << "Camisa Destructor" << endl;
}

EPrendaType Camisa::GetType() {
	return PrendaData.PrendaType;
}

float Camisa::GetFinalPrice() {
	float Price = static_cast<float>(BasePrice);
	for (int i = 0; i < Decorators.size(); i++) {
		auto DecoratorUP = std::move(Decorators.at(i));
		auto DecoratorPtr = DecoratorUP.get();
		Price = DecoratorPtr->UpdatePrice(Price);
		Decorators[i] = std::move(DecoratorUP);
	}
	return Price * PrendaData.Count;
}
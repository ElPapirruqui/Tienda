#include<iostream>
#include "Decorators/PrendaDecorator.h"
#include "../Enum/EPrendaType.h"
#include "../Structs/SPrendaChoice.h"
#include "Pantalon.h"

using namespace std;

Pantalon::Pantalon() {
	PrendaData.PrendaType = EPrendaType::Pantalon;
	PrendaData.PrendaProperties.push_back(EPrendaType::Pantalon);
	PrendaChoices.push_back({ "Tipo de pantalon", "Seleccione una opcion valida", {EPrendaType::Chupin, EPrendaType::Clasico } });
	AddFinalChoices();	
}

Pantalon::~Pantalon() {
	cout << "Pantalon Destructor" << endl;
}

EPrendaType Pantalon::GetType() {
	return PrendaData.PrendaType;
}

float Pantalon::GetFinalPrice() {
	float Price = static_cast<float>(BasePrice);
	for (int i = 0; i < Decorators.size(); i++) {
		auto DecoratorUP = std::move(Decorators.at(i));
		auto DecoratorPtr = DecoratorUP.get();
		Price = DecoratorPtr->UpdatePrice(Price);
		Decorators[i] = std::move(DecoratorUP);
	}
	return Price * PrendaData.Count;
}
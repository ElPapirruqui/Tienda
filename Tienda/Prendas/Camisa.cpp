#include<iostream>
#include "Decorators/PrendaDecorator.h"
#include "Camisa.h"

using namespace std;

Camisa::Camisa() {
	PrendaData.PrendaType = EPrendaType::Camisa;
	PrendaData.PrendaProperties.push_back(EPrendaType::Camisa);
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
	return Price;
}
#include<iostream>
#include "Decorators/PrendaDecorator.h"
#include "Pantalon.h"

using namespace std;

Pantalon::Pantalon() {
	PrendaData.PrendaType = EPrendaType::Pantalon;
	PrendaData.PrendaProperties.push_back(EPrendaType::Pantalon);
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
	return Price;
}
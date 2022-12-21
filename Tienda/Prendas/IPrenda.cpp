#include<iostream>
#include "Decorators/PrendaDecorator.h"
#include "IPrenda.h"

using namespace std;

IPrenda::IPrenda() {}

IPrenda::~IPrenda() {
	cout << "IPrenda Destructor" << endl;
}

void IPrenda::AddProperty(EPrendaType PrendaProperty) {
	IPrenda* NewPrenda = nullptr;
	PrendaData.PrendaProperties.push_back(PrendaProperty);	
}

void IPrenda::SetPrice(int NewPrice) {
	BasePrice = NewPrice;
}

EPrendaType IPrenda::GetType() {
	return PrendaData.PrendaType;
}
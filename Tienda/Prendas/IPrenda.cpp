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

void IPrenda::SetQuantity(int NewQuantity) {
	PrendaData.Count = NewQuantity;
}

string IPrenda::GetPropertiesAsString() {
	string PropertiesStr = "";
	vector<EPrendaType>& PrendaProperties = PrendaData.PrendaProperties;
	bool bFirstItem = true;
	for (EPrendaType& PrendaData : PrendaProperties) {
		if (bFirstItem) {
			PropertiesStr += PrendaType::TypeNames[PrendaData];
			bFirstItem = false;
		}
		else {
			PropertiesStr += " - " + PrendaType::TypeNames[PrendaData];
		}
		
	}
	return PropertiesStr;
}

EPrendaType IPrenda::GetType() {
	return PrendaData.PrendaType;
}

SPrendaData& IPrenda::GetPrendaData() {
	return PrendaData;
}

int IPrenda::GetBasePrice() {
	return BasePrice;
}
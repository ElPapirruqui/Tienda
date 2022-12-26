#include<iostream>
#include "Vendedor.h"
#include "History.h"
#include "Store.h"

using namespace std;

Store::Store() {
	VendedorUP = make_unique<Vendedor>();
	VendedorPtr = VendedorUP.get();
}

Store::~Store() {
	cout << "Store Destructor" << endl;
}

SPrendaData* Store::FindPrenda(SPrendaData& CurrentPrendaData) {
	for (SPrendaData& PrendaData : Prendas) {
		if (CheckEquality(PrendaData, CurrentPrendaData)) {
			CurrentPrenda = &PrendaData;
			break;
		}
	}
	return CurrentPrenda;
}

bool Store::CheckStock(int NewQuantity) {
	return CurrentPrenda->Count >= NewQuantity;
}

void Store::UpdateStock(int Quantity) {
	CurrentPrenda->Count -= Quantity;
}

bool Store::CheckEquality(SPrendaData& PrendaDataRef, SPrendaData& CurrentPrendaData) {
	bool result;
	if (PrendaDataRef.PrendaProperties.size() >= CurrentPrendaData.PrendaProperties.size()) {
		result = std::equal(CurrentPrendaData.PrendaProperties.begin(), CurrentPrendaData.PrendaProperties.end(), PrendaDataRef.PrendaProperties.begin());
	}
	else {
		result = std::equal(PrendaDataRef.PrendaProperties.begin(), PrendaDataRef.PrendaProperties.end(), CurrentPrendaData.PrendaProperties.begin());
	}
	return result;
}

string Store::GetName() {
	return Name;
}

string Store::GetAddress() {
	return Address;
}

Vendedor* Store::GetCurrentVendedor() {
	return VendedorPtr;
}
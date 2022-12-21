#include<iostream>
#include "Vendedor.h"
#include "History.h"
#include "Store.h"

using namespace std;

Store::Store() {
	HistoryUP = std::make_unique<History>();
	HistoryPtr = HistoryUP.get();
}

Store::~Store() {
	cout << "Store Destructor" << endl;
}

SPrendaData* Store::FindPrenda(IPrenda* Prenda) {
	for (SPrendaData& PrendaData : Prendas) {
		if (CheckEquality(PrendaData, Prenda)) {
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

bool Store::CheckEquality(SPrendaData& PrendaDataRef, IPrenda* PrendaPtr) {
	SPrendaData& PrendaData = PrendaPtr->GetPrendaData();
	bool result;
	if (PrendaDataRef.PrendaProperties.size() >= PrendaData.PrendaProperties.size()) {
		result = std::equal(PrendaData.PrendaProperties.begin(), PrendaData.PrendaProperties.end(), PrendaDataRef.PrendaProperties.begin());
	}
	else {
		result = std::equal(PrendaDataRef.PrendaProperties.begin(), PrendaDataRef.PrendaProperties.end(), PrendaData.PrendaProperties.begin());
	}
	return result;
}

vector<SHistoryData>& Store::GetHistory() {
	return HistoryPtr->GetHistory();
}

SHistoryData& Store::AddToHistory(IPrenda* Prenda, string Date, string VendedorID) {
	SHistoryData& LastHistory = HistoryPtr->AddToHistory(Date, VendedorID, Prenda->GetPropertiesAsString(), Prenda->GetBasePrice(), Prenda->GetPrendaData().Count, Prenda->GetFinalPrice());
	return LastHistory;
}
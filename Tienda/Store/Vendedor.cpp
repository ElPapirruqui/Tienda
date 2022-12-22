#include<iostream>
#include "../Structs/SHistoryData.h"
#include "History.h"
#include "Vendedor.h" 

using namespace std;

Vendedor::Vendedor() {
	HistoryUP = std::make_unique<History>();
	HistoryPtr = HistoryUP.get();
}

Vendedor::~Vendedor() {
	cout << "Vendedor Destructor" << endl;
}

string Vendedor::GetID() {
	return ID;
}

string Vendedor::GetFullName() {
	return FullName;
}

vector<SHistoryData>& Vendedor::GetHistory() {
	return HistoryPtr->GetHistory();
}

SHistoryData& Vendedor::AddToHistory(string Date, string PrendaProperties, int UnitPrice, int Quantity, float FinalPrice) {
	SHistoryData& LastHistory = HistoryPtr->AddToHistory(Date, ID, PrendaProperties, UnitPrice, Quantity, FinalPrice);
	return LastHistory;
}
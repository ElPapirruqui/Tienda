#include<iostream>
#include "History.h" 

using namespace std;

History::History() {
}

History::~History() {
	cout << "History Destructor" << endl;
}

vector<SHistoryData>& History::GetHistoryData() {
	return HistoryData;
}

SHistoryData& History::AddToHistory(string Date, string VendorID, string PrendaProperties, int UnitPrice, int Quantity, float FinalPrice) {
	SHistoryData NewHistoryData;
	NewHistoryData.ID = to_string(ID);
	NewHistoryData.Date = Date;
	NewHistoryData.VendorID = VendorID;
	NewHistoryData.PrendaProperties = PrendaProperties;
	NewHistoryData.UnitPrice = UnitPrice;
	NewHistoryData.Quantity = Quantity;
	NewHistoryData.FinalPrice = FinalPrice;
	HistoryData.push_back(NewHistoryData);
	ID++;
	return HistoryData.at(HistoryData.size()-1);
}
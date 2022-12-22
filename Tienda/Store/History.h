#pragma once
#include "../Structs/SHistoryData.h"
#include<vector>
#include<string>

using namespace std;

class IPrenda;

class History {
public:
	History();
	~History();
    vector<SHistoryData>& GetHistory();
    SHistoryData& AddToHistory(string Date, string VendorID, string PrendaProperties, int UnitPrice, int Quantity, float FinalPrice);
private:
    int ID = 0;
    vector<SHistoryData> HistoryData;
};
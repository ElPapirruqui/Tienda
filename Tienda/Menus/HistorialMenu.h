#pragma once
#include "IMenu.h"
#include "../Store/SHistoryData.h"
#include<vector>

using namespace std;

class HistorialMenu : public IMenu {
public:
	int ID = 3;
	HistorialMenu(View* NewAppView);
	~HistorialMenu();
	void ShowMenuBody();
	void ProcessInputAction();
	void SetHistoryData(SHistoryData& NewHistoryData);
	void SetHistoryData(vector<SHistoryData>& NewHistoryData);
private:
	void ShowHistoryItems(SHistoryData* HistoryItem);
	SHistoryData* HistoryData;
	vector<SHistoryData>* HistoryDataVector;
};
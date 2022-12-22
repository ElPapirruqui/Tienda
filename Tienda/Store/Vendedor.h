#pragma once
#include<string>
#include<vector>

using namespace std;

struct SHistoryData;
class History;

class Vendedor {
public:
	Vendedor();
	~Vendedor();
	string GetID();
	string GetFullName();
	vector<SHistoryData>& GetHistory();
	SHistoryData& AddToHistory(string Date, string PrendaProperties, int UnitPrice, int Quantity, float FinalPrice);
private:
	unique_ptr<History> HistoryUP;
	History* HistoryPtr;
	string ID = "001";
	string FullName = "Juan Domingo Quark";
};
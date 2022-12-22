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
	History* GetHistory();
private:
	unique_ptr<History> HistoryUP;
	History* HistoryPtr;
	string ID = "001";
	string FullName = "Juan Domingo Quark";
};
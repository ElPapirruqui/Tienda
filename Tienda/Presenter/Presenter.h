#pragma once
#include<vector>
#include "../Prendas/SPrendaChoice.h"
#include "../Prendas/EPrendaType.h"

using namespace std;

class Vendedor;
class Store;
class PrendaFactory;
class View;

class Presenter {
public:
	Presenter();
	Presenter(View* NewView);
	~Presenter();
	vector<SPrendaChoice> GetCotizacionSteps();
	SPrendaChoice GetNextStep(int NextStep);
	void SetNewPrenda(EPrendaType NewPrendaType);
	void AddPropertyToCurrentPrenda(EPrendaType PrendaProperty);
	void SetPriceToCurrentPrenda(int NewPrice);
	bool SetQuantityToCurrentPrenda(int NewQuantity);
	void NewHistoryRecord();
	void ShowHistoryRecords();
private:
	string CurrentDateTime();
	unique_ptr<Store> StoreUP;
	Store* StorePtr;
	unique_ptr<PrendaFactory> PrendaFactoryUP;
	PrendaFactory* PrendaFactoryPtr;
	unique_ptr<Vendedor> VendedorUP;
	Vendedor* VendedorPtr;
	View* ViewPtr;
};
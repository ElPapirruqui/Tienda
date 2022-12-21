#pragma once
#include<vector>
#include "../Prendas/SPrendaChoice.h"
#include "../Prendas/EPrendaType.h"

class Vendedor;
class Store;
class PrendaFactory;
class View;

class Presenter {
public:
	Presenter();
	Presenter(View* NewView);
	~Presenter();
	std::vector<SPrendaChoice> GetCotizacionSteps();
	SPrendaChoice GetNextStep(int NextStep);
	void SetNewPrenda(EPrendaType NewPrendaType);
	void AddPropertyToCurrentPrenda(EPrendaType PrendaProperty);
	void SetPriceToCurrentPrenda(int NewPrice);
	bool SetQuantityToCurrentPrenda(int NewQuantity);
	void NewHistoryRecord();
	void ShowHistoryRecords();
private: 
	std::unique_ptr<Store> StoreUP;
	Store* StorePtr;
	std::unique_ptr<PrendaFactory> PrendaFactoryUP;
	PrendaFactory* PrendaFactoryPtr;
	unique_ptr<Vendedor> VendedorUP;
	Vendedor* VendedorPtr;
	View* ViewPtr;
};
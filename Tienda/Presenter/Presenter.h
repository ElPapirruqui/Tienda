#pragma once
#include<vector>
#include "../Prendas/SPrendaChoice.h"
#include "../Prendas/EPrendaType.h"

class Store;
class PrendaFactory;

class Presenter {
public:
	Presenter();
	~Presenter();
	std::vector<SPrendaChoice> GetCotizacionSteps();
	void SetNewPrenda(EPrendaType NewPrendaType);
	void AddPropertyToCurrentPrenda(EPrendaType PrendaProperty);
	void SetPriceToCurrentPrenda(int NewPrice);
	void NewHistoryRecord();
private: 
	std::unique_ptr<Store> StoreUP;
	Store* StorePtr;
	std::unique_ptr<PrendaFactory> PrendaFactoryUP;
	PrendaFactory* PrendaFactoryPtr;
};
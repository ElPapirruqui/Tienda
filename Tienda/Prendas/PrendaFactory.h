#pragma once
#include "../Prendas/SPrendaChoice.h"
#include "../Prendas/EPrendaType.h"
#include<vector>
#include<memory>

using namespace std;

class IPrenda;

class PrendaFactory {
public:
	PrendaFactory();
	virtual ~PrendaFactory();
	SPrendaChoice& GetCotizacionStep(EPrendaType PrendaType, int NextStep);
	IPrenda* GetCurrentPrenda();
	void SetCurrentPrenda(EPrendaType PrendaType);
	void AddPrendaProperty(EPrendaType PrendaProperty);
	void SetNewPrice(int NewPrice);
	void SetNewQuantity(int NewQuantity);
	void UpdateStepQuantity(SPrendaChoice* CurrentStep, int Quantity);
private:
	unique_ptr<IPrenda> PrendaUP;
	IPrenda* PrendaPtr;
};
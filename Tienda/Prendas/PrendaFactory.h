#pragma once
#include "../Prendas/SPrendaChoice.h"
#include "../Prendas/EPrendaType.h"
#include<vector>

class IPrenda;

class PrendaFactory {
public:
	PrendaFactory();
	virtual ~PrendaFactory();
	std::vector<SPrendaChoice> GetCotizacionSteps(EPrendaType PrendaType);
	SPrendaChoice GetCotizacionStep(EPrendaType PrendaType, int NextStep);
	IPrenda* GetCurrentPrenda();
	void SetCurrentPrenda(EPrendaType PrendaType);
	void AddPrendaProperty(EPrendaType PrendaProperty);
	void SetNewPrice(int NewPrice);
	void SetNewQuantity(int NewQuantity);
	void UpdateStepQuantity(SPrendaChoice& CurrentStep, int Quantity);
private:
	std::unique_ptr<IPrenda> PrendaUP;
	IPrenda* PrendaPtr;
};
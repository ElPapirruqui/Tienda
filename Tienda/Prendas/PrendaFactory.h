#pragma once
#include "../Prendas/SPrendaChoice.h"
#include "../Prendas/EPrendaType.h"
#include<vector>

class IPrenda;

class PrendaFactory {
public:
	PrendaFactory();
	~PrendaFactory();
	std::vector<SPrendaChoice> GetCotizacionSteps(EPrendaType PrendaType);
	IPrenda* GetCurrentPrenda();
	void SetCurrentPrenda(EPrendaType PrendaType);
	void AddPrendaProperty(EPrendaType PrendaProperty);
	void SetNewPrice(int NewPrice);
private:
	std::unique_ptr<IPrenda> PrendaUP;
	IPrenda* PrendaPtr;
};
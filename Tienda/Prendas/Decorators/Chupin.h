#pragma once
#include "PrendaDecorator.h"

class Chupin : public PrendaDecorator {
public:
	Chupin(IPrenda* NewPrenda);
	~Chupin();
	float UpdatePrice(float CurrentPrice);
};
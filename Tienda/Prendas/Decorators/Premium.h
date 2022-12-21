#pragma once
#include "PrendaDecorator.h"

class Premium : public PrendaDecorator {
public:
	Premium(IPrenda* NewPrenda);
	~Premium();
	float UpdatePrice(float CurrentPrice);
};
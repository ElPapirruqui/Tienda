#pragma once
#include "PrendaDecorator.h"

class CuelloMao : public PrendaDecorator {
public:
	CuelloMao(IPrenda* NewPrenda);
	~CuelloMao();
	float UpdatePrice(float CurrentPrice);
};
#pragma once
#include "IPrenda.h"

class Camisa : public IPrenda {
public:
	Camisa();
	~Camisa();
	EPrendaType GetType();
	float GetFinalPrice();
};
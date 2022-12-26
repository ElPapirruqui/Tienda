#pragma once
#include "IPrenda.h"

class Pantalon : public IPrenda {
public:
	Pantalon();
	~Pantalon();
	EPrendaType GetType();
	float GetFinalPrice();
};
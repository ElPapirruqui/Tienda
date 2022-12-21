#pragma once
#include "PrendaDecorator.h"

class MangaCorta : public PrendaDecorator {
public:
	MangaCorta(IPrenda* NewPrenda);
	~MangaCorta();
	float UpdatePrice(float CurrentPrice);
};
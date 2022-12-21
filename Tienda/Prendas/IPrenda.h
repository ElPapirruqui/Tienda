#pragma once
#include<string>
#include<vector>
#include "EPrendaType.h"

class PrendaDecorator;

struct SPrendaData {
	EPrendaType PrendaType;
	std::vector<EPrendaType> PrendaProperties;
	int Count = 0;
};

class IPrenda {
public:
	IPrenda();
	virtual ~IPrenda();
	virtual EPrendaType GetType();
	virtual float GetFinalPrice() = 0;
	void AddProperty(EPrendaType PrendaProperty);
	void SetPrice(int NewPrice);
	std::vector<std::unique_ptr<PrendaDecorator>> Decorators;
protected:
	float BasePrice = 0;
	SPrendaData PrendaData;
};
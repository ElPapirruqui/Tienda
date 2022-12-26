#pragma once

class IPrenda;

class PrendaDecorator{
public:
	PrendaDecorator(IPrenda* NewPrenda);
	virtual ~PrendaDecorator();
	virtual float UpdatePrice(float CurrentPrice) = 0;
protected:
	IPrenda* ParentPrenda;
};
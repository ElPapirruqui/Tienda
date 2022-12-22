#pragma once
#include "../Structs/SPrendaData.h"
#include<string>
#include<vector>

using namespace std;

class PrendaDecorator;
enum class EPrendaType;
struct SPrendaChoice;
struct SPrendaData;

class IPrenda {
public:
	IPrenda();
	virtual ~IPrenda();
	virtual EPrendaType GetType();
	int GetBasePrice();
	virtual float GetFinalPrice() = 0;
	void AddProperty(EPrendaType PrendaProperty);
	void SetPrice(int NewPrice);
	void SetQuantity(int NewQuantity);
	string GetPropertiesAsString();
	vector<SPrendaChoice> PrendaChoices;
	vector<unique_ptr<PrendaDecorator>> Decorators;
	SPrendaData& GetPrendaData();
protected:
	float BasePrice = 0;
	SPrendaData PrendaData;
	void AddFinalChoices();
};
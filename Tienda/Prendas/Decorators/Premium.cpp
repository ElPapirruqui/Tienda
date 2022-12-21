#include<iostream>
#include "Premium.h"

using namespace std;

Premium::Premium(IPrenda* NewPrenda) :PrendaDecorator(NewPrenda) {}

Premium::~Premium() {
	cout << "Premium Destructor" << endl;
}

float Premium::UpdatePrice(float CurrentPrice) {
	return CurrentPrice * 1.3;
}
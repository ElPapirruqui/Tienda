#include<iostream>
#include "Chupin.h"

using namespace std;

Chupin::Chupin(IPrenda* NewPrenda) :PrendaDecorator(NewPrenda) {}

Chupin::~Chupin() {
	cout << "Chupin Destructor" << endl;
}

float Chupin::UpdatePrice(float CurrentPrice) {
	return CurrentPrice * 0.88;
}
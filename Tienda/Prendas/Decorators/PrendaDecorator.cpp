#include<iostream>
#include "../IPrenda.h"
#include "PrendaDecorator.h"

using namespace std;

PrendaDecorator::PrendaDecorator(IPrenda* NewPrenda):ParentPrenda(NewPrenda){}

PrendaDecorator::~PrendaDecorator() {
	cout << "PrendaDecorator Destructor" << endl;
}
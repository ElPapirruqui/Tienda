#include<iostream>
#include "CuelloMao.h"

using namespace std;

CuelloMao::CuelloMao(IPrenda* NewPrenda) :PrendaDecorator(NewPrenda) {}

CuelloMao::~CuelloMao() {
	cout << "CuelloMao Destructor" << endl;
}

float CuelloMao::UpdatePrice(float CurrentPrice) {
	return CurrentPrice * 1.03;
}
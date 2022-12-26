#include<iostream>
#include "MangaCorta.h"

using namespace std;

MangaCorta::MangaCorta(IPrenda* NewPrenda) :PrendaDecorator(NewPrenda) {}

MangaCorta::~MangaCorta() {
	cout << "MangaCorta Destructor" << endl;
}

float MangaCorta::UpdatePrice(float CurrentPrice) {
	return CurrentPrice * 0.9;
}
#include<iostream>
#include "Vendedor.h" 

using namespace std;

Vendedor::Vendedor() {
}

Vendedor::~Vendedor() {
	cout << "Vendedor Destructor" << endl;
}

string Vendedor::GetID() {
	return ID;
}

string Vendedor::GetFullName() {
	return FullName;
}

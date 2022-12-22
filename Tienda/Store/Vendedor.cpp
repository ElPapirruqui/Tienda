#include<iostream>
#include "../Structs/SHistoryData.h"
#include "History.h"
#include "Vendedor.h" 

using namespace std;

Vendedor::Vendedor() {
	HistoryUP = std::make_unique<History>();
	HistoryPtr = HistoryUP.get();
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

History* Vendedor::GetHistory() {
	return HistoryPtr;
}
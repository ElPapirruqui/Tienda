#pragma once
#include<string>

using namespace std;

class Vendedor {
public:
	Vendedor();
	~Vendedor();
	string GetID();
private:
	string ID = "001";
};
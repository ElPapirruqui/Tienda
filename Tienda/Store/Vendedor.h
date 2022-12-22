#pragma once
#include<string>

using namespace std;

class Vendedor {
public:
	Vendedor();
	~Vendedor();
	string GetID();
	string GetFullName();
private:
	string ID = "001";
	string FullName = "Juan Domingo Quark";
};
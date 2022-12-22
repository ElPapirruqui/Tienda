#pragma once
#include "../Structs/SPrendaChoice.h"
#include "../Enum/EPrendaType.h"
#include "../Structs/SPrendaData.h"
#include<vector>
#include<string>

using namespace std;

class History;
class Vendedor;
class Prenda;

class Store {
public:
	Store();
	~Store();
	SPrendaData* FindPrenda(SPrendaData& CurrentPrendaData);
	bool CheckStock(int NewQuantity);
	void UpdateStock(int Quantity);
	string GetName();
	string GetAddress();
	Vendedor* GetCurrentVendedor();
private:
	string Name = "ROPA QUARK";
	string Address = "Av. Gdor. Quark 3300";
	bool CheckEquality(SPrendaData& PrendaDataRef, SPrendaData& CurrentPrendaData);
	vector<SPrendaData> Prendas = {
		{EPrendaType::Camisa, {EPrendaType::Camisa, EPrendaType::MangaCorta, EPrendaType::CuelloMao, EPrendaType::Standard}, 100},
		{EPrendaType::Camisa, {EPrendaType::Camisa, EPrendaType::MangaCorta, EPrendaType::CuelloMao, EPrendaType::Premium}, 100},
		{EPrendaType::Camisa, {EPrendaType::Camisa, EPrendaType::MangaCorta, EPrendaType::CuelloComun, EPrendaType::Standard}, 150},
		{EPrendaType::Camisa, {EPrendaType::Camisa, EPrendaType::MangaCorta, EPrendaType::CuelloComun, EPrendaType::Premium}, 150},
		{EPrendaType::Camisa, {EPrendaType::Camisa, EPrendaType::MangaLarga, EPrendaType::CuelloMao, EPrendaType::Standard}, 75},
		{EPrendaType::Camisa, {EPrendaType::Camisa, EPrendaType::MangaLarga, EPrendaType::CuelloMao, EPrendaType::Premium}, 75},
		{EPrendaType::Camisa, {EPrendaType::Camisa, EPrendaType::MangaLarga, EPrendaType::CuelloComun, EPrendaType::Standard}, 175},
		{EPrendaType::Camisa, {EPrendaType::Camisa, EPrendaType::MangaLarga, EPrendaType::CuelloComun, EPrendaType::Premium}, 175},
		{EPrendaType::Pantalon, {EPrendaType::Pantalon, EPrendaType::Chupin, EPrendaType::Standard}, 750},
		{EPrendaType::Pantalon, {EPrendaType::Pantalon, EPrendaType::Chupin, EPrendaType::Premium}, 750},
		{EPrendaType::Pantalon, {EPrendaType::Pantalon, EPrendaType::Clasico, EPrendaType::Standard}, 250},
		{EPrendaType::Pantalon, {EPrendaType::Pantalon, EPrendaType::Clasico, EPrendaType::Premium}, 250},
	};
	SPrendaData* CurrentPrenda;
	unique_ptr<Vendedor> VendedorUP;
	Vendedor* VendedorPtr;
};
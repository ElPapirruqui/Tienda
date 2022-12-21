#pragma once
#include "../Prendas/SPrendaChoice.h"
#include "../Prendas/EPrendaType.h"
#include "../Prendas/IPrenda.h"
#include<vector>

class Store {
public:
	Store();
	~Store();
private:
	std::vector<SPrendaData> Prendas = {
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
};
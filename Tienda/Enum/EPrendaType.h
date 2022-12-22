#pragma once
#include<map>
#include<string>

using namespace std;

enum class EPrendaType { Camisa, Pantalon, MangaCorta, MangaLarga, CuelloMao, CuelloComun, Chupin, Clasico, Standard, Premium };

class PrendaType {
public:
	typedef map<EPrendaType, string> PrendaMap;
	static PrendaMap TypeNames;
};
#pragma once
#include <vector>

enum class EPrendaType;

struct SPrendaData {
	EPrendaType PrendaType;
	std::vector<EPrendaType> PrendaProperties;
	int Count = 0;
};

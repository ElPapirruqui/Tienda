#pragma once
#include "EPrendaType.h"
#include<string>
#include<vector>

using namespace std;

enum class EStepType { Choice, Price, Quantity };

struct SPrendaChoice {
	string Message = "";
	vector<EPrendaType> Choices;
	EStepType StepType = EStepType::Choice;
	string Info;
	int Iteration = 0;
};
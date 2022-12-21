#pragma once
#include "EPrendaType.h"
#include<string>
#include<vector>

enum class EStepType { Choice, Price, Quantity };

struct SPrendaChoice {
	std::string Message;
	std::vector<EPrendaType> Choices;
	EStepType StepType = EStepType::Choice;
	std::string Info = "";
};
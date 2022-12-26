#pragma once
#include<string>
#include<vector>

using namespace std;

enum class EStepType;
enum class EPrendaType;

struct SPrendaChoice {
	string Message = "";
	string Error = "";
	vector<EPrendaType> Choices;
	EStepType StepType;
	string Info;
	int Iteration = 0;
};
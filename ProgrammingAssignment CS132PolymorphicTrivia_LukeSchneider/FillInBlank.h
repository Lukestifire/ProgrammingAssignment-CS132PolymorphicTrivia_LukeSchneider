// ProgrammingAssignment CS132PolymorphicTrivia
// LukeSchneider
// CS132 - 6/6/2021

#pragma once
#include "TriviaQuestion.h"
#include <string>
using namespace std;

class FillInBlank : public TriviaQuestion
{
private:
	string answer;
public:
	FillInBlank(string);
	void printMe();

	// Answer Parser
	string answerParser(string);
	int askQuestion();
};


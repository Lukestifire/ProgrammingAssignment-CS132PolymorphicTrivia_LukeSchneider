// ProgrammingAssignment CS132PolymorphicTrivia
// LukeSchneider
// CS132 - 6/6/2021

#pragma once
#include "TriviaQuestion.h"
class NumericQuestion : public TriviaQuestion
{
private:
	string answer; 
public:
	NumericQuestion(string);
	void printMe();

	// Answer Parser
	string answerParser(string);
	int askQuestion();
};



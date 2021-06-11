// ProgrammingAssignment CS132PolymorphicTrivia
// LukeSchneider
// CS132 - 6/6/2021

#pragma once
#include "TriviaQuestion.h"
class TrueOrFalse :
    public TriviaQuestion
{
private:
	string answer;
public:
	TrueOrFalse(string);
	void printMe();

	// Answer Parser
	string answerParser(string);
	int askQuestion();
};


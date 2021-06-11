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


#pragma once
#include "TriviaQuestion.h"
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


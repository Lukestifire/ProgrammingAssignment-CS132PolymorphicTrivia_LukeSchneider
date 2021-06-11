#pragma once
// ProgrammingAssignment CS132PolymorphicTrivia
// LukeSchneider
// CS132 - 6/6/2021

#include "TriviaQuestion.h"
#include <vector>
#include <algorithm>
#include <numeric>
class MultipleChoice : public TriviaQuestion
{ 
private:
	vector<string> possibleAnswers;
	string correctAnswer;
public:
	MultipleChoice(string);
	void printMe();
	
	// Answer Parser
	vector<string> answerParser(string);
	int askQuestion();
};


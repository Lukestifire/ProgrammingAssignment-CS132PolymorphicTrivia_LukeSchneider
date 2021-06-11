// ProgrammingAssignment CS132PolymorphicTrivia
// LukeSchneider
// CS132 - 6/6/2021

#pragma once
#include <iomanip>
#include <string>
using namespace std;

class TriviaQuestion
{
protected:
	int points;
	string question;
public:
	TriviaQuestion();
	~TriviaQuestion(); 
	int virtual getMax();
	int virtual askQuestion() = 0;
	void virtual printMe();

	// Parsers
	int pointsParser(string);
	string questionParser(string);
};







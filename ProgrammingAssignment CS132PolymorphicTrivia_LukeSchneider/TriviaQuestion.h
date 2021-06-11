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
	int virtual getMax();
	int virtual askQuestion() = 0;
	void virtual printMe();


	// Parsers
	int pointsParser(string);
	string questionParser(string);
	




};







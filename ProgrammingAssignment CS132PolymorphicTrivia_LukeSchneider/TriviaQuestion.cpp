// ProgrammingAssignment CS132PolymorphicTrivia
// LukeSchneider
// CS132 - 6/6/2021

#include "TriviaQuestion.h"
#include "ExtraFunctions.h"

#include <iostream>
#include <iomanip>

using namespace std;

// basic construcot/destructor
TriviaQuestion::TriviaQuestion() { points = 0, question = ""; }
TriviaQuestion::~TriviaQuestion() {}

// gets points for object
int TriviaQuestion::getMax()
{
	return points;
}

// prints question - for troubleshooting
void TriviaQuestion::printMe()
{
	cout << question;
}

// parses a question objects points from data
int TriviaQuestion::pointsParser(string x)
{
	x.erase(0, 4);
	points = stoi(x.substr(0, 2));
	return points;
}

// parses a question objects question from data
string TriviaQuestion::questionParser(string x)
{
	int pos;
	x.erase(0, 6);
	pos = x.find(":");
	x = x.substr(0, pos);
	x = rtrim(x);
	return x;
}




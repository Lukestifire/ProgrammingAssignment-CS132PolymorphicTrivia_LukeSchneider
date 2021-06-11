#include "TriviaQuestion.h"
#include "ExtraFunctions.h"

#include <iostream>
#include <iomanip>

using namespace std;

TriviaQuestion::TriviaQuestion() {}

int TriviaQuestion::getMax()
{
	return points;
}

void TriviaQuestion::printMe()
{
	cout << question;
}

int TriviaQuestion::pointsParser(string x)
{
	x.erase(0, 4);
	points = stoi(x.substr(0, 2));
	return points;
}

string TriviaQuestion::questionParser(string x)
{
	int pos;
	x.erase(0, 6);
	pos = x.find(":");
	x = x.substr(0, pos);
	x = rtrim(x);
	return x;
}




#include "TrueOrFalse.h"
#include <iostream>
#include <iomanip>
#include <string>

#include "ExtraFunctions.h"

using namespace std;

TrueOrFalse::TrueOrFalse(string x)
{
	question = questionParser(x);
	points = pointsParser(x);
	answer = answerParser(x);
}

string TrueOrFalse::answerParser(string x)
{
	int pos = 0;
	pos = x.find(":");
	x = x.substr(pos + 1, string::npos);
	return ltrim(x);
}

int TrueOrFalse::askQuestion()
{
	string userAnswer = "";
	cout << "This is a true or false question worth " << getMax() << " points, please type in your answer as a value 'True' or 'False'" << endl << endl;
	cout << "Question : " << question << endl << endl;
	cout << "-->";
	cin.clear();
	cin >> userAnswer;

	if (upperCase(trim(userAnswer)) == upperCase(answer))
	{
		cout << "CORRECT" << endl << endl;
		return getMax();
	}
	else
	{
		cout << "I am sorry, that is incorrect, thecorrect answer was " << answer << endl << endl;
		return 0;
	}

}


void TrueOrFalse::printMe()
{
	cout << question << endl;
}



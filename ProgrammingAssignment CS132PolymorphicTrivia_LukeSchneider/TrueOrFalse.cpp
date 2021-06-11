// ProgrammingAssignment CS132PolymorphicTrivia
// LukeSchneider
// CS132 - 6/6/2021

#include "TrueOrFalse.h"
#include <iostream>
#include <iomanip>
#include <string>
#include "ExtraFunctions.h"

using namespace std;

// Constructs a True or False question object
TrueOrFalse::TrueOrFalse(string x)
{
	question = questionParser(x);
	points = pointsParser(x);
	answer = answerParser(x);
}

// Parses the correct answer for true or false question - 
string TrueOrFalse::answerParser(string x)
{
	int pos = 0;
	pos = x.find(":");
	x = x.substr(pos + 1, string::npos);
	return ltrim(x);
}

// Asks a True Or false style question. Answer in form of a string/word 'True' or 'False'
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

// prints question - for troubleshooting
void TrueOrFalse::printMe()
{
	cout << question << endl;
}



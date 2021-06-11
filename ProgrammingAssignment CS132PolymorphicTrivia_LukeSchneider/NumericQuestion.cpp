
// ProgrammingAssignment CS132PolymorphicTrivia
// LukeSchneider
// CS132 - 6/6/2021

#include "NumericQuestion.h"
#include <iostream>
#include <iomanip>
#include <string>

#include "ExtraFunctions.h"

using namespace std;

// Constructs a neumeric question object
NumericQuestion::NumericQuestion(string x)
{
	question = questionParser(x);
	points = pointsParser(x);
	answer = answerParser(x);
}

// Parses the correct answer from data - data always has correct answer in first position
string NumericQuestion::answerParser(string x)
{
	int pos = 0;
	pos = x.find(":");
	x = x.substr(pos + 1, string::npos);
	return ltrim(x);
}

// Asks a numeric style question. 
int NumericQuestion::askQuestion()
{
	string userAnswer = "";
	cout << "This is a numeric question worth " << getMax() << " points, please type in your answer as a value" << endl << endl;
	cout << "Question : " << question << endl << endl;
	cout << "-->";
	cin.clear();
	cin >> userAnswer;

	if (trim(userAnswer) == answer)
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

// prints the numeric questions basic values
void NumericQuestion::printMe()
{
	cout << question << endl;
	cout << points << endl;
	cout << answer << endl;
}




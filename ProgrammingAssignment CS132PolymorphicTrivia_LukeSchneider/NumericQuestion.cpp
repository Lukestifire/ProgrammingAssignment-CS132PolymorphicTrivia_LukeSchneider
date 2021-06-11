#include "NumericQuestion.h"
#include <iostream>
#include <iomanip>
#include <string>

#include "ExtraFunctions.h"

using namespace std;

NumericQuestion::NumericQuestion(string x)
{
	question = questionParser(x);
	points = pointsParser(x);
	answer = answerParser(x);
}

string NumericQuestion::answerParser(string x)
{
	int pos = 0;
	pos = x.find(":");
	x = x.substr(pos + 1, string::npos);
	return ltrim(x);
}

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


void NumericQuestion::printMe()
{
	cout << question << endl;
	cout << points << endl;
	cout << answer << endl;
}




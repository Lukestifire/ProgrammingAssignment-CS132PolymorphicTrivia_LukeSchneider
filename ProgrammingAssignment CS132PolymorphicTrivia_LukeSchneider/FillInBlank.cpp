// ProgrammingAssignment CS132PolymorphicTrivia
// LukeSchneider
// CS132 - 6/6/2021



#include "FillInBlank.h"
#include <iostream>
#include <iomanip>
#include <string>

#include "ExtraFunctions.h"

using namespace std; 

// Constructs a Fill in the Blan question object
FillInBlank::FillInBlank(string x)
{
	question = questionParser(x);
	points = pointsParser(x);
	answer = answerParser(x);
}
// Parses the correct answer for fill in the blank question 
string FillInBlank::answerParser(string x)
{
	int pos = 0;
	pos = x.find(":");
	x = x.substr(pos + 1, string::npos);
	return ltrim(x);
}
// Asks a fill in the blank style question. Answer in form of a string/word - returns 'points if' correct or 0 if wrong
int FillInBlank::askQuestion()
{
	string userAnswer = "";
	cout << "This is a fill in the blank question worth " << getMax() << " points, please type in your answer as a value" << endl << endl;
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
void FillInBlank::printMe()
{
	cout << question << endl; 
}






// ProgrammingAssignment CS132PolymorphicTrivia
// LukeSchneider
// CS132 - 6/6/2021

#include "MultipleChoice.h"
#include "ExtraFunctions.h"
#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <algorithm>
#include <numeric>
#include <map>

using namespace std;

// Constructs Multiple choice object - can be any number of answers
MultipleChoice::MultipleChoice(string x)
{
	question = questionParser(x);
	points = pointsParser(x);
	possibleAnswers = answerParser(x);
	correctAnswer = possibleAnswers.at(0);
}

// Generates vector of possible answers from data
vector<string> MultipleChoice::answerParser(string x)
{
	vector<string> tmp;
	int pos = 0;

	while (x.find(":") != string::npos)
	{
		pos = x.find(":");
		x.erase(0, pos + 1);
		pos = x.find(":");
		tmp.push_back(x.substr(0, pos));
	}
	return tmp;
}

// Asks MC3 question then determines if the answer was correct
int MultipleChoice::askQuestion()
{
	//Variables
	int userAnswer = 0;
	map<int, string> answers;

	// Shuffle the answers
	default_random_engine rd(chrono::system_clock::now().time_since_epoch().count());
	shuffle(possibleAnswers.begin(), possibleAnswers.end(), rd);
	
	// Oupup questions
	cout << "This is a multiple choice question worth " << getMax() << " points, please type in your answer as a value" << endl << endl;
	cout << "Question : " << question << endl;																
	
	// Place shuffled answers into map with corresponding position
	for (int i = 0; i < possibleAnswers.size(); i++)
	{
		answers[i+1] = possibleAnswers.at(i);
	}

	// Map iterator
	map<int, string>::iterator ptr = answers.begin();

	// Use map to ouput possible answers 
	int count = 0; 
	for (pair<int, string> p : answers)
	{
		int num = p.first;
		string tmpAnswer = p.second;
		tmpAnswer = trim(tmpAnswer);
		cout << num << ": " << tmpAnswer << endl;
	}

	// Recieves user selected answer - determins if input is valid based on number of questions
	cout << "-->";
	cin >> userAnswer;
	while (userAnswer > possibleAnswers.size() || userAnswer < 1)
	{
		cout << "Please select a valid number for an answer  (1-" << possibleAnswers.size() << ")" << endl;
		cout << "-->";
		cin >> userAnswer;
	}

	// checks to see if the answer correct - if correct full points, if not, no points. 
if (answers.at(userAnswer) == correctAnswer)
	{
		cout << "CORRECT" << endl << endl;
		return getMax();
	}
	else
	{
		cout << "I am sorry, that is incorrect, thecorrect answer was " << correctAnswer << endl << endl;
		return 0;
	}		
}

// print function to reveal data in MC problem - troubleshooting only
void MultipleChoice::printMe()
{
	cout << "question is: " << question << endl;
	cout << "points is: " << points << endl;
	cout << "correctAnswer is: " << correctAnswer << endl;
	for (int i = 0; i < possibleAnswers.size(); i++)
	{
		cout << possibleAnswers.at(i) << endl;
	}
}





// ProgrammingAssignment CS132PolymorphicTrivia
// LukeSchneider
// CS 132 - 6/6/2021

#include <iostream>
#include <string> 
#include <algorithm>
#include <numeric>
#include <fstream>
#include <iomanip>
#include <cstdlib>
#include <vector>
#include <chrono>
#include <random>

#include "TriviaQuestion.h"
#include "ExtraFunctions.h"
#include "FillInBlank.h"
#include "MultipleChoice.h"
#include "NumericQuestion.h"
#include "TrueOrFalse.h"


using namespace std;


void printMe(const vector<TriviaQuestion*>& L);


int main()
{
	// variables
	string triviaQuestionsFileName, question;
	ifstream triviaQuestionsFile;
	vector<TriviaQuestion*> TriviaQuestions; 
	TriviaQuestion* tmp;

	int count = 0, count2 = 0, numOfQuestionsRequested = 0;
	double totalPointsEarned = 0, totalPointsPossible = 0, percentCorrect = 0;

	// Get file name from user																												//	CORRECT THIS LINE
	//cout << "Please type in the name of the question bank you would like to open. " << endl << "-->";
	//cin >> triviaQuestionsFileName;																										//	CORRECT THIS LINE


	// Opens/checks that user selected file opened correctly
	triviaQuestionsFile.open("Questions.txt");																								//	CORRECT THIS LINE
	if (!triviaQuestionsFile)
	{
		cout << "file not found";
		exit(-1);
	}

	// read the trivia questions file into the program and create objects based on type of question
	
	while (getline(triviaQuestionsFile, question))
	{
		//if (question.substr(0, 3) == "FIB") { tmp = new FillInBlank(question); TriviaQuestions.push_back(tmp); count2++; }					//	CORRECT THIS LINE
		//if (question.substr(0, 3) == "NUM") { tmp = new NumericQuestion(question); TriviaQuestions.push_back(tmp); count2++; }				//	CORRECT THIS LINE
		if (question.substr(0, 3) == "TOF") { tmp = new TrueOrFalse(question); TriviaQuestions.push_back(tmp); count2++; }						//	CORRECT THIS LINE
		
		//if (question.substr(0, 3) == "MC3") cout << "found MC3" << endl;
		//if (question.substr(0, 3) == "MC4") cout << "found MC4" << endl;
		//if (question.substr(0, 3) == "TOF") cout << "found TOF" << endl;
		//if (question.substr(0, 3) == "NUM") cout << "found NUM" << endl;
		
	}
	// Closes the chosen file
	triviaQuestionsFile.close();


	// shuffle the vector of trivia questions
	default_random_engine rd(chrono::system_clock::now().time_since_epoch().count());
	shuffle(TriviaQuestions.begin(), TriviaQuestions.end(), rd);					


	// Get number of questions to play from user
	cout << "How long would you like the quiz to be?" << endl;
	cin >> numOfQuestionsRequested;
	while (numOfQuestionsRequested > count2 || numOfQuestionsRequested < 1	)
	{
		cout << "There are only " << count2 << " questions total. Please choose at least one question and no more that the total questions." << endl;
		cin >> numOfQuestionsRequested;

	}
	cout << endl;
	
	// Asks the quantity of requested questions from randomized vector of trivia questions. 
	for (int i = 0; i < numOfQuestionsRequested; i++)
	{
		totalPointsEarned += TriviaQuestions.at(i)->askQuestion();
		totalPointsPossible += TriviaQuestions.at(i)->getMax();
	}
	

	percentCorrect = (totalPointsEarned / totalPointsPossible) * 100;
	cout << "Your final Score is " << totalPointsEarned << "/" << totalPointsPossible << " or " << fixed << setprecision(2) << percentCorrect << "%" << endl;

}

void printMe(const vector<TriviaQuestion*>& L)
{
	for (TriviaQuestion* x : L)
	{
		x->printMe();
	}
}
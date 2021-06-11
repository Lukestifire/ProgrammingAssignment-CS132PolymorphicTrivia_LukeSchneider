// ProgrammingAssignment CS132PolymorphicTrivia
// LukeSchneider
// CS132 - 6/6/2021

/*
This program uses a specific data file to create Trivia question obejects. Each question has its own rules
on how the question should be asked/answered and a predetermined point value that is earned and totalized.
Can be any file with correctly formatted data and you can select the number of questions to play from a randomly assorted "deck" of questions.
*/

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

int userQuestionQuantity(int);
void playGame(vector<TriviaQuestion*>, int);


int main()
{
	// variables
	string triviaQuestionsFileName, question;
	ifstream triviaQuestionsFile;
	vector<TriviaQuestion*> TriviaQuestions; 
	TriviaQuestion* tmp;

	int count = 0, count2 = 0, numOfQuestionsRequested = 0;
	double totalPointsEarned = 0, totalPointsPossible = 0, percentCorrect = 0;


	//Get file name from user																												
	cout << "Please type in the name of the question bank you would like to open. ";
	cin >> triviaQuestionsFileName;		
	cout << endl;


	// Opens/checks that user selected file opened correctly
	triviaQuestionsFile.open(triviaQuestionsFileName);
	if (!triviaQuestionsFile)
	{
		cout << "file not found";
		exit(-1);
	}


	// read the trivia questions file into the program and create objects based on type of question
	while (getline(triviaQuestionsFile, question))
	{
		if (question.substr(0, 3) == "FIB") { tmp = new FillInBlank(question); TriviaQuestions.push_back(tmp); count2++; }				
		if (question.substr(0, 3) == "NUM") { tmp = new NumericQuestion(question); TriviaQuestions.push_back(tmp); count2++; }			
		if (question.substr(0, 3) == "TOF") { tmp = new TrueOrFalse(question); TriviaQuestions.push_back(tmp); count2++; }				
		if (question.substr(0, 2) == "MC") { tmp = new MultipleChoice(question); TriviaQuestions.push_back(tmp); count2++; }				
	}


	// Closes the chosen file
	triviaQuestionsFile.close();


	//shuffle the vector of trivia questions - requires '#include <chrono>' & '#include <random>'
	default_random_engine rd(chrono::system_clock::now().time_since_epoch().count());
	shuffle(TriviaQuestions.begin(), TriviaQuestions.end(), rd); 		 			

	
	numOfQuestionsRequested = userQuestionQuantity(count2);
	playGame(TriviaQuestions, numOfQuestionsRequested);

	return 0;
}

// Asks the quantity of requested questions from randomized vector of trivia questions. 
int userQuestionQuantity(int x)
{
	int numOfQuestionsRequested = 0;
	cout << "How long would you like the quiz to be?  ";
	cin >> numOfQuestionsRequested;
	cout << endl;
	while (numOfQuestionsRequested > x || numOfQuestionsRequested < 1)
	{
		cout << "There are only " << x << " questions total. Please choose at least one question and no more that the total questions." << endl;
		cin >> numOfQuestionsRequested;
		cout << endl;
	}
	return numOfQuestionsRequested;
}

void playGame(vector<TriviaQuestion*> T, int x)
{
	double numOfQuestionsRequested = x, totalPointsEarned = 0, totalPointsPossible = 0;
	double percentCorrect;
	
	for (int i = 0; i < numOfQuestionsRequested; i++)
	{
		totalPointsEarned += T.at(i)->askQuestion();
		totalPointsPossible += T.at(i)->getMax();
	}

	// calculates final score
	percentCorrect = (totalPointsEarned / totalPointsPossible) * 100;
	cout << "Your final Score is " << totalPointsEarned << "/" << totalPointsPossible << " or " << fixed << setprecision(2) << percentCorrect << "%" << endl;
}


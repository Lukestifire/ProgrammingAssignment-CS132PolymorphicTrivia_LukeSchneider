#pragma once
#include <iomanip>
#include <string>
using namespace std;



class TriviaQuestion
{
private:
	int points;
	string question;

public:
	TriviaQuestion();
	int virtual getMax();
	int virtual askQuestion() = 0;


};

FillInBlank : public TriviaQuestion


 MultipleChoice3 : public TriviaQuestion


MultipleChoice4 : public TriviaQuestion



TrueOrFalse : public TriviaQuestion



class NumericQuestion : public TriviaQuestion
{


};


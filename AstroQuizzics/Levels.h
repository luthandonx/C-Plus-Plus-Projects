#ifndef LEVELS_H
#define LEVELS_H
#include<fstream>
#include "Question_Operator.h"
#include <iostream>


struct QandA {

    string Q ;
    string A ;
    int point ;
    int index;

    friend ostream& operator << (ostream& os, const QandA& q)
    {
        os << q.Q <<" " <<endl;
        return os ;
    }

    void PrintA()
    {
        cout<<A<<endl;
    }

    bool isCorrect(char ans)
    {
        char a = ans;
        if (putchar(toupper(a)) == A[1])
        {
            return true;
        }
        return false;
    }

    int operator+(const QandA &qanda)
    {
        return (point + qanda.point);
    }

};

using namespace std;

class Levels
{
    public:
        Levels(string l);
        virtual ~Levels();//clear all the vectors
        void loadQuestion(string l);// Create a vector that will load all the question from the text file
        void DisplayQuestion(int index);//Randomly select a question  from the vector
        void RecieveAnswer(char answer , int i); // for which question is the answer for
        void DisplayWrongQsAns() ;// display the questions and answers the user got incorrect
        int GetPoints();
        void AddPoints(int i);
        int GetNumberOfQuestions();

    protected:

    private:
        vector<QandA>Qs;// vector that will hold all the questions
        int points;// hold the number of points user gets
        vector<QandA> WrongQsandAns ; // vector will hold all the Questions the user got wrong
        int numberOfQuestions;
};

#endif // LEVELS_H

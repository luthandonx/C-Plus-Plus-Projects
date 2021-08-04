#ifndef QUESTION_OPERATOR_H_INCLUDED
#define QUESTION_OPERATOR_H_INCLUDED


#include<fstream>
#include<regex>
#include<iterator>
#include <stdio.h>
#include <iostream>
#include<vector>
using namespace std;

class Question
{
private:
    string question;
    string answer;
    string question_type;
    int    score;
    string text;
    vector<string>lines;
    int numlines;

public:
    Question(string level); // input the level to determine which text file to get the question
    virtual ~Question();
    string Getquestion(int num);
    string GetAnswer(int num);
    int GetScore();
    string Format_Question (string str , regex reg);
    int GetNumOfLine();

    string SetQuestion(string Q);
    string SetAnswer(string A);
    void SetScore(string level);
    bool If_Correct(char chr);

};



#endif // QUESTION_OPERATOR_H_INCLUDED

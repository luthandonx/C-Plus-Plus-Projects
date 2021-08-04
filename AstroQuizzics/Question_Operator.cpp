#include <iostream>
#include "Question_Operator.h"
#include<fstream>
#include<regex>
#include<iterator>
#include <stdio.h>
#include "Levels.h"
#include<vector>

using namespace std;

 Question::Question(string level)
{
    lines.clear();
    SetScore(level);
    ifstream file;
    file.open("Level "+level+".txt");
    string line;
    numlines = 0;
    while(getline(file , line))
    {
        if(line.length() > 1)
        {
            lines.push_back(line);
            numlines++;
        }
    }
    file.close();
}
string Question::Getquestion(int num)
{
    int x = num;
    string question = SetQuestion(lines[x]);
    return question;
}
string Question::GetAnswer(int num)// the answer returned needs to be formatted
{
    int x = num;
    answer = SetAnswer(lines[x]);
    return answer;
}
int Question::GetScore()
{
    return score;
}

string Question::SetQuestion(string Q)
{
    regex re ("(.+\\?)");
    string Que = Format_Question(Q , re)+"\n";
    regex re2 ("(\\?(.)+\\|)")  ;
    string Que2 = "\n"+Format_Question(Q , re2);
    string fin;
    for (int i = 2 ; i < Que2.size() - 1 ; i++){fin += Que2[i];};
    Que+= fin;
    return Que;
}

string Question :: Format_Question (string str , regex reg)
{
    string text ;
    smatch match ;
    sregex_iterator currentMatch(str.begin() , str.end() , reg);
    sregex_iterator lastMatch;
    while (currentMatch != lastMatch)
    {
        match = *currentMatch;
        text =  match.str();
        currentMatch++;
    }
    return text;
}

string Question::SetAnswer(string A)
{
    regex re ("(\\|(.+)\\;)") ;
    string Ans = Format_Question(A , re);
    string fin;
    for (int i = 1 ; i < Ans.size() - 1 ; i++){fin += Ans[i];};
    return fin;
}

void Question::SetScore(string level)
{
    if (level =="1"){score = 10;}
    else if (level == "2"){score = 15;}
    else if (level == "3"){score = 25;}
    else if (level == "4"){score = 30;}

}

bool Question::If_Correct(char chr)
{
    if (chr ==answer[0])
    {
        return true;
    }
    else{ return false ;}
}

int Question::GetNumOfLine()
{
    return numlines;
}

Question::~Question()
{
    while(lines.empty()== false){lines.pop_back();}
}

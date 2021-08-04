#include <iostream>
#include<fstream>
#include<regex>
#include<iterator>
#include <stdio.h>
#include "Levels.h"
#include "Player.h"
#include <cstdlib>
#include <ctime>
#include<queue>

template <class t>
void emptyVectors(t &vec)
{
    while(vec.empty()==false)
    {
        vec.pop_back();
    }
}

bool GenerateRandomNumber(int &x ,vector<int> &num , int range ,int i );

using namespace std;
int main()
{
    string name;
    cout <<"WELCOME TO ASTROQUIZZICS"<<endl;

    cout <<"Enter your alias then press enter : ";
    cin>>name;
    cout <<""<<endl;
    cout<<"Welcome : "<<name <<" " <<endl;
    Player player(name);
    int random ;
   vector<int>num = {99,99,99,99,99,99,99,99,99,99,99,99,99};
   char answer;
   vector<Levels>levels;

    //Set the levels 1 2 and 3
    Levels lvl1("1");Levels lvl2("2");Levels lvl3("3");
    queue<Levels> lvl;
    lvl.push(lvl3);
    lvl.push(lvl2);
    lvl.push(lvl1);

    cout <<"Rules of the game:"<<endl;

    cout <<"each level has a certain amount questions you are required to answer all of them"<<endl;

    cout << "if it is multiple choice question only enter x,y or z"<<endl;

    cout << "example : which is the first planet on the solar system?"<<endl;

    cout <<"x) Earth y) Mars z)Mercury v)the Sun"<<endl;
    cout <<"only enter z"<<endl;;
    cout <<"for true or false questions only "<<endl;cout<<"enter f for false or t for true"<<endl;

    cout <<"\n"<<"press any key then ENTER to begin"<<endl;
    string key;
    cin >>key;

    cout <<"you need to get at least 8 question correct to move to the next round"<<endl;


    cout<<"START"<<endl;

    for (int i = 0 ; i <10 ; i++)
    {
        random = rand()%lvl1.GetNumberOfQuestions();

        while( GenerateRandomNumber(random , num , lvl1.GetNumberOfQuestions() , i) != false){
            random = rand()%lvl1.GetNumberOfQuestions();
        };

        cout <<"Question: "<<(i+1)<<") ";

        lvl1.DisplayQuestion(random);

        cin >> answer;

        lvl1.RecieveAnswer(answer , random);
        cout << "\n"<<endl;
        cout <<"Question "<<(i+1)<<"/10"<<endl;
        cout << "\n"<<endl;

    }

    emptyVectors(num);

    cout << "LEVEL 1 complete!! "<<endl;
    int points = lvl1.GetPoints();

    cout << "POINTS WON BY "<<player.GetName()<<": "<<points<<endl;
    player.AddPoints(points);
    cout<<"Press any key then enter to continue : ";
    cin >> key;

    cout<<"You GOT everything correct!!! WOW Well done to you little Einstein "<<endl;

    if (points != 100){
        cout << "Here is some correction for the question you got wrong"<<"\n" <<endl;
        lvl1.DisplayWrongQsAns();
    }
    else
    {
        cout<<"You GOT everything correct!!! WOW Well done to you little Einstein "<<endl;
    }

    if (points >-1 )
    {
             cout<<"\n"<<endl;cout<<"\n"<<endl;

    cout<<"Wow Well DONE!! you made it level 2 "<<endl;
    cout <<"Things are about to get a bit more difficult "<<endl;
    cout <<"This level has 8 Question and you need to get at least 7 correct to continue "<<endl;
    cout<<"If you ready press any key then enter to begin:";cin>>key;

    for (int i = 0 ; i < 9 ; i++)
    {
          while( GenerateRandomNumber(random , num , lvl1.GetNumberOfQuestions() , i) != false){
            random = rand()%lvl1.GetNumberOfQuestions();
        };


        cout <<"Question: "<<(i+1)<<") ";
        lvl2.DisplayQuestion(i);

        cin >> answer ;

        lvl2.RecieveAnswer(answer , i);

        cout << "\n"<<endl;
        cout <<"Question "<<(i+1)<<"/9"<<endl;
        cout << "\n"<<endl;

    }
    emptyVectors(num);
    cout << "LEVEL 2 !!"<<endl;
    int points = lvl2.GetPoints();
    cout << "POINTS WON BY "<<player.GetName()<<": "<<points<<endl;
    player.AddPoints(lvl2.GetPoints());

    cout<<"Press any key then enter to continue : ";
    cin >> key;
    if (lvl2.GetPoints() == 69 )
    {
        cout<<"GAME OVER ANFORTUNATLY!!!  "<<endl;
        cout <<"Total Points Won By "<<player.GetName()<<": "<<player.GetPoints()<<endl;

        cout<<"Press any key then enter to continue and see the corrections for the question you got wrong: ";
        cin >> key;

        lvl2.DisplayWrongQsAns();
    }
    else{

        cout <<"\n"<<endl; cout <<"\n"<<endl;
        cout <<"WELL DONE YOU HAVE MADE IT ROUND 3 "<<endl;

        cout <<"THINGS ARE ABOUT TO GET REALLY TOUGH NOW"<<endl;
        cout <<"YOU NEED TO GET EVERYTHING!! CORRECT TO COMPLETE THE ROUND"<<endl;

        cout<<"Press any key then enter to BEGIN LEVEL 3";
        cin >> key;


         for (int i = 0 ; i < 8 ; i++)
        {
            random = (rand() % lvl1.GetNumberOfQuestions());
              while( GenerateRandomNumber(random , num , lvl1.GetNumberOfQuestions() , i) != false){
            random = rand()%lvl1.GetNumberOfQuestions();
        };

            cout <<"Question: "<<(i+1)<<") ";
            lvl3.DisplayQuestion(random);

            cin >> answer ;

            lvl3.RecieveAnswer(answer , random);

            cout << "\n"<<endl;
            cout <<"Question "<<(i+1)<<"/8"<<endl;
            cout << "\n"<<endl;


        }
        emptyVectors(num);
        cout <<"LEVEL 3 complete that was not so bad right?"<<endl;
        cout << "points won: "<< lvl3.GetPoints()<<endl;
        player.AddPoints(lvl3.GetPoints());
        cout <<"TOTAL POINTS: "<< player.GetPoints()<<endl;
    }

    }

    return 0;
}

//This function is generating a random numbers that are not in the list
// This is too ensure the all Questions are randomly selected only once;
bool GenerateRandomNumber(int &x ,vector<int> &num , int range , int i)
{
    bool found = false ;
   for (int c = 0 ; c < num.size() ; c++)
   {
       if (num[c] == x)
       {
           found = true;
       }
   }
   if (found == false )
   {
       num.push_back(x);
   }
    return found ;
}

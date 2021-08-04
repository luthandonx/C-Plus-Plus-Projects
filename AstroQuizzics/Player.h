#ifndef PLAYER_H
#define PLAYER_H
#include<string>
#include <iostream>

using namespace std;

class Player
{
   private:
       string name;
       int points;
   public:
        Player(string name);
        Player();
        ~Player();
        string GetName();
        int GetPoints();
        void AddPoints(int x);
        void SetName(string n);
};

#endif // PLAYER_H

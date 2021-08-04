#include "Player.h"
#include <iostream>
#include<Levels.h>

using namespace std;

Player::Player(string n){
    name = n;
    points = 0;
}

Player::Player()
{
    points = 0;
}
Player::~Player(){

}
int Player::GetPoints()
{
    return points;
}
void Player::SetName(string n)
{
    name = n ;
}
void Player::AddPoints(int x)
{
    points += x;
};
string Player::GetName()
{
    return name;
}

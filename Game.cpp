// Shahrukh Showkath sxs20032

#include "Game.h"
#include <iostream>
#include <iomanip>
// cpp file of Game class
Game::Game()
{
    name = "";
    score = 0;
    initials = "";
    plays = 0;
}

Game::Game(std::string n, int s, std::string i, int p)
{
    name = n;
    score = s;
    initials = i;
    plays = p;
}

bool Game::operator< (Game g)
{
    if (name < g.name)
        return true;
    return false;
}
bool Game::operator> (Game g)
{
    if (name > g.name)
        return true;
    return false;
}
std::ostream& operator<<(std::ostream& output, const Game g)
{
    float rev;
    rev = g.plays / 4.0;
    output << g.name << ", " << g.score << ", " << g.initials << ", " << g.plays << ", $";
    output << std::fixed << std::setprecision(2) << rev << std::endl;
    return output;
}
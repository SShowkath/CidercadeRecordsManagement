// Shahrukh Showkath sxs20032

#ifndef GAME_H
#define GAME_H
#include <string>
/* Game class with getters, setters, and comparison/output operators */
class Game
{
    private:
        std::string name;
        int score;
        std::string initials;
        int plays;
    public:
    
        Game();
        Game(std::string n, int s, std::string i, int p);
        std::string getName() {return name;};
        int getScore() {return score;};
        std::string getInitials() {return initials;};
        int getPlays() {return plays;};
        
        void setName(std::string n) {name = n;};
        void setScore(int s) {score = s;};
        void setInitials(std::string i) {initials = i;};
        void setPlays(int p) {plays = p;};
        
        bool operator< (Game g);
        bool operator> (Game g);
        friend std::ostream& operator<<(std::ostream& output, Game d);
};
#endif